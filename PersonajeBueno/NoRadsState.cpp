/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WinState.cpp
 * Author: natalia
 * 
 * Created on 18 de mayo de 2018, 13:24
 */

#include "NoRadsState.h"
#include "Estado.h"
#include "Motor_2D.h"
#include "Juego.h"
#include "Mi_Texto.h"
#include "config.h"
#include "Mundo.h"


NoRadsState* NoRadsState::pinstance = 0;

NoRadsState* NoRadsState::Instance() {
    if (pinstance == 0) { 
        pinstance = new NoRadsState;
    } 
    
    return pinstance;
}

void NoRadsState::Init(){
    
}
NoRadsState::NoRadsState() {
    background.setTex("not-rads.jpg");
    background.setParams(0,0,448,700,0,0);
    activo = false;
    estado=0;
     puntos=0;
    ss<<puntos;  
    texto.setParams(ss.str(),30,120,-120);
    texto.setColor(sf::Color::Black);
}

void NoRadsState::HandleInput(){  
     std::stringstream ss;
    ss<<puntos;
    texto.setText(ss.str());
    sf::Event event;    
    Motor_2D* motor = Motor_2D::Instance();
    Juego* juego = Juego::Instance();
     Mundo* mundo = Mundo::Instance();
    activo = true;
    
  
    // vidas.setText()    
     while (motor->getWindow()->pollEvent(event)&& activo)
        {            
            switch(event.type){
                case sf::Event::Closed:
                    motor->getWindow()->close();
                    break;             
                case sf::Event::KeyPressed:  
                    switch(event.key.code) { 
                        case sf::Keyboard::Return: 
                            juego->pausa=false; 
                            mundo->inicializar();         
                            break;
                        case sf::Keyboard::Q:
                            motor->getWindow()->close();
                        break;
                              
                    }

            }
            
            
     
     }

}

void NoRadsState::Update(int num){
    
        
}

void NoRadsState::Update(string menu){
    
}

void NoRadsState::Draw(){
    background.draw();
     texto.draw();
 
}

