/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mi_Sprite.h
 * Author: pato-pc
 *
 * Created on 25 de abril de 2018, 19:32
 */

#ifndef MI_SPRITE_H
#define MI_SPRITE_H

#include "config.h"

class Mi_Sprite {
public:
    Mi_Sprite();
    float getPosx();
    float getPosy();
    float getScaley();
    float getScalex();
    sf::Sprite getSprite();
    
    void setPosition(float, float);
    void setFrame(int,int);
    void move(float,float);
    void setScale(float,float);
    void setParams(int, int , int, int ,int, int);
    void draw();
private:
    sf::Sprite sprite;
    sf::Texture tex;
};

#endif /* MI_SPRITE_H */

