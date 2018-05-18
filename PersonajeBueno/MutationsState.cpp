/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutationsState.cpp
 * Author: natalia
 * 
 * Created on 17 de mayo de 2018, 12:30
 */

#include "MutationsState.h"
#include "Mi_Texto.h"
#include "Motor_2D.h"
#include "Juego.h"
#include "Mundo.h"

MutationsState* MutationsState::pinstance = 0;

MutationsState* MutationsState::Instance() {
    if (pinstance == 0) { 
        pinstance = new MutationsState;
    } 
    
    return pinstance;
}
void MutationsState::Init(){
    
}
MutationsState::MutationsState() {
    background.setTex("mutacion1.jpg");
    background.setParams(0,0,448,700,0,0);
    activo = false;
    estado=0;
    op=0;       
    puntos=0;
    ss<<puntos;  
    texto.setParams(ss.str(),30,140,-120);
    texto.setColor(sf::Color::Black);
}

void MutationsState::HandleInput(){   
    std::stringstream ss;
    ss<<puntos;
    texto.setText(ss.str());
    sf::Event event;    
    Motor_2D* motor = Motor_2D::Instance();
    Juego* juego = Juego::Instance();
     Mundo* mundo = Mundo::Instance();
    activo = true;
     while (motor->getWindow()->pollEvent(event)&& activo)
     {     if(op==3){
             op=0;
            }
            if(op==-1){
                op=2;
            }
            switch(event.type){
                case sf::Event::Closed:
                    motor->getWindow()->close();
                    break;             
                case sf::Event::KeyPressed:  
                    switch(event.key.code) {
                        case sf::Keyboard::Left:
                            Update(op-1);
                            break;
                        case sf::Keyboard::Right:
                            Update(op+1);
                            break;
                        case sf::Keyboard::Return:
                            if(op == 0){
                                juego->pj.inmunidad();                                
                            }else if(op==1){
                                cout<<"entro en slowwwwwwwwwwwwwwww"<<"\n";
                                juego->pj.slow();
                                
                            }
                            else if(op==2){
                                cout<<"entro en radsx2"<<"\n";
                                juego->pj.porDos();
                            }
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
void MutationsState::Update(int num){
    
    if(num == 0){
        op=0;
        background.setTex("mutacion1.jpg"); 
    }
    else if(num==1){
        op=1;
        background.setTex("mutacion2.jpg"); 
    }
    else if(num==2){
        op=2;
         background.setTex("mutacion3.jpg"); 
    }        
}

void MutationsState::Update(string menu){
    Juego* juego = Juego::Instance();
    if(menu=="home"){
        juego->cambiarMenu(0);
    }
   
}

void MutationsState::Draw(){
    background.draw();
    texto.draw();
}



