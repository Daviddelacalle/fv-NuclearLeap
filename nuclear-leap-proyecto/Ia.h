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
    int posx;
    int posy;
    sf::Texture tex;
    sf::Sprite sprite;
public:
    sf::Sprite getSprite();
    Ia(int,int);
};

class Npc1: public Ia{
    private:
        sf::RectangleShape box_up;
        sf::RectangleShape box_left;
        sf::RectangleShape box_right;
    public: 
        Npc1(int,int);
        void movimiento();
};

class Npc3: public Ia{
    public: 
        Npc3(int,int);
        void movimiento();
};

class Npc5: public Ia{
    public: 
        Npc5(int,int);
        void movimiento();
};
#endif /* IA_H */

