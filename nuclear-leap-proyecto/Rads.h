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

#ifndef RADS_H
#define RADS_H

class Rads{
private:
    int puntuacion;
    int posx;
    int posy;
    sf::Texture tex;
    sf::Sprite sprite;
public:
    Rads(int,int,int);
    int getPuntuacion();
    sf::Sprite getSprite();
    void setPosition(int, int);
};


#endif /* RADS_H */

