/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameOverState.cpp
 * Author: natalia
 * 
 * Created on 16 de mayo de 2018, 21:06
 */

#include "GameOverState.h"
#include "config.h"
#include "Motor_2D.h"
#include "Juego.h"

GameOverState* GameOverState::pinstance = 0;

GameOverState* GameOverState::Instance() {
    if (pinstance == 0) { 
        pinstance = new GameOverState;
    } 
    
    return pinstance;
}

void GameOverState::Init(){
    
}
GameOverState::GameOverState() {
    background.setTex("again.jpeg");
    background.setParams(0,0,448,700,0,0);
    activo = false;
    estado=0;
}

void GameOverState::HandleInput(){
    sf::Event event;    
    Motor_2D* motor = Motor_2D::Instance();
    Juego* juego = Juego::Instance();
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

void GameOverState::Update(int num){
    if(num == 0){
        background.setTex("again.jpeg");        
        estado = 1;
    }
    else if(num==1){
        background.setTex("atras.jpeg");
        estado =0;
    }
   
        
}

void GameOverState::Update(string menu){
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
        ingame.iniciarPartida(); 
        activo=false;
        juego->cambiarMenu(1);
    }
}

void GameOverState::Draw(){
    background.draw();
}

