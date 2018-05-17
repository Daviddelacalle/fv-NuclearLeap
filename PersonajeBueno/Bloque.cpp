/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.cpp
 * Author: david
 * 
 * Created on 16 de mayo de 2018, 16:11
 */

#include "Bloque.h"
#include <SFML/Graphics.hpp>

Bloque::Bloque() {
    
}
sf::RectangleShape Bloque::getBloque(){
    return sprite;
}
void Bloque::setParams(float x, float y, float posx, float posy){
    sprite = sf::RectangleShape(sf::Vector2f(x,y));
    sprite.setOrigin(x/2,y/2);
    sprite.setPosition(posx, posy);
    sprite.setFillColor(sf::Color::Red);
}
void Bloque::rotate(float n){
    sprite.rotate(n);
}
void Bloque::setPos(float x, float y){
    sprite.setPosition(x,y);
}