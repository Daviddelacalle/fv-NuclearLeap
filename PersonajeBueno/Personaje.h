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
#include "Mi_Sprite.h"
#include "Mi_Texto.h"
#include "Rads.h"

class Personaje {
public:
    Personaje();
    Mi_Sprite getSprite();     
    void moverSalto();
    void mover(float);
    void gravity(float);
    int getEspacios();
    void actualizarSprite();    
    void cambiarPosicion(int num, int num2);    
    void estoyPortalIda(float, float);
    void estoyPortalVuelta(float, float);
    void setPosition(float, float);
    void draw();

    sf::RectangleShape getBoxAbajo();
    sf::RectangleShape getBoxArriba();
    sf::RectangleShape getBoxDerecha();
    sf::RectangleShape getBoxIzquierda();
    void actualizarBoxes();

    void update(float);
    void actualizarVidas();
    void setPosVidas();
    void morir();
    void actualizarPuntuacion();
    
    
private:
    int posy_vida;
    int posx_vida;
    bool pierdo;
    int checkpoint; 

    Mi_Sprite sprite;
    Mi_Sprite sprite_vidas;
    Mi_Texto text_vidas;
    Mi_Texto text_puntuacion;
    Mi_Texto text_perder;
    int nsprite;
    int max_sprites;
    sf::RectangleShape boxAbajo;
    sf::RectangleShape boxArriba;
    sf::RectangleShape boxDerecha;
    sf::RectangleShape boxIzquierda;
    int vidas;
    int puntuacion;
   
    //variables de movimiento
    float pos_inicial;
    
    int direccion;
    float posx;
    float posy;
    
    float vel_y;
    
    bool estoy_suelo;
    int n_saltos;

    
};

#endif /* PERSONAJE_H */

