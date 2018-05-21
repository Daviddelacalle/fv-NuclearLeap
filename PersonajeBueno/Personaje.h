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
#include "Bloque.h"
#include "Vector.h"
#include "Reloj.h"
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
    void estoyRoja(int);
    void estoyAzul(int);
    void estoyPortalIda(float, float);
    void estoyPortalVuelta(float, float);
    void estoySaltador();
    void estoyNormal();
    void setPosition(float, float);
    void draw();
    void iniciarPersonaje();
    int getPuntos();
    void win();  
    Bloque getBoxAbajo();
    Bloque getBoxAbajo2();
    Bloque getBoxAbajo3();
    Bloque getBoxAbajo4();
    Bloque getBoxArriba();
    Bloque getBoxArriba2();
    Bloque getBoxArriba3();
    Bloque getBoxDerecha();
    Bloque getBoxIzquierda();
    void actualizarBoxes();
    int contEspacios;
    int var1;
    int getVidas();
    void update(float);
    float getVelocidad();
    void actualizarVidas();
    void setPosVidas();
    void morir();
    void actualizarPuntuacion();
    void abrirMutaciones();
    void inmunidad();
    void jump();
    void porDos();
    bool pordos;
    int inmune;
    Reloj clock;
    string reloj;
private:
    int lastCheck;
    int cosa;
    int posy_vida;
    int posx_vida;
    bool pierdo;
    float vel_camara;
    int alturasuelo_nueva;
    float gravedad;
    int posx;
    int posy;
    int direccion;   
    int dir_aux; //variable para guardar la direccion para cuando salga de la pared
    bool check_pared; // para saber si he tocado la pared
    int alturasuelo;
     int checkpoint; 
    Vector velocidad;
    float velocidadsalto;
    Mi_Sprite sprite;
    Mi_Sprite sprite_vidas;
    Mi_Sprite sprite_puntuacion;
    Mi_Texto text_vidas;
    Mi_Texto text_puntuacion;
    Mi_Texto text_perder;
    int espacio;
    int nsprite;
    int max_sprites;
    Bloque boxAbajo;
    Bloque boxAbajo2;
    Bloque boxAbajo3;
    Bloque boxAbajo4;
    Bloque boxArriba;
    Bloque boxArriba2;
    Bloque boxArriba3;
    Bloque boxDerecha;
    Bloque boxIzquierda;
    int vidas;
    int puntuacion;    
    bool jumpy;
    
    Mi_Sprite soyInmune;
    Mi_Texto soyPor2;
    Mi_Texto soyPor3;
    
    Reloj clock2;
    Reloj clockJump;
    Reloj tiempoFinal;
  

    
};

#endif /* PERSONAJE_H */
