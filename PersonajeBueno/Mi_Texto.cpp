/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mi_Texto.cpp
 * Author: natalia
 * 
 * Created on 27 de abril de 2018, 13:16
 */

#include "Mi_Texto.h"
#include "Motor_2D.h"

Mi_Texto::Mi_Texto() {    
    font.loadFromFile("8-bit-pusab.ttf");  
    
    
}


void Mi_Texto::setParams(sf::String _string, int _tam, float _posx, float _posy){
   
    text.setFont(font);
    text.setString(_string);
    text.setCharacterSize(_tam);
    text.setPosition(_posx, _posy);
    text.setColor(sf::Color::White);
    
}

sf::Text Mi_Texto::getTexto(){
    return text;
}



void Mi_Texto::draw(){
    Motor_2D *mi_motor = Motor_2D::Instance();
    mi_motor->draw(text);
}

void Mi_Texto::setText(sf::String _string){
    text.setString(_string);
}

void Mi_Texto::setPosition(float _posx, float _posy){
    text.setPosition(_posx,_posy);
}

void Mi_Texto::setColor(sf::Color color){
    text.setColor(color);
}
void Mi_Texto::setStyle(){
    text.setStyle(sf::Text::Bold);
}