/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.h
 * Author: pato-lt
 *
 * Created on 19 de abril de 2018, 13:54
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "config.h"

class Personaje {
public:
    Personaje();
    sf::Sprite getSprite();   
    void moverSalto();
    void mover();
    void gravity();
    int getEspacios();
    void actualizarSprite();    
    void cambiarPosicion(int num, int num2);    
    float gravedad;
    void estoyRoja(float);
    void estoyAzul(float);
    void estoyPortalIda(float, float);
    void estoyPortalVuelta(float, float);
    void estoySaltador();
    void estoyNormal();
    void setPosition(int, int);
    sf::RectangleShape colisionador();
    int contEspacios;
    int var1;
    
    
    
private:
    int posx;
    int posy;
    int direccion;   
    int alturasuelo;
    sf::Vector2f velocidad;
    float velocidadsalto;
    sf::Sprite sprite;
    sf::Texture tex;
    int espacio;
    int nsprite;
    int max_sprites;
    sf::RectangleShape colision;
    bool pared;
    
   
    
  

    
};

#endif /* PERSONAJE_H */

