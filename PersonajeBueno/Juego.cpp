/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: natalia
 * 
 * Created on 15 de mayo de 2018, 14:09
 */

#include "Juego.h"
#include "Mundo.h"
#include "config.h"
#include "MainMenuState.h"
#include "GameOverState.h"
#include "MutationsState.h"
#include "WinState.h"
#include "NoRadsState.h"



Juego* Juego::pinstance = 0;

Juego* Juego::Instance() {
    if (pinstance == 0) { 
        pinstance = new Juego;
    } 
    
    return pinstance;
}

Juego::Juego(){    
    alive = true;
    menu =0;
    pausa=false;
    pj.iniciarPersonaje();
    estadoJuego = MainMenuState::Instance();
    muerto=false;    
   
 }

void Juego::cambiarMenu(int num){
    menu = num;
}


bool Juego::getMuerto(){
    return muerto;
}
void Juego::setMuerto(bool var){
    muerto = var;
}
void Juego::inicializar(){
    Motor_2D* motor = Motor_2D::Instance(); 
        
    while(motor->getWindow()->isOpen()){  
       
        estadoJuego->HandleInput();       
        motor->getVistaPrincipal()->setCenter(0,0);
        motor->setVistaPrincipal();
        motor->getWindow()->clear(); 
         estadoJuego->Draw();
        motor->getWindow()->display();
       
     }
    }
   // if(state ==1){
        
      //motor->draw(fondo);
   // }
      
    


