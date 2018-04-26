/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pato-lt
 *
 * Created on 17 de abril de 2018, 13:36
 */
#include "config.h"
#include "State.h"
#include "Personaje.h"
#include "mapa.h"
#include "Npc.h"
#include "Mi_Sprite.h"
#include "Motor_2D.h"
/*
 * 
 */
void update( State &_pj_S ,float timeElapsed, Personaje &_pj, State &_npc_S, Npc5 &npc5);
void render_interpolation(sf::RenderWindow &_window, State _pj_S, float _percentTick, Personaje &_pj, State _npc_S, Npc5 &_npc5);
float minimo(float,float);

void update(State &_pj_S ,float timeElapsed, Personaje &_pj, State &_npc_S, Npc5 &_npc5){
    /*
    int posx = _lastState.getPosx() + (kVel*timeElapsed + 0.5f);
    int posy = _lastState.getPosy() + (kVel*timeElapsed + 0.5f);
    */
    
    //AQUI ES DONDE TENEMOS QUE LLAMAR A LAS FUNCIONES DE MOVIMIENTO DE LOS OBJETOS PARA ACTUALIZAR SU RECORRIDO
    _pj.mover(timeElapsed);
    _npc5.movimiento(_pj);
    //ACTUALIZAR EL NEWSTATE DE CADA OBJETO
    /*
    _newState.setPosx(posx);
    _newState.setPosy(posy);
    */
    
    _pj_S.setPosx(_pj.getSprite().getPosx());
    _pj_S.setPosy(_pj.getSprite().getPosy());
    
    _npc_S.setPosx(_npc5.getSprite().getPosx());
    _npc_S.setPosy(_npc5.getSprite().getPosy());
}

void render_interpolation(sf::RenderWindow &_window, State _pj_S, float _percentTick, Personaje &_pj, State _npc_S, Npc5 &_npc5){
    
    //CALCULAMOS LA POSICION INTERPOLADA PARA CUANDO NO SE EJECUTA EL UDPATE
  
    float posxf = _pj_S.getLastx()*(1.f-_percentTick) + _pj_S.getPosx() * _percentTick;
    float posyf = _pj_S.getLasty()*(1.f-_percentTick) + _pj_S.getPosy() * _percentTick;
   

    //float posxf = _pj_S.getLastx()*(1-_percentTick) + _pj_S.getPosx() * _percentTick;
    //float posyf = _pj_S.getLasty()*(1-_percentTick) + _pj_S.getPosy() * _percentTick;
    
    float posxnpc =_npc_S.getLastx()*(1-_percentTick) + _npc_S.getPosx() * _percentTick;
    float posynpc =_npc_S.getLasty()*(1-_percentTick) + _npc_S.getPosy() * _percentTick;
    /*
    int posx = _lastState.getPosx()*(1-_percentTick) + _newState.getPosx() * _percentTick;
    int posy = _lastState.getPosy()*(1-_percentTick) + _newState.getPosy() * _percentTick;
    
    _pj.setPosition(posx,posy);
     */
    _pj.setPosition(posxf,posyf);
    _npc5.setPosition(posxnpc , posynpc );
    _pj.actualizarBoxes();
    
    //cout << "pj posx: " << _pj.getSprite().getPosition().x << " posy: " << _pj.getSprite().getPosition().y << "\n";
    
    
    //DIBUJAMOS
    _pj.draw();
    _npc5.draw();
    
    _window.draw(_pj.getBoxAbajo());
    _window.draw(_pj.getBoxArriba());
    _window.draw(_pj.getBoxDerecha());
    _window.draw(_pj.getBoxIzquierda());
   
    
}
float minimo(float a, float b){
    float res;
    if (b < a ){
        res = b;
    }
    if (a <= b ){
        res = a;
    }
    return res;
}

int main() {   
    Motor_2D* motor = Motor_2D::Instance();
    //MAPA Y CAMARA
    Mapa* map = Mapa::Instance();
 
    int tiles =map->getAltura() * 32;
    
    sf::View view(sf::FloatRect(0, tiles, 448, 700));
    
    
    
    //Relojes de control de tiempo entre cada update y el tiempo global
    sf::Clock updateClock;
    sf::Clock globalClock;
    
    //INICIALIZAR OBJETOS
    
    Personaje pj;
    Npc5 npc5(200,10800);
    //INICIALIZAR VARIABLES
    
    float tiempo_update;
    float update_tick_time = UPDATE_TICK_TIME;
    float division;     //
    float percentTick;
    sf::Time timeElapsed = sf::seconds(0);
    
    bool firstTime = true;
    
    
    //ESTADOS    
    State pj_S(pj.getSprite().getPosx(),pj.getSprite().getPosy());
    
    State npc_S(npc5.getSprite().getPosx(),npc5.getSprite().getPosy());

    /*
     
    Personaje pj_ls();
    Personaje pj_ls();
    */
    
    while(motor->getWindow()->isOpen()){
        sf::Event event;
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
                        case sf::Keyboard::Space:
                           //if(p.getEspacios() <2){
                           pj.moverSalto(); 
                           
                          
                        break;
                        //Tecla ESC para salir
                        case sf::Keyboard::Q:
                            motor->getWindow()->close();
                        break;
                              
                    }

            }
            
            
        }
        //AJUSTAR VISTA A LA POSICION DEL PERSONAJE
        view.setCenter(224,pj.getSprite().getPosy()-64);
        
        //INTERPOLACION
        
        //El update es una funcion que se ejecuta solo 15veces por segundo
        if(updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){

            pj_S.setPosx(pj_S.getPosx());
            pj_S.setPosy(pj_S.getPosy());
            
            npc_S.setPosx(npc_S.getPosx());
            npc_S.setPosy(npc_S.getPosy());
            
            timeElapsed = updateClock.restart();

            update(pj_S,timeElapsed.asMilliseconds(),pj,npc_S,npc5);

           // update(pj_S,timeElapsed.asSeconds(),pj,npc_S,npc5);

            
        }
        
        tiempo_update = (float)updateClock.getElapsedTime().asMilliseconds();
        division = tiempo_update / update_tick_time;
        
        percentTick = minimo(1.f,division);
        
        //RENDERIZAMOS TODO
        motor->getWindow()->clear();
        
        
        motor->getWindow()->setView(view);
               
        sf::Sprite img_fondo = map->getFondo();
        img_fondo.setPosition(0,view.getCenter().y-400);
        motor->getWindow()->draw(img_fondo);
        
        map->activarCapa(3);
        motor->getWindow()->draw(*map);
        render_interpolation(*motor->getWindow(),pj_S,percentTick,pj,npc_S,npc5);
        
        motor->getWindow()->display();
    }   
    return 0;
}

