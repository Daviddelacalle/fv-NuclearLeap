/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: pato-lt
 * 
 * Created on 19 de abril de 2018, 13:54
 */
#include "SFML/Audio.hpp"
#include "Personaje.h"
#include "mapa.h"
#include "Mi_Texto.h"
#include "Motor_2D.h"


Personaje::Personaje(){

        
    Mapa* map = Mapa::Instance();
    
    pos_inicial = map->getAltura()*32 - 32*9.5;
    posx = 200.f;
    posy = pos_inicial;
    sprite.setParams(0,2,32,32,posx,posy);
  
    direccion = 1;
    dir_aux = 1;
    vel_y = 0;
    estoy_suelo = true;
    estoy_pared = false;
    n_saltos = 0;
    
    boxAbajo = sf::RectangleShape(sf::Vector2f(24,8));
    boxAbajo.setOrigin(12,4);
    boxAbajo.setPosition(320, 630);
    boxAbajo.setFillColor(sf::Color::Red);
        
    
    boxArriba = sf::RectangleShape(sf::Vector2f(24,8));
    boxArriba.setOrigin(12,4);
    boxArriba.setPosition(320, 630);
    boxArriba.setFillColor(sf::Color::Blue);
    
    boxDerecha = sf::RectangleShape(sf::Vector2f(16,8));
    boxDerecha.setOrigin(8,4);
    boxDerecha.rotate(90);
    boxDerecha.setPosition(320, 630);
    boxDerecha.setFillColor(sf::Color::Green);
    
    boxIzquierda = sf::RectangleShape(sf::Vector2f(16,8));
    boxIzquierda.setOrigin(8,4);
    boxIzquierda.rotate(90);
    boxIzquierda.setPosition(320, 630);
    boxIzquierda.setFillColor(sf::Color::Yellow);
    
    //Y creo el spritesheet a partir de la imagen anterior

    nsprite = 0;
    max_sprites = 6;

    checkpoint== Mapa::Instance()->getAltura()*32 - 32*9.5;
    pierdo = false;
    puntuacion = 0;
    
    std::stringstream ss;
    vidas = 5;
    ss<<vidas;
    posx_vida = 60;
    posy_vida= posy +200;
    
    text_vidas.setParams(ss.str(), 13, posx_vida,posy_vida);
    text_puntuacion.setParams('0',13, posx_vida +40, posy_vida);
    sprite_vidas.setParams(4,0,32,32, posx_vida+15,posy_vida+3);
    sprite_vidas.setScale(1.5,1.5);
    
     
    text_perder.setParams("HAS PERDIDO", 30, 0, 0);
    
    
   // sprite.setPosition(224, alturasuelo);
}



Mi_Sprite Personaje::getSprite(){
   return sprite;   
}

void Personaje::moverSalto(){   
    n_saltos ++;
    
    if(n_saltos < 3){
        vel_y = -kVel_y;
        estoy_suelo = false;    
    }
    
}

