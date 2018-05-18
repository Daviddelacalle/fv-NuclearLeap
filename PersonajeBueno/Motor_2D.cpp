/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor_2D.cpp
 * Author: pato-pc
 * 
 * Created on 25 de abril de 2018, 19:31
 */

#include "Motor_2D.h"

Motor_2D* Motor_2D::pinstance = 0;

Motor_2D* Motor_2D::Instance() {
    if (pinstance == 0) { 
        pinstance = new Motor_2D;
    } 
    
    return pinstance;
}

Motor_2D::Motor_2D() { 
    window = new sf::RenderWindow(sf::VideoMode(448,700),"PersonajeBueno");
    Mapa* map = Mapa::Instance();
    vista_principal = new sf::View(sf::FloatRect(0, map->getAltura()*32 - 32*9.5, 448, 700)); 
    cout << "map->getAltura()*32 - 32*9.5: " << map->getAltura()*32 - 32*9.5 << "\n"; 
    cout << "Creas la vista posy: " << vista_principal->getCenter().y << "\n";
}

sf::RenderWindow* Motor_2D::getWindow(){
    return window;
}


sf::View* Motor_2D::getVistaPrincipal(){
    return vista_principal;
}

float Motor_2D::get_clockElapsedTime(){
    return clock.getElapsedTime().asMilliseconds();
}

void Motor_2D::draw(sf::Sprite& _sprite){
    window->draw(_sprite);
}

void Motor_2D::draw(sf::Text& _text){
    window->draw(_text);
}

void Motor_2D::setVistaPrincipal(){
    window->setView(*vista_principal);
}

void Motor_2D::restartClock(){
    clock.restart();
}

void Motor_2D::setCenterVista(float _pjy){ 
    Mapa* map = Mapa::Instance(); 
    vista_principal->setCenter(224,_pjy-60); 
} 
 
void Motor_2D::actualizarVista(Personaje& _pj){ 
    int dirv_y; 
    float posx_vista = 224; 
    float posy_vista = getVistaPrincipal()->getCenter().y; 
    cout << "posy_vista: " << posy_vista << "\n"; 
     
    int pos_pj = _pj.getSprite().getPosy() - 64; 
    cout << "pos pj: " << pos_pj << "\n"; 
     
    if(pos_pj < posy_vista -20){ 
    //El pj esta encima 
        dirv_y = -1; 
 
    } 
    else if(pos_pj > posy_vista +20){ 
    //El pj esta debajo 
        dirv_y = 1; 
 
    } 
     
    else { 
    //El pj esta a la misma altura y 
        dirv_y = 0; 
 
    } 
    cout << "dir v: " << dirv_y << "\n"; 
    posy_vista = posy_vista + dirv_y*_pj.getVelocidad()/1.2; 
    cout << "posy_vista despues: " << posy_vista << "\n"; 
    cout << "--------------------------- \n" ; 
    vista_principal->setCenter(posx_vista,posy_vista); 
}