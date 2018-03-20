/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ia.h
 * Author: pato-lt
 *
 * Created on 16 de marzo de 2018, 18:32
 */
#include "config.h"

#ifndef IA_H
#define IA_H

class Ia{
protected:
    float posx;
    float posy;
    int nsprite;
    int max_sprites;
    int tam;
    int dirx;
    int diry;
    sf::Texture tex;
    sf::Sprite sprite;
public:
    Ia(float,float);
    sf::Sprite getSprite();
    void actualizarSprite();
};

class Npc1: public Ia{
    protected:
        sf::RectangleShape box_up;
        sf::RectangleShape box_left;
        sf::RectangleShape box_right;
    public: 
        Npc1(float,float);
        void movimiento(sf::RectangleShape &_bloque);
        void actualizarBox();
        sf::RectangleShape getBox_up();
        sf::RectangleShape getBox_right();
        sf::RectangleShape getBox_left();
};

class Npc3: public Npc1{
    public: 
        Npc3(float,float);
};

class Npc5: public Ia{
    public: 
        Npc5(float,float);
        void movimiento(sf::RectangleShape &_pj,vector<sf::RectangleShape*> &_plataformas);
};
#endif /* IA_H */

