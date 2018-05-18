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
#include <SFML/Audio.hpp>
#include <iostream>
#include "tinyxml2.h"
#include "mapa.h"
#include "Rads.h"
#include "Personaje.h"
#include "LoadXML.h"
#include "Juego.h"
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
      
}
void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    Mapa::Instance()->animacionesMapa();
    for(int y=0; y<_height; y++){
        for(int x=0; x<_width; x++){
            if(_tilemapSprite[capa][y][x]!=NULL)
                target.draw(*(_tilemapSprite[capa][y][x]),states);
        }
    }
    
    auto it = v_rads.begin();    
    for(it = v_rads.begin(); it != v_rads.end(); it++){           
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

vector<Npc1*> Mapa::getvNpc1(){
    return v_npc1;
}

vector<Npc3*> Mapa::getvNpc3(){
    return v_npc3;
}

vector<Npc5*> Mapa::getvNpc5(){
    return v_npc5;
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

void Mapa::recogerRads(Mi_Sprite &_pj, int &_puntuacion){
       Juego* juego = Juego::Instance();
    auto it = v_rads.begin();
    
    for(it; it != v_rads.end(); it++){
        
        Rads *tmp = *it;
         
        if(_pj.getSprite().getGlobalBounds().intersects(tmp->getSprite().getSprite().getGlobalBounds())){ 
            v_rads.erase(it);
            if(juego->pj.pordos==true){
                _puntuacion+=2;
            }
            else{
                _puntuacion++;
            }
            
            delete tmp; 
            break;
        }
        
        
    }
}

void Mapa::CargarMapa(int capita, int height, int width, int ***tilemap, sf::Sprite ****tilemapSpri,
        sf::Sprite fond, sf::Texture tex_fond, sf::Texture tex_pla, int alturasZona[zonas],
        std::string fonditos[zonas], vector<Rads*> rad, vector<Npc1*> npc1, vector<Npc3*> npc3,
        vector<Npc5*> npc5, vector< vector<sf::Sprite> > aRueda, vector<sf::Sprite> aFuego){
    
    capa=capita;
    _height=height;
    _width=width;
    _tilemap=tilemap;
    _tilemapSprite=tilemapSpri;
    fondo = fond;
    tex_fondo = tex_fond;
    tex_plat = tex_pla;
    for(int i=0; i<zonas;i++){
        alturasZonas[i] = alturasZona[i];
        fondos[i] = fonditos[i];
    }
    v_rads = rad;
    v_npc1 = npc1;
    v_npc3 = npc3;
    v_npc5 = npc5;
    animRueda = aRueda;
    animFuego = aFuego;
    numSpriteRueda = 1;
    numSpriteFuego = 1;
    relojAnim.restart();
  
 }

void Mapa::animacionesMapa(){
    //cout << relojAnim.getElapsedTime().asSeconds() << endl;
    if(relojAnim.getElapsedTime().asSeconds()>0.08){
        
        activarCapa(3);
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemap[capa][y][x]==72 || _tilemap[capa][y][x]==16){
                    _tilemapSprite[capa][y][x]->setTextureRect(animRueda[0][numSpriteRueda].getTextureRect());
                    numSpriteRueda = (numSpriteRueda+1)%2;
                }
                if(_tilemap[capa][y][x]==73 || _tilemap[capa][y][x]==17){
                    _tilemapSprite[capa][y][x]->setTextureRect(animRueda[1][numSpriteRueda].getTextureRect());
                    numSpriteRueda = (numSpriteRueda+1)%2;
                }
                if(_tilemap[capa][y][x]==100 || _tilemap[capa][y][x]==44){
                    _tilemapSprite[capa][y][x]->setTextureRect(animRueda[2][numSpriteRueda].getTextureRect());
                    numSpriteRueda = (numSpriteRueda+1)%2;
                }
                if(_tilemap[capa][y][x]==101 || _tilemap[capa][y][x]==45){
                    _tilemapSprite[capa][y][x]->setTextureRect(animRueda[3][numSpriteRueda].getTextureRect());
                    numSpriteRueda = (numSpriteRueda+1)%2;
                }
                if(_tilemap[capa][y][x]==103 || _tilemap[capa][y][x]==104 || _tilemap[capa][y][x]==105){
                    _tilemapSprite[capa][y][x]->setTextureRect(animFuego[numSpriteFuego].getTextureRect());
                    numSpriteFuego = (numSpriteFuego+1)%3;
                }
            }
        }
        relojAnim.restart();
    }
}

