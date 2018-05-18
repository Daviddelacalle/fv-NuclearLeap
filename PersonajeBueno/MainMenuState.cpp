/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuState.cpp
 * Author: natalia
 * 
 * Created on 16 de mayo de 2018, 15:53
 */

#include "MainMenuState.h"
#include "Mi_Sprite.h"
#include "Juego.h"
#include "Motor_2D.h"


MainMenuState* MainMenuState::pinstance = 0;

MainMenuState* MainMenuState::Instance() {
    if (pinstance == 0) { 
        pinstance = new MainMenuState;
    } 
    
    return pinstance;
}
void MainMenuState::Init(){
    
}
MainMenuState::MainMenuState() {
    background.setTex("play.jpeg");
    background.setParams(0,0,448,700,0,0);
    activo = false;
    estado=0;
    op=0;
}

void MainMenuState::HandleInput(){
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
                        case sf::Keyboard::Up: 
                            Update(0);
                            break;
                        case sf::Keyboard::Left:
                            Update(1);
                            break;
                        case sf::Keyboard::Right:
                            Update(2);
                            break;
                        case sf::Keyboard::Return: 
                        //    cout<<estado<<"\n";
                            if(estado==0){
                                if(op == 0){
                                    Update("jugar");
                                }
                                else if(op == 2){
                                    Update("info");

                                }
                                else if(op ==1){
                                    Update("opciones");
                                }
                            }
                            else if(estado==2 || estado ==1){
                                if(op==0){
                                    Update(0);
                                }
                            }
                           
                            break;
                        case sf::Keyboard::Q:
                            motor->getWindow()->close();
                        break;
                              
                    }

            }
            
            
     
     }

}
void MainMenuState::Update(int num){
    if(num == 0){
        background.setTex("play.jpeg");
        op =0;
        estado=0;
    }
    else if(num==1){
        background.setTex("opciones.jpeg");
        op=1;
        estado=0;
    }
    else{
         background.setTex("info.jpeg");
         op=2;
         estado=0;
    }        
}

void MainMenuState::Update(string menu){
    Juego* juego = Juego::Instance();
    if(menu=="home"){
        juego->cambiarMenu(0);
    }
    else if(menu == "muerte"){
        activo == false;
        juego->cambiarMenu(0);
        //juego->cambiarMenu(1);
    }
    else if(menu=="jugar"){
        ingame.iniciarPartida();
        activo=false;
        juego->cambiarMenu(1);
    }
    else if(menu=="info"){
        background.setTex("ayuda.png");
        estado = 1;
        op=0;
    }
    else if(menu=="opciones"){
        background.setTex("mutators.png");
        estado = 2;
        op=0;
    }
}

void MainMenuState::Draw(){
    background.draw();
}



