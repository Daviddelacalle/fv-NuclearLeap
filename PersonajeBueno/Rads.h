/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rads.h
 * Author: pato-lt
 *
 * Created on 9 de marzo de 2018, 17:24
 */
#include <iostream>

#include <string>
#include <sstream> 
#include "Mi_Sprite.h"
#ifndef RADS_H
#define RADS_H

using namespace std;

class Rads{
private:
    int puntuacion;
    int posx;
    int posy;
  
    Mi_Sprite sprite;
public:
    Rads(int,int,int);
    int getPuntuacion();
    Mi_Sprite getSprite();
    void setPosition(int, int);
    sf::Text crearPuntuacion();
    void draw();
   
    
};


#endif /* RADS_H */
