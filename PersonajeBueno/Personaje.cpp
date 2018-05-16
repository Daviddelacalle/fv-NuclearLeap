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

        
   
    alturasuelo = Mapa::Instance()->getAltura()*32 - 32*9.5;
    alturasuelo_nueva = Mapa::Instance()->getAltura()*32 - 32*9.5;
    sprite.setParams(0,2,32,32,200,alturasuelo);
  
    
    boxAbajo = sf::RectangleShape(sf::Vector2f(24,8));
    boxAbajo.setOrigin(12,4);
    boxAbajo.setPosition(320, 630);
    boxAbajo.setFillColor(sf::Color::Red);
        
    
    boxArriba = sf::RectangleShape(sf::Vector2f(24,8));
    boxArriba.setOrigin(12,4);
    boxArriba.setPosition(320, 630);
    boxArriba.setFillColor(sf::Color::Blue);
    
    boxDerecha = sf::RectangleShape(sf::Vector2f(10,8));
    boxDerecha.setOrigin(5,4);
    boxDerecha.rotate(90);
    boxDerecha.setPosition(320, 630);
    boxDerecha.setFillColor(sf::Color::Green);
    
    boxIzquierda = sf::RectangleShape(sf::Vector2f(10,8));
    boxIzquierda.setOrigin(5,4);
    boxIzquierda.rotate(90);
    boxIzquierda.setPosition(320, 630);
    boxIzquierda.setFillColor(sf::Color::Yellow);
    
    //Y creo el spritesheet a partir de la imagen anterior
    
    posx = sprite.getPosx();
    posy = sprite.getPosy();
    
    
    direccion = 1;  
    dir_aux = direccion;
    check_pared = false;
    
    gravedad = kGrav;
    
    espacio = 0;
    velocidadsalto = 0.8;
    nsprite = 0;
    max_sprites = 6;
    velocidad.x = kVel;
    contEspacios=0;
    var1 = 0;
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

void Personaje::gravity(float timeElapsed){
     if(sprite.getPosy() + sprite.getScaley() < alturasuelo || velocidad.y < 0) {
        velocidad.y += gravedad*timeElapsed;
      }
      else {
        sprite.setPosition(sprite.getPosx(), alturasuelo - sprite.getScaley());
        posx = sprite.getPosx();
        posy = sprite.getPosy();
        velocidad.y = 0;
        espacio=0;
        gravedad = kGrav;
        
      }
     
}

void Personaje::moverSalto(){    
    if(espacio <2){
      velocidad.y = -velocidadsalto;         
      espacio++;
      gravedad= kGrav;
    }
    
     int var1 = contEspacios;
}

void Personaje::mover(float timeElapsed){

    Mapa* map = Mapa::Instance();
    
    vector<sf::RectangleShape> paredes = map->getPared();
    vector<sf::RectangleShape> bloques = map->getBloques();
    vector<sf::RectangleShape> suelo = map->getSuelo();

    
    for(int i = 0 ; i < paredes.size(); i++){
        sf::RectangleShape aux_paredes = paredes[i];
        if(boxDerecha.getGlobalBounds().intersects(aux_paredes.getGlobalBounds())){
            
            direccion = -1;
            sprite.setScale(-1.0f, 1.0f);
        }
        if(boxIzquierda.getGlobalBounds().intersects(aux_paredes.getGlobalBounds())){
            direccion = 1;
            sprite.setScale(1.0f, 1.0f);
        }
    }
    
    
    bool cabezazo = false;
    for(int i = 0; i < bloques.size() ; i++){
        sf::RectangleShape aux_bloques = bloques[i];
        
        if(boxArriba.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            velocidad.y = 0.2;
            cabezazo = true;
        }
        
        if(boxAbajo.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
            if(estoy_volando == true){
                alturasuelo = boxAbajo.getPosition().y - 6;
                estoy_volando = false;
            }
            
        }
        else{
            estoy_volando = true;
        }
        
        if (cabezazo == false){
            if(boxDerecha.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
                direccion = -1;
                sprite.setScale(-1.0f, 1.0f);
            }

            if(boxIzquierda.getGlobalBounds().intersects(aux_bloques.getGlobalBounds())){
                direccion = 1;
                sprite.setScale(1.0f, 1.0f);
            }
        }

        
    }
        
    
    //cuando el box abajo ha decidido que tenia suelo debajo ha cambiado estoy_tierra a 

        
    gravity(timeElapsed);
    
    if(pierdo == false){
        sprite.move(velocidad.x * direccion*timeElapsed, velocidad.y*timeElapsed);
    }
    
}

int Personaje::getEspacios(){
    return espacio;
}


void Personaje::actualizarSprite(){
    
   
    if(pierdo == false){
        if(sprite.get_clockElapsedTime() > 50){
        if(check_pared == false){
            if(nsprite == max_sprites){
                nsprite = 0;
            }
            sprite.setFrame(nsprite,2); // dos porque es la fila 2
            nsprite++;    
        sprite.restartClock();
    }
    //actualizo la pos de las vidas   
   }
    }
}



void Personaje::cambiarPosicion(int num, int num2){
    sprite.setPosition(num, num2);
}

void Personaje::estoyRoja(int y){
        alturasuelo =y-15;
        velocidad.x = kVel*2;
}
    void Personaje::estoyAzul(int y){
       alturasuelo = y-15;
         velocidad.x = kVel;
    }
    void Personaje::estoyPortalIda(float x, float y){
        sprite.setPosition(x,y);
        
    }
    void Personaje::estoyPortalVuelta(float x, float y){
        
    }
    void Personaje::estoySaltador(){
        moverSalto();
    }
    
    void Personaje::estoyNormal(){
       alturasuelo = alturasuelo_nueva;
        velocidad.x = kVel;
    }
    
    sf::RectangleShape Personaje::getBoxAbajo(){
        return boxAbajo;
        
    }

    void Personaje::setPosition(float _x, float _y){
        sprite.setPosition(_x,_y);
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
        alturasuelo=checkpoint;
        alturasuelo_nueva = checkpoint;
        sprite.setPosition(200, alturasuelo);
        vidas--;
        actualizarVidas();
        if(vidas==0){       
            pierdo = true;
            text_perder.setPosition(30, sprite.getPosy()-30);
        }
     }
     
