/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mi_Sprite.cpp
 * Author: pato-pc
 * 
 * Created on 25 de abril de 2018, 19:32
 */

#include "Mi_Sprite.h"
#include "Motor_2D.h"

Mi_Sprite::Mi_Sprite(){
    
    if (!tex.loadFromFile("sprites.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    //Le pongo el centroide donde corresponde
   
    
}

void Mi_Sprite::setParams(int _x, int _y, int _w, int _h, int _posx, int _posy){
    
    
    sprite.setTexture(tex);
    
     sprite.setOrigin(_w/2,_h/2);
    //Cojo el sprite que me interesa por defecto del sheet
   // sprite.setTextureRect(sf::IntRect(23, 448, 23, 24));
    sprite.setTextureRect(sf::IntRect(_x*_w, _y*_h, _w, _h));   
    
    sprite.setPosition(_posx, _posy);
    
}

float Mi_Sprite::getPosx(){
    return sprite.getPosition().x;
}

float Mi_Sprite::getPosy(){
    return sprite.getPosition().y;
}

float Mi_Sprite::getScalex(){
    return sprite.getScale().x;
}

float Mi_Sprite::getScaley(){
    return sprite.getScale().y;
}

float Mi_Sprite::get_clockElapsedTime(){
    return clock.getElapsedTime().asMilliseconds();
}

sf::Sprite Mi_Sprite::getSprite(){
    return sprite;
}

void Mi_Sprite::setFrame(int _x, int _y){
    sprite.setTextureRect(sf::IntRect(_x*sprite.getTextureRect().width, _y*sprite.getTextureRect().height, sprite.getTextureRect().width, sprite.getTextureRect().height)); 
}

void Mi_Sprite::setPosition(float _posx, float _posy){
    sprite.setPosition(_posx,_posy);
}

void Mi_Sprite::move(float _x, float _y){
    sprite.move(_x,_y);
}

void Mi_Sprite::setScale(float _x, float _y){
    sprite.setScale(_x,_y);
}

void Mi_Sprite::draw(){
    Motor_2D *mi_motor = Motor_2D::Instance();
    mi_motor->draw(sprite);
}

void Mi_Sprite::restartClock(){
    clock.restart();
}

void Mi_Sprite::setOrigin(int x, int y){
    sprite.setOrigin(x,y);
}