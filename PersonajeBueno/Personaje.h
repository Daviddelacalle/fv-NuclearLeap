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
    void mover(float);
    void gravity(float);
    int getEspacios();
    void actualizarSprite();    
    void cambiarPosicion(int num, int num2);    
    void estoyRoja(int);
    void estoyAzul(int);
    void estoyPortalIda(float, float);
    void estoyPortalVuelta(float, float);
    void estoySaltador();
    void estoyNormal();
    void setPosition(float, float);
    sf::RectangleShape getBoxAbajo();
    sf::RectangleShape getBoxArriba();
    sf::RectangleShape getBoxDerecha();
    sf::RectangleShape getBoxIzquierda();
    void actualizarBoxes();
    int contEspacios;
    int var1;
    
    
    
private:
    int alturasuelo_nueva;
    float gravedad;
    int posx;
    int posy;
    int direccion;   
    int dir_aux; //variable para guardar la direccion para cuando salga de la pared
    bool check_pared; // para saber si he tocado la pared
    int alturasuelo;
    sf::Vector2f velocidad;
    float velocidadsalto;
    sf::Sprite sprite;
    sf::Texture tex;
    int espacio;
    int nsprite;
    int max_sprites;
    sf::RectangleShape boxAbajo;
    sf::RectangleShape boxArriba;
    sf::RectangleShape boxDerecha;
    sf::RectangleShape boxIzquierda;
    
   
    
  

    
};

#endif /* PERSONAJE_H */

