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
#include "Rads.h"
#include "Personaje.h"
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
    int _tileWidth, _tileHeight, _numLayers=0, _tsw, _tsh,_numTiles,_numColTiles, temp, altFinal;
    int num_bloques = zonas * sec_zona * bloq_seccion; 
    mivector.resize(num_bloques*6);
    
    int cont =0;
    //MAPA
    XMLDocument doc;
    doc.LoadFile("tiled/0.tmx");
    
    //Tamaño del mapa y de los tiles
    XMLElement *map = doc.FirstChildElement("map");
    
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);
    
    //Medidas del tileset
    map->FirstChildElement("tileset")->QueryIntAttribute("tilewidth", &_tsw);
    map->FirstChildElement("tileset")->QueryIntAttribute("tileheight", &_tsh);
    map->FirstChildElement("tileset")->QueryIntAttribute("tilecount", &_numTiles);
    map->FirstChildElement("tileset")->QueryIntAttribute("columns", &_numColTiles);
    
    //textura
    if(!tex_plat.loadFromFile("tiled/plataformas.png")){
        std::cerr << "Error cargando la imagen sprites.png";
    }
    
    //Capas XML
    XMLElement *layer = map->FirstChildElement("layer");
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    
    //LEER EL BLOQUE FINAL
    XMLDocument doc2;
    doc2.LoadFile("tiled/final.tmx");
    XMLElement *map2 = doc2.FirstChildElement("map");
    map2->QueryIntAttribute("height", &altFinal);         
    _height += altFinal;
    
    
    //--------------LEER TODOS LOS XML----------------------
    
    //VARIABLES
    XMLDocument document[num_bloques*2];
    XMLElement *tmxs[num_bloques*2];
    std::vector<int> usados(6);
    srand(time(NULL));
    //fondo 
    XMLElement *img_fondo;
    const char *fondo_cadena;
    
    for(int i=0; i<zonas; i++){
        
        std::string s = std::to_string(i+1);
        std::string cad = "tiled/zona" + s + "/";
        usados.clear();
        alturasZonas[i]=0;
        
        for(int l=1 ; l< (sec_zona * bloq_seccion * 2); l=l+2){
            int pB, pS;
            //---------------SUELO------------------------
            
            int suelo = l-1;
            pS = suelo + i*(sec_zona * bloq_seccion * 2);
            std::string cad_suelo;
            if(suelo%3==0)//checkpoint
            {
                cad_suelo = cad + "check.tmx";
                
                
            }else//suelo normal
            {
                cad_suelo = cad + "suelo.tmx";
                
            }
            char const *s = cad_suelo.c_str();
            std::cout << s << std::endl; 
            document[pS].LoadFile(s);
            tmxs[pS] = document[pS].FirstChildElement("map");
            _height++;
            alturas[pS]=1;
            
            //---------------BLOQUE------------------------
            pB = l + i*(sec_zona * bloq_seccion * 2);
            
            //seleccionar un bloque aletorio que no se haya seleccionado antes
            int nb = bloqRandom(usados);
            usados.push_back(nb);
            
            std::string cadena = cad + std::to_string(nb) + ".tmx";
            char const *u = cadena.c_str();
            std::cout << u << std::endl; 
            document[pB].LoadFile(u);
            
            tmxs[pB] = document[pB].FirstChildElement("map");
            tmxs[pB]->QueryIntAttribute("height", &temp);
            
            _height += temp;
            alturas[pB]=temp;
            temp++;
            alturasZonas[i]=alturasZonas[i] + temp*32;
            for(int j=i-1; j>-1; j--){
                alturasZonas[j] = alturasZonas[j]+temp*32;
            } 
            
        }
        //FONDO
            img_fondo = tmxs[i*(sec_zona * bloq_seccion * 2)]->FirstChildElement("imagelayer")->FirstChildElement("image");
            fondo_cadena = img_fondo->Attribute("source");
            std::string fc = fondo_cadena;
            std::string buf = cad + fc;
            std::cout << buf << std::endl;
            fondos[i]=buf;
    }
    
 //-------------------------------------------------------
    
    if(zonas>0){
        if(!tex_fondo.loadFromFile(fondos[0])){
            std::cerr << "Error cargando la imagen";
            exit(0);
        }

        fondo = sf::Sprite(tex_fondo);
    }
    
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
    
    
    //Cargando los GIDs de multiples capas del BLOQUE FINAL
    
    XMLElement *data[_numLayers];
    layer = map2->FirstChildElement("layer");
    
    data[0] = layer->FirstChildElement("data")->FirstChildElement("tile");
    
    for(int i=1; i<_numLayers; i++){
        layer = layer->NextSiblingElement("layer");
        data[i] = layer->FirstChildElement("data")->FirstChildElement("tile");        
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y < altFinal; y++){
            for(int x=0; x<_width; x++){
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                
                //Avanzo al siguiente tag
                data[l] = data[l]->NextSiblingElement("tile");
            }
        }
    }
    
    temp=altFinal;
    //Cargando los GIDs de multiples capas de LOS BLOQUES ALEATORIOS
    
    for(int i=(num_bloques*2-1); i>-1; i--){
        
        XMLElement *data[_numLayers];
        layer = tmxs[i]->FirstChildElement("layer");

        data[0] = layer->FirstChildElement("data")->FirstChildElement("tile");

        for(int i=1; i<_numLayers; i++){
            layer = layer->NextSiblingElement("layer");
            data[i] = layer->FirstChildElement("data")->FirstChildElement("tile");        
        }

        for(int l=0; l<_numLayers; l++){
            for(int y=temp; y< (temp+alturas[i]); y++){
                for(int x=0; x<_width; x++){
                    data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                   
                if(l==2 && _tilemap[l][y][x]==1){
                    cout<<"holaaaaaaaaaaaaa";
                    Rads *rad1 = new Rads(x*32,y*32,1); 
                    mivector[cont]=rad1; 
                    cont++;
                }
                    //Avanzo al siguiente tag
                    data[l] = data[l]->NextSiblingElement("tile");
                }
            }
        }
        temp=temp+alturas[i];
    }
   
    //Cargando los GIDs de multiples capas del BLOQUE INICIAL
    
    layer = map->FirstChildElement("layer");
    
    data[0] = layer->FirstChildElement("data")->FirstChildElement("tile");
    
    for(int i=1; i<_numLayers; i++){
        layer = layer->NextSiblingElement("layer");
        data[i] = layer->FirstChildElement("data")->FirstChildElement("tile");        
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=temp; y < _height; y++){
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
                //std::cout << "GID: " << gid << "  " << std::endl;
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
    
      auto it = mivector.begin();    
      
        for(it = mivector.begin(); it != mivector.end(); it++){           
            Rads *tmp = *it; 
            tmp->draw();            
        } 
}
void Mapa::activarCapa(int num_capa){
    capa = num_capa;
}
int Mapa::getTile(float x, float y){
    int tile = _tilemap[capa][(int)y][(int)x];
    return tile;
}
 int Mapa::getCoordenadas(int tile, int xy){
     int res;
    
    for(int y=0; y<_height; y++){
        for(int x=0; x<_width; x++){
           if(_tilemap[capa][y][x] == tile){
               if(xy==0)
                   res=x;
               if(xy==1)
                   res=y;
           }           
        }
    }
    return res;
}
 
int Mapa::getAltura(){
    int res = _height;
    return res;
}

sf::Sprite Mapa::getFondo(){
    return fondo;
}
void Mapa::setFondo(int numz){
    if(zonas>0){
        if(!tex_fondo.loadFromFile(fondos[numz])){
            std::cerr << "Error cargando la imagen";
            exit(0);
        }

        fondo = sf::Sprite(tex_fondo);
    }
}

int Mapa::getAltZonas(int numz){
    return alturasZonas[numz];
}

int Mapa::bloqRandom(std::vector<int> v){
    int random;
    do{
        random = (rand()%6) + 1;
    }
    while(std::find(v.begin(), v.end(), random) != v.end());
    

  
    return random;
}

vector<Rads*> Mapa::getRads(){
    return mivector;
}

void Mapa::recogerRads(Mi_Sprite &_pj){
    

    auto it = mivector.begin();
    
    for(it; it != mivector.end(); it++){
        
        Rads *tmp = *it;
         
        if(_pj.getSprite().getGlobalBounds().intersects(tmp->getSprite().getSprite().getGlobalBounds())){          
            mivector.erase(it);       
            delete tmp; 
            break;
        }
        
    }
}

