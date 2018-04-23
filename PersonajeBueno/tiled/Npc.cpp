/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npc.cpp
 * Author: pato-lt
 * 
 * Created on 23 de abril de 2018, 11:17
 */

#include <SFML/Graphics/Sprite.hpp>

#include "Npc.h"

Npc::Npc(int _posx, int _posy) {
    posx = (float)_posx;
    posy = (float)_posy;
    dirx = 1;
    diry = 0;
    nsprite = 0;
}

sf::Sprite Npc::getSprite(){
    return sprite;
}

void Npc::setPosition(int _x, int _y){
    posx = (float)_x;
    posy = (float)_y;
}

Npc1::Npc1(int _posx, int _posy):Npc(_posx,_posy){
    tam = 32;
    max_sprites = 4;
    
     if (!tex.loadFromFile("sprites/npc1.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    sprite = sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(nsprite*32, 0*32, 32, 32));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
    
    //COLISIONADORES
    
    box_up = sf::RectangleShape(sf::Vector2f(28,1));
    box_up.setOrigin(14,0);
    box_up.setPosition(posx,posy-16);
    box_up.setFillColor(sf::Color::Red);
    
    box_left = sf::RectangleShape(sf::Vector2f(1,16));
    box_left.setOrigin(0,8);
    box_left.setPosition(posx-16,posy+2);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,16));
    box_right.setOrigin(0,8);
    box_right.setPosition(posx+16,posy+2);
    box_right.setFillColor(sf::Color::Red);

}