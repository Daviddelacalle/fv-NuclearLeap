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




Juego* Juego::pinstance = 0;

Juego* Juego::Instance() {
    if (pinstance == 0) { 
        pinstance = new Juego;
    } 
    
    return pinstance;
}

Juego::Juego(){    
    alive = true;
   
}
void Juego::cambiarEstado(int num){
    estado = num;
}

void Juego::cambiarMenu(int num){
    menu = num;
}

void Juego::inicializar(){
    Motor_2D* motor = Motor_2D::Instance();
    Mi_Sprite fondo;
    fondo.setParams(0,0,448,700,0,0);
    estado=2;
    menu = 1;    
    //estdo 0 --> salir
    //estado 1 --> menu principal
    //estado 2 --> iniciar juego
    //estado 3 --> muerte  
      
    
    while(motor->getWindow()->isOpen()){
        sf::Event event;
        if(menu==1){//menu principal
            if(estado ==2){//play
                fondo.setTex(2);
            }
            else if(estado ==3){//opciones
                fondo.setTex(3);
            }
           else if(estado ==4){//info
                fondo.setTex(4);
            }            
        }
        else if(menu==2){//muerte
             if(estado ==2){ //restart
                fondo.setTex(5);
            }
             else if(estado ==3){//salir
                fondo.setTex(6);
            }           
        }
        else if(menu==3){//muerte
             if(estado ==1){ //restart
                fondo.setTex(7);
            }
             else  if(estado ==2){ //restart
                fondo.setTex(8);
            }
                      
        }
         
        cout<<"tecla"<<estado<<"\n";
       
        while (motor->getWindow()->pollEvent(event))
        {
            
            switch(event.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    motor->getWindow()->close();
                    break;
                    
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Up:  
                            if(menu==1)
                            estado=2;
                         break;
                        case sf::Keyboard::Left:
                            if(menu==1)
                            estado=3;
                            else if(menu==2)
                            estado=3;
                         break;
                        case sf::Keyboard::Right:
                            if(menu==1)
                            estado=4;
                            else if(menu==2)
                            estado=2;
                         break;
                        case sf::Keyboard::N:
                            if(estado==2 && (menu ==1|| menu==2)){
                                ingame.iniciarPartida(); 
                            } 
                            else if(menu ==2 && estado==3){
                                menu = 1;
                                estado = 2;
                            }
                            else if(menu ==1 && estado==4){
                                menu = 3;
                                estado = 1;
                            }
                            else if(menu ==1 && estado==3){
                                menu = 3;
                                estado = 2;
                            }
                            else if(menu ==3 && estado==1){
                                menu = 1;
                                estado = 2;
                            }
                            else if(menu ==3 && estado==2){
                                menu = 1;
                                estado = 2;
                            }
                            
                            
                            
                         break;
                        case sf::Keyboard::Q:
                            motor->getWindow()->close();
                        break;
                              
                    }

            }
            
            
     
        }
        motor->getVistaPrincipal()->setCenter(0,0);
        motor->setVistaPrincipal();
        motor->getWindow()->clear();      
        
        fondo.draw();
        motor->getWindow()->display();
    }
   // if(state ==1){
        
      //motor->draw(fondo);
   // }
      
    
}

