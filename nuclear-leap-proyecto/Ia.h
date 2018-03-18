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

#ifndef IA_H
#define IA_H

class Ia{
protected:
    float posx;
    float posy;
    int dirx;
    int diry;
    sf::Texture tex;
    sf::Sprite sprite;
public:
    sf::Sprite getSprite();
    Ia(float,float);
};

class Npc1: public Ia{
    protected:
        int tam;
        int nsprite;
        int max_sprites;
        sf::RectangleShape box_up;
        sf::RectangleShape box_left;
        sf::RectangleShape box_right;
    public: 
        Npc1(float,float);
        void movimiento(sf::RectangleShape &_bloque);
        void actualizarBox();
        void actualizarSprite();
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
        void movimiento();
};
#endif /* IA_H */

