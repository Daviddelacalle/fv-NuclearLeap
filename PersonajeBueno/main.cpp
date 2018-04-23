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

/*
 * 
 */
void update( State &_newState ,float timeElapsed, Personaje &_pj, State &_npc_newState, Npc5 &npc5);
void render_interpolation(sf::RenderWindow &_window, State _lastState, State _newState, float _percentTick, Personaje &_pj, State _lastStatenpc, State _newStatenpc, Npc5 &npc5);
float minimo(float,float);

void update(State &_pj_newState ,float timeElapsed, Personaje &_pj, State &_npc_newState, Npc5 &_npc5){
    /*
    int posx = _lastState.getPosx() + (kVel*timeElapsed + 0.5f);
    int posy = _lastState.getPosy() + (kVel*timeElapsed + 0.5f);
    */
    
    //AQUI ES DONDE TENEMOS QUE LLAMAR A LAS FUNCIONES DE MOVIMIENTO DE LOS OBJETOS PARA ACTUALIZAR SU RECORRIDO
    _pj.mover();
    _npc5.movimiento(_pj);
    //ACTUALIZAR EL NEWSTATE DE CADA OBJETO
    /*
    _newState.setPosx(posx);
    _newState.setPosy(posy);
    */
    _pj_newState.setPosx(_pj.getSprite().getPosition().x);
    _pj_newState.setPosy(_pj.getSprite().getPosition().y);
    
    _npc_newState.setPosx(_npc5.getSprite().getPosition().x);
    _npc_newState.setPosy(_npc5.getSprite().getPosition().y);
}

void render_interpolation(sf::RenderWindow &_window, State _lastStatepj, State _newStatepj, float _percentTick, Personaje &_pj, State _lastStatenpc, State _newStatenpc, Npc5 &_npc5){
    
    //CALCULAMOS LA POSICION INTERPOLADA PARA CUANDO NO SE EJECUTA EL UDPATE
    
    float posxf = _lastStatepj.getPosx()*(1-_percentTick) + _newStatepj.getPosx() * _percentTick;
    float posyf = _lastStatepj.getPosy()*(1-_percentTick) + _newStatepj.getPosy() * _percentTick;
    
    float posxnpc =_lastStatenpc.getPosx()*(1-_percentTick) + _newStatenpc.getPosx() * _percentTick;
    float posynpc =_lastStatenpc.getPosy()*(1-_percentTick) + _newStatenpc.getPosy() * _percentTick;
    /*
    int posx = _lastState.getPosx()*(1-_percentTick) + _newState.getPosx() * _percentTick;
    int posy = _lastState.getPosy()*(1-_percentTick) + _newState.getPosy() * _percentTick;
    
    _pj.setPosition(posx,posy);
     */
    
    _pj.setPosition(int(posxf + 0.5),int(posyf + 0.5));
    _npc5.setPosition(int(posxnpc +0.5), int(posynpc + 0.5));
    
    //cout << "pj posx: " << _pj.getSprite().getPosition().x << " posy: " << _pj.getSprite().getPosition().y << "\n";
    
    
    //DIBUJAMOS
    _window.draw(_pj.getSprite());
    _window.draw(_npc5.getSprite());
   
    
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
    sf::RenderWindow window(sf::VideoMode(448,700),"PersonajeBueno");
    
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
    
    State pj_newState(pj.getSprite().getPosition().x,pj.getSprite().getPosition().y);
    State pj_lastState(pj.getSprite().getPosition().x,pj.getSprite().getPosition().y); 
    
    State npc_newState(npc5.getSprite().getPosition().x,npc5.getSprite().getPosition().y);
    State npc_lastState(npc5.getSprite().getPosition().x,npc5.getSprite().getPosition().y);

    /*
     
    Personaje pj_ls();
    Personaje pj_ls();
    */
    
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
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
                            window.close();
                        break;
                              
                    }

            }
            
            
        }
        //AJUSTAR VISTA A LA POSICION DEL PERSONAJE
        view.setCenter(224,pj.getSprite().getPosition().y-64);
        
        //INTERPOLACION
        
        //El update es una funcion que se ejecuta solo 15veces por segundo
        if(updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
            pj_lastState.setPosx(pj_newState.getPosx());
            pj_lastState.setPosy(pj_newState.getPosy());
            
            npc_lastState.setPosx(npc_newState.getPosx());
            npc_lastState.setPosy(npc_newState.getPosy());
            
            timeElapsed = updateClock.restart();
            update(pj_newState,timeElapsed.asSeconds(),pj,npc_newState,npc5);
            
        }
        
        tiempo_update = (float)updateClock.getElapsedTime().asMilliseconds();
        division = tiempo_update / update_tick_time;
        
        percentTick = minimo(1.f,division);
        
        //RENDERIZAMOS TODO
        window.clear();
        
        
        window.setView(view);
               
        sf::Sprite img_fondo = map->getFondo();
        img_fondo.setPosition(0,view.getCenter().y-400);
        window.draw(img_fondo);
        
        map->activarCapa(3);
        window.draw(*map);
        render_interpolation(window,pj_lastState,pj_newState,percentTick,pj,npc_lastState,npc_newState,npc5);
        
        window.display();
    }   
    return 0;
}

