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
}

sf::RenderWindow* Motor_2D::getWindow(){
    return window;
}

