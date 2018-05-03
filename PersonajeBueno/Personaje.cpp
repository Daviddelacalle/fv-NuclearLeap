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

        
   
            
   sprite.setParams(0,2,32,32,200,10780);
  
    
    boxAbajo = sf::RectangleShape(sf::Vector2f(30,2));
    boxAbajo.setOrigin(15,1);
    boxAbajo.setPosition(320, 630);
    boxAbajo.setFillColor(sf::Color::Red);
        
    
    boxArriba = sf::RectangleShape(sf::Vector2f(30,2));
    boxArriba.setOrigin(15,1);
    boxArriba.setPosition(320, 630);
    boxArriba.setFillColor(sf::Color::Blue);
    
    boxDerecha = sf::RectangleShape(sf::Vector2f(20,2));
    boxDerecha.setOrigin(10,1);
    boxDerecha.rotate(90);
    boxDerecha.setPosition(320, 630);
    boxDerecha.setFillColor(sf::Color::Green);
    
    boxIzquierda = sf::RectangleShape(sf::Vector2f(20,2));
    boxIzquierda.setOrigin(10,1);
    boxIzquierda.rotate(90);
    boxIzquierda.setPosition(320, 630);
    boxIzquierda.setFillColor(sf::Color::Yellow);
    
    //Y creo el spritesheet a partir de la imagen anterior
    
    posx = sprite.getPosx();
    posy = sprite.getPosy();
    
    suelo =true;
    direccion = 1;  
    dir_aux = direccion;
    check_pared = false;
    gravedad = kGrav;
    alturasuelo = Mapa::Instance()->getAltura()*32 - 32*9.5;//APAÑO FEO (ARREGLAR)
    alturasuelo_nueva = Mapa::Instance()->getAltura()*32 - 32*9.5;//APAÑO FEO (ARREGLAR);
    espacio = 0;
    velocidadsalto = 0.8;
    nsprite = 0;
    max_sprites = 6;
    velocidad.x = kVel;
    velocidad.y=0;
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

void Personaje::gravity(float timeElapsed, int valorabajo){
    
    if(valorabajo==0){
        velocidad.y += gravedad*timeElapsed;
    }
    else{
        if(!suelo){
            suelo =true;
        }
        else{
           velocidad.y = 0; 
        }
         
         espacio=0;
         gravedad = kGrav;
        
    }
    
     /*if(sprite.getPosy() + sprite.getScaley() < alturasuelo || velocidad.y < 0) {
        velocidad.y += gravedad*timeElapsed;
      }
      else {
        sprite.setPosition(sprite.getPosx(), alturasuelo - sprite.getScaley());
        posx = sprite.getPosx();
        posy = sprite.getPosy();
        velocidad.y = 0;
        espacio=0;
        gravedad = kGrav;
        
      }*/
     
}

void Personaje::moverSalto(){    
    if(espacio <2){
      velocidad.y = -velocidadsalto;         
      espacio++;
      gravedad= kGrav;
      suelo= false;
    }
    
     // int var1 = contEspacios;
}

void Personaje::mover(float timeElapsed){
    int rx = boxDerecha.getPosition().x / 32;
    int ry = boxDerecha.getPosition().y / 32;
    int lx = boxIzquierda.getPosition().x / 32;
    int ly = boxIzquierda.getPosition().y / 32;
    int dx = boxAbajo.getPosition().x /32;
    int dy = boxAbajo.getPosition().y /32;
    int ux = boxArriba.getPosition().x /32;
    int uy = boxArriba.getPosition().y /32;
    int px = sprite.getSprite().getPosition().x / 32;
    int py = sprite.getSprite().getPosition().y / 32;
    Mapa::Instance()->activarCapa(0);
    int valorderecha = Mapa::Instance()->getTile(rx,ry);
    int valorabajo = Mapa::Instance()->getTile(dx,dy);
    int valorizquierda = Mapa::Instance()->getTile(lx,ly);
    int valorarriba = Mapa::Instance()->getTile(ux,uy);
    
    
    
    int valorpersonaje = Mapa::Instance()->getTile(px,py);
    //cout << "(x,y) = " << rx << " , " << ry <<  " : "<< valorderecha << endl;
    //cout << "(x,y) = " << lx << " , " << ly <<  " : "<< valorizquierda << endl;
    //cout << "(x,y) = " << dx << " , " << dy <<  " : "<< valorabajo << endl;
    //cout << "(x,y) = " << ux << " , " << uy <<  " : "<< valorarriba << endl;
    
    
    
    switch(valorderecha){
        case 2: //aqui esta tocando con la pared del lado
            direccion = -1;
            espacio = 0;
            sprite.setScale(-1.0f,1.0f);
            
        break;
        
        case 7://aqui toca con los bloques normales
            direccion = -1;
            espacio = 0;
            sprite.setScale(-1.0f,1.0f);
        break;
    }
    
     switch(valorizquierda){
        case 1: //aqui esta tocando con la pared del lado
            direccion = 1;
            espacio = 0;
            sprite.setScale(1.0f,1.0f);
            
        break;
        
        case 7://aqui toca con los bloques normales
            direccion = 1;
            espacio = 0;
            sprite.setScale(1.0f,1.0f);
        break;
    }
     
     if(valorarriba !=0 && valorarriba!=3 && valorarriba!=4){
         velocidad.y+=1;
     }
    
     gravity(timeElapsed, valorabajo);
    
     posx = posx+velocidad.x*direccion*timeElapsed;
     posy = posy+ velocidad.y*timeElapsed;
     sprite.setPosition(posx,posy);
     
    
  
    
    
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
        boxArriba.setPosition(sprite.getPosx(),sprite.getPosy()-15);
        boxDerecha.setPosition(sprite.getPosx()+15, sprite.getPosy());
        boxIzquierda.setPosition(sprite.getPosx()-15, sprite.getPosy());
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
     
