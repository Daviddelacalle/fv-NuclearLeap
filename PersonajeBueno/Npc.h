/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npc.h
 * Author: pato-lt
 *
 * Created on 23 de abril de 2018, 11:54
 */

#ifndef NPC_H
#define NPC_H

#include "config.h"
#include "Personaje.h"
#include "Mi_Sprite.h"

class Npc {
public:
    Npc(float,float);
    void setPosition(float,float);
    Mi_Sprite getSprite();
    void actualizarSprite();
    void draw();

    sf::RectangleShape getBox_up();
    sf::RectangleShape getBox_left();
    sf::RectangleShape getBox_right();
    sf::RectangleShape getBox_down();
    
protected:
    float posx;
    float posy;
    float posix;
    float posiy;
    int dirx;
    int diry;
    int nsprite;
    int line_sprite;
    int max_sprites;
    int tam;
    int vel_actualizar;
    
    sf::Texture tex;
    Mi_Sprite sprite;
    sf::RectangleShape box_up;
    sf::RectangleShape box_left;
    sf::RectangleShape box_right;
    sf::RectangleShape box_down;

};

class Npc1: public Npc{
    private:
       float div_box; 
    public: 
        void actualizarBox();
        Npc1(float,float);
        void movimiento();
        void update(Personaje &_pj);
        void matarPj(Personaje &_pj);
};

class Npc3: public Npc{
    private:
        float div_box;  
    public: 
        Npc3(float,float);
        void actualizarBox();
        void movimiento();
        void update(Personaje &_pj);
        void matarPj(Personaje &_pj);
};

class Npc5: public Npc{
    private:

    public: 
        Npc5(float,float);
        void movimiento(Personaje &_pj);
        void update(Personaje &_pj);
        void actualizarBox();
        void matarPj(Personaje &_pj);
};

#endif /* NPC_H */

