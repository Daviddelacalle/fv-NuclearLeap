/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npc.h
 * Author: pato-lt
 *
 * Created on 23 de abril de 2018, 11:17
 */

#ifndef NPC_H
#define NPC_H

class Npc {
public:
    Npc(int,int);
    sf::Sprite getSprite();
    void actualizarSprite();
    sf::RectangleShape getBox_up();
    sf::RectangleShape getBox_left();
    sf::RectangleShape getBox_right();
    void setPosition(int,int);
    
protected:
    float posx;
    float posy;
    int dirx;
    int diry;
    int nsprite;
    
    int max_sprites;
    int tam;
    
    sf::Texture tex;
    sf::Sprite sprite;
    sf::RectangleShape box_up;
    sf::RectangleShape box_left;
    sf::RectangleShape box_right;
    
};

class Npc1: public Npc{
    private:
    void check_morir();
    
    protected:
        
    public: 
        void actualizarBox();
        Npc1(int,int);
        void movimiento();
};

class Npc3: public Npc1{
    public: 
        Npc3(int,int);
};

class Npc5: public Npc{
    private:
        sf::RectangleShape box_down;
    public: 
        Npc5(int,int);
        void movimiento();
        sf::RectangleShape getBox_down();
        void actualizarBox();
};
#endif /* NPC_H */

