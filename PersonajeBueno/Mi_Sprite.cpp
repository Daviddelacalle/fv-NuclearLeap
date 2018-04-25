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

Mi_Sprite::Mi_Sprite(int _x , int _y , int _w ,int _h, int _posx , int _posy){
    
    if (!tex.loadFromFile("resources/Sprite.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    
    sprite.setTexture(tex);
    
    //Le pongo el centroide donde corresponde
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