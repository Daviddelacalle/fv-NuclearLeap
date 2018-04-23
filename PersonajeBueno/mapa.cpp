/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mapa.cpp
 * Author: javi
 * 
 * Created on 17 de abril de 2018, 11:20
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml2.h"
#include "mapa.h"
using namespace tinyxml2;

Mapa* Mapa::pinstance = 0;// Inicializar el puntero
Mapa* Mapa::Instance(){
    if(pinstance == 0) //¿Es la primera llamada?
    {
        pinstance = new Mapa;
    }
    return pinstance;
}
Mapa::Mapa() {
    //DEFINIMOS VARIABLES TAMAÑO
    int _tileWidth, _tileHeight, _numLayers=0, _tsw, _tsh,_numTiles,_numColTiles;
    
    
    //MAPA
    XMLDocument doc;
    doc.LoadFile("tiled/mapa.tmx");
    
    //Tamaño del mapa y de los tiles
    XMLElement* map = doc.FirstChildElement("map");
    
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    
    //Imagen del tileset
    XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    map->FirstChildElement("tileset")->QueryIntAttribute("tilewidth", &_tsw);
    map->FirstChildElement("tileset")->QueryIntAttribute("tileheight", &_tsh);
    map->FirstChildElement("tileset")->QueryIntAttribute("tilecount", &_numTiles);
    map->FirstChildElement("tileset")->QueryIntAttribute("columns", &_numColTiles);
    
    //textura
    if(!tex_plat.loadFromFile("tiled/plataformas.png")){
        std::cerr << "Error cargando la imagen sprites.png";
    }
    
    //fondo 
    XMLElement *img_fondo = map->FirstChildElement("imagelayer")->FirstChildElement("image");
    const char *fondo_cadena = img_fondo->Attribute("source");
    
    char buf[100];
    strcpy(buf, "tiled/");
    strcat(buf, fondo_cadena);
    
    if(!tex_fondo.loadFromFile(buf)){
        std::cerr << "Error cargando la imagen";
        exit(0);
    }
    
    fondo = sf::Sprite(tex_fondo);
    
    //Capas XML
    XMLElement *layer = map->FirstChildElement("layer");
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    
    //std::cout << "Layers: " << _numLayers << "\n";
    //Reservar memoria para el tilemap
    _tilemap = new int**[_numLayers];
    for (int i=0; i<_numLayers; i++){
        _tilemap[i] = new int*[_height];
    }
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]= new int[_width];
        }
    }
    
    
    //Cargando los GIDs de multiples capas
    XMLElement *data[_numLayers];
    layer = map->FirstChildElement("layer");
    
    data[0] = layer->FirstChildElement("data")->FirstChildElement("tile");
    
    for(int i=1; i<_numLayers; i++){
        layer = layer->NextSiblingElement("layer");
        data[i] = layer->FirstChildElement("data")->FirstChildElement("tile");        
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                //Avanzo al siguiente tag
                data[l] = data[l]->NextSiblingElement("tile");
            }
        }
    }
    
    //Reserva de memoria para el tilemapSprite
    
    _tilemapSprite = new sf::Sprite***[_numLayers];
    for (int l=0; l<_numLayers; l++){
        _tilemapSprite[l] = new sf::Sprite**[_height];
    }
    for (int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y] = new sf::Sprite*[_width];
            for(int x=0; x<_width; x++) {
                _tilemapSprite[l][y][x] = new sf::Sprite(tex_plat);
            }
        }
    } 
    sf::Sprite _tilesetSprite[_numTiles];
    int f,c;
    
    //std::cout << "Numero de columnas de tiles: " << _numColTiles << std::endl;
    //std::cout << "Numero de tiles: " << _numTiles << std::endl;
    
    for(int i=0; i < _numTiles; i++){
        f = (int) i/_numColTiles;
        c = (i%_numColTiles);
        //std::cout << "GID: " << i << "  ";
       //std::cout << "fila: " << f << "  ";
        //std::cout << "columna : " << c << std::endl;
        _tilesetSprite[i].setTexture(tex_plat);
        _tilesetSprite[i].setTextureRect(sf::IntRect(c*32,f*32,_tsw,_tsh));
    }

    
    //CREACION DEL ARRAY DE SPRITES
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                int gid = _tilemap[l][y][x]-1;
                std::cout << "GID: " << gid << "  " << std::endl;
                if(gid>=_tsw*_tsh){
                    std::cout << "Error, gid at (l,x,y)= (" << l << "," << x << "," << y << ") :" << gid << " fuera del rango del tileset (" << _tsw*_tsh << ")" << std::endl;
                } else if(gid>-1){
                    _tilemapSprite[l][y][x] = new sf::Sprite(tex_plat, _tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tileWidth, y*_tileHeight);
                } else{
                    _tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }
 /*
    //Liberar memoria del tilemap
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            delete[] _tilemap[l][y];
        }
        delete[] _tilemap[l];
    }
    delete[] _tilemap;
    
        //Liberar memoria TileMapSprite
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height;y++){
            for(int x=0; x<_width;x++){
                delete[] _tilemapSprite[l][y][x];
            }
            delete[] _tilemapSprite[l][y];
        }
        delete[] _tilemapSprite[l];
    }
    delete[] _tilemapSprite;
 */
}
void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    
    for(int y=0; y<_height; y++){
        for(int x=0; x<_width; x++){
            if(_tilemapSprite[capa][y][x]!=NULL)
                target.draw(*(_tilemapSprite[capa][y][x]),states);
        }
    }
}
void Mapa::activarCapa(int num_capa){
    capa = num_capa;
}
int Mapa::getTile(float x, float y){
    int tile = _tilemap[capa][(int)y][(int)x];
    return tile;
}

int Mapa::getAltura(){
    int res = _height;
    return res;
}

sf::Sprite Mapa::getFondo(){
    return fondo;
}