void Personaje::mover(float timeElapsed){

    Mapa* map = Mapa::Instance();
    
    vector<sf::RectangleShape> paredes = map->getPared();
    vector<sf::RectangleShape> bloques = map->getBloques();
    vector<sf::RectangleShape> suelos = map->getSuelo();
    vector<sf::RectangleShape> checkpoints = map->getCheckpoint();
    
    for(int i = 0 ; i < paredes.size() ;  i++){
        sf::RectangleShape aux_paredes = paredes[i];
        
        if(boxDerecha.getGlobalBounds().intersects(aux_paredes.getGlobalBounds())){
            dir_aux = -1;
            //TOCO CON LA PARED 
            if(estoy_suelo == true){//SI ESTOY EN EL SUELO, CAMBIO LA DIRECCION Y SALGO DE LA PARED
                direccion = -1;
                sprite.setScale(-1.0f,1.0f);
            }
            else{//SINO ESTOY EN EL SUELO ENTONCES TOCA DESLIZAR
                if(direccion != 0){//ESTO DICE QUE SI LLEGO Y ES LA PRIMERA VEZ QUE TOCO LA PARED
                    //DIRECCION ES 0 PARA K NO SE MUEVA
                    direccion = 0;
                    sprite.setScale(-1.0f,1.0f); 
                    n_saltos = 0;
                    estoy_pared = true;
                    if(vel_y < -0.1){ vel_y = -0.1;}
                }
                //SI ESTOY TOCANDO LA PARED PERO YA ESTABA DE ANTES
                else{ if(n_saltos > 0){ direccion = -1; } }//SI PULSAN EL BOTON DE SALTAR SALTO   
            }
            
        }
        if(boxIzquierda.getGlobalBounds().intersects(aux_paredes.getGlobalBounds())){
            dir_aux = 1;
            //TOCO CON LA PARED 
            if(estoy_suelo == true){//SI ESTOY EN EL SUELO, CAMBIO LA DIRECCION Y SALGO DE LA PARED
                direccion = 1;
                sprite.setScale(1.0f,1.0f);
            }
            else{//SINO ESTOY EN EL SUELO ENTONCES TOCA DESLIZAR
                if(direccion != 0){//ESTO DICE QUE SI LLEGO Y ES LA PRIMERA VEZ QUE TOCO LA PARED
                    //DIRECCION ES 0 PARA K NO SE MUEVA
                    direccion = 0;
                    sprite.setScale(1.0f,1.0f); 
                    n_saltos = 0;
                    if(vel_y < -0.1){ vel_y = -0.1;}
                    estoy_pared = true;
                }
                //SI ESTOY TOCANDO LA PARED PERO YA ESTABA DE ANTES
                else{ if(n_saltos > 0){ direccion = 1; } }//SI PULSAN EL BOTON DE SALTAR SALTO   
            }
        }
    }
    
    for(int i = 0 ; i <bloques.size() ;  i++){
        sf::RectangleShape aux_bloques = bloques[i];
        
        if(boxDerecha.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            dir_aux = -1;
            //TOCO CON LA PARED 
            if(estoy_suelo == true){//SI ESTOY EN EL SUELO, CAMBIO LA DIRECCION Y SALGO DE LA PARED
                direccion = -1;
                sprite.setScale(-1.0f,1.0f);
            }
            else{//SINO ESTOY EN EL SUELO ENTONCES TOCA DESLIZAR
                if(direccion != 0){//ESTO DICE QUE SI LLEGO Y ES LA PRIMERA VEZ QUE TOCO LA PARED
                    //DIRECCION ES 0 PARA K NO SE MUEVA
                    direccion = 0;
                    sprite.setScale(-1.0f,1.0f); 
                    n_saltos = 0;
                    if(vel_y < -0.1){ vel_y = -0.1;}
                    estoy_pared = true;
                }
                //SI ESTOY TOCANDO LA PARED PERO YA ESTABA DE ANTES
                else{ if(n_saltos > 0){ direccion = -1; } }//SI PULSAN EL BOTON DE SALTAR SALTO   
            }
        }
        
        if(boxIzquierda.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            dir_aux = 1;
            //TOCO CON LA PARED 
            if(estoy_suelo == true){//SI ESTOY EN EL SUELO, CAMBIO LA DIRECCION Y SALGO DE LA PARED
                direccion = 1;
                sprite.setScale(1.0f,1.0f);
            }
            else{//SINO ESTOY EN EL SUELO ENTONCES TOCA DESLIZAR
                if(direccion != 0){//ESTO DICE QUE SI LLEGO Y ES LA PRIMERA VEZ QUE TOCO LA PARED
                    //DIRECCION ES 0 PARA K NO SE MUEVA
                    direccion = 0;
                    sprite.setScale(1.0f,1.0f); 
                    n_saltos = 0;
                    if(vel_y < -0.1){ vel_y = -0.1;}
                    estoy_pared = true;
                }
                //SI ESTOY TOCANDO LA PARED PERO YA ESTABA DE ANTES
                else{ if(n_saltos > 0){ direccion = 1;} }//SI PULSAN EL BOTON DE SALTAR SALTO   
            }
        }
        //else{if(direccion == 0){direccion = 1;}}
        
        if(boxAbajo.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            if(vel_y >= 0){ 
                cout << "toco suelo \n"; 
                estoy_suelo = true;
                n_saltos = 0;
                posy = aux_bloques.getPosition().y -16;
            }
            break;
        }
        else{
            estoy_suelo = false;
            
        }
        
        if(boxArriba.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            
            vel_y = 0.05;
            posy = posy + kVel_y;
        }
    }
    
    
    
    for(int i = 0; i < suelos.size(); i++){
        sf::RectangleShape aux_suelos = suelos[i];
        if(boxAbajo.getGlobalBounds().intersects(aux_suelos.getGlobalBounds())){
            if(vel_y >= 0){ 
                estoy_suelo = true;
                n_saltos = 0;
                posy = aux_suelos.getPosition().y -16;
            }
            
        }
    }
    
    for(int i = 0; i < checkpoints.size(); i++){
        sf::RectangleShape aux_checkpoints =  checkpoints[i];
        if(boxAbajo.getGlobalBounds().intersects(aux_checkpoints.getGlobalBounds())){
            if(vel_y >= 0){ 
                estoy_suelo = true;
                n_saltos = 0;
                posy = aux_checkpoints.getPosition().y -16;
            }
            
        }
    }
    cout << "estoy_suelo: " <<estoy_suelo << "\n";
    
    if(estoy_suelo == true){
        direccion = dir_aux;
    }
    
    if(estoy_pared == true){
        if(n_saltos > 0){ direccion = dir_aux;}
    }
    
    gravity(timeElapsed);
    
    cout << "vel_y: " <<vel_y << "\n";
    posx = posx + kVel * direccion*timeElapsed;
    posy = posy + vel_y*timeElapsed;

    
    
    sprite.setPosition(posx,posy);
    
    
}

