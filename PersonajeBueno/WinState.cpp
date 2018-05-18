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

#include "WinState.h"
#include "Estado.h"
#include "Motor_2D.h"
#include "Juego.h"
#include "Mi_Texto.h"
#include "config.h"


WinState* WinState::pinstance = 0;

WinState* WinState::Instance() {
    if (pinstance == 0) { 
        pinstance = new WinState;
    } 
    
    return pinstance;
}

void WinState::Init(){
    
}
WinState::WinState() {
    background.setTex("fin.jpg");
    background.setParams(0,0,448,700,0,0);
    activo = false;
    estado=0;
}

void WinState::HandleInput(){    
    sf::Event event;    
    Motor_2D* motor = Motor_2D::Instance();
    Juego* juego = Juego::Instance();
    std::stringstream ss;
    ss<<juego->pj.getVidas();   
    
     reloj.setParams(juego->pj.reloj, 25, -20, 205);
     reloj.setColor(sf::Color::White);    
     vidas.setParams(ss.str(), 25, -20, 290);
    // vidas.setText()
    activo = true;
     while (motor->getWindow()->pollEvent(event)&& activo)
        {            
            switch(event.type){
                case sf::Event::Closed:
                    motor->getWindow()->close();
                    break;             
                case sf::Event::KeyPressed:  
                    switch(event.key.code) {                           
                        case sf::Keyboard::Left:
                            Update(1);
                            break;
                        case sf::Keyboard::Right:
                            Update(0);
                            break;
                        case sf::Keyboard::Return: 
                            if(estado == 1){
                                Update("jugar");
                            }
                            else if(estado == 0){
                                Update("home");
                            }
                           
                            break;
                        case sf::Keyboard::Q:
                            motor->getWindow()->close();
                        break;
                              
                    }

            }
            
            
     
     }

}

void WinState::Update(int num){
    if(num == 0){
        background.setTex("again.jpeg");        
        estado = 1;
    }
    else if(num==1){
        background.setTex("atras.jpeg");
        estado =0;
    }
   
        
}

void WinState::Update(string menu){
    Juego* juego = Juego::Instance();
    if(menu=="home"){
        cout<<"entro home"<<"\n";
        juego->estadoJuego = MainMenuState::Instance(); 
    }
    else if(menu == "muerte"){
        activo == false;
        //juego->cambiarMenu(1);
    }
    else if(menu=="jugar"){
        juego->cambiarMenu(1);
        ingame.iniciarPartida(); 
        activo=false;
    }
}

void WinState::Draw(){
    background.draw();
    reloj.draw();
    vidas.draw();
}