void Personaje::gravity(float timeElapsed){
    float g = kGrav;
    
    if(!estoy_suelo){
        vel_y = vel_y + g*timeElapsed;
        posy = posy + vel_y;
    }
    else{
        vel_y = 0;
    }
}

void Personaje::actualizarSprite(){
    if(pierdo == false){
        if(sprite.get_clockElapsedTime() > 50){
            if(nsprite == max_sprites){
                nsprite = 0;
            }
            sprite.setFrame(nsprite,2); // dos porque es la fila 2
            nsprite++;    
            sprite.restartClock();
        
    //actualizo la pos de las vidas   
        }
   }
}



void Personaje::cambiarPosicion(int num, int num2){
    sprite.setPosition(num, num2);
}


void Personaje::estoyPortalIda(float x, float y){
    sprite.setPosition(x,y);
        
}
void Personaje::estoyPortalVuelta(float x, float y){
        
}

sf::RectangleShape Personaje::getBoxAbajo(){
    return boxAbajo;
        
}

void Personaje::setPosition(float _x, float _y){
    posx = _x;
    posy = _y;
    sprite.setPosition(posx,posy);
}
    
void Personaje::actualizarBoxes(){
    boxAbajo.setPosition(sprite.getPosx(), sprite.getPosy()+20);
    boxArriba.setPosition(sprite.getPosx(),sprite.getPosy()-12);
    boxDerecha.setPosition(sprite.getPosx()+12, sprite.getPosy());
    boxIzquierda.setPosition(sprite.getPosx()-12, sprite.getPosy());
}
     
   
    
    sf::RectangleShape Personaje::getBoxArriba(){
        return boxArriba;  
    }
    
    sf::RectangleShape Personaje::getBoxDerecha(){
        return boxDerecha;  
    }
    
    sf::RectangleShape Personaje::getBoxIzquierda(){
        return boxIzquierda;  
    }
    
    void Personaje::draw(){
        sprite.draw();
        sprite_vidas.draw();
        text_vidas.draw();
        text_puntuacion.draw();
        if(pierdo ==true){
            text_perder.draw();
        }
        
    }
    
     void Personaje::update(float timeElapsed){    
        Mapa* map = Mapa::Instance(); 
        mover(timeElapsed);      
        actualizarSprite();
        map->recogerRads(sprite,puntuacion);
        actualizarPuntuacion();
        if(posy < map->getAltZonas(1))
            map->setFondo(1);
        
     }
     
     void Personaje::setPosVidas(){
        Motor_2D* motor = Motor_2D::Instance();
        text_vidas.setPosition(posx_vida -7 ,motor->getVistaPrincipal()->getCenter().y -330);  
        sprite_vidas.setPosition(posx_vida,motor->getVistaPrincipal()->getCenter().y-327); 
        text_puntuacion.setPosition(posx_vida - 50, motor->getVistaPrincipal()->getCenter().y -330);
     }  
     
     void Personaje::actualizarVidas(){
         std::stringstream ss;
         ss<<vidas;
         text_vidas.setText(ss.str());
         
     }
     
     void Personaje::actualizarPuntuacion(){
         std::stringstream ss;
         ss<<puntuacion;
         text_puntuacion.setText(ss.str());
         
     }

void Personaje::morir(){
    sprite.setPosition(200, pos_inicial);
    vidas--;
    actualizarVidas();
    if(vidas==0){       
        pierdo = true;
        text_perder.setPosition(30, sprite.getPosy()-30);
    }
}
     
