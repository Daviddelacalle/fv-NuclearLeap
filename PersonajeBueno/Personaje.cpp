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

#include "Personaje.h"
#include "mapa.h"


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
    
    
    direccion = 1;  
    dir_aux = direccion;
    check_pared = false;
    gravedad = kGrav;
    alturasuelo = Mapa::Instance()->getAltura()*32 - 32*9.5;//APAÑO FEO (ARREGLAR)
    alturasuelo_nueva = Mapa::Instance()->getAltura()*32 - 32*9.5;//APAÑO FEO (ARREGLAR);
    espacio = 0;
    velocidadsalto = 0.8f;
    nsprite = 0;
    max_sprites = 6;
    velocidad.x = kVel;
    contEspacios=0;
    var1 = 0;
    
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
    
    int rx = boxDerecha.getPosition().x / 32;
    int ry = boxDerecha.getPosition().y / 32;
    int lx = boxIzquierda.getPosition().x / 32;
    int ly = boxIzquierda.getPosition().y / 32;
    int dx = boxAbajo.getPosition().x /32;
    int dy = boxAbajo.getPosition().y /32;
    int ux = boxArriba.getPosition().x /32;
    int uy = boxArriba.getPosition().y /32;
    Mapa::Instance()->activarCapa(0);
    int valorderecha = Mapa::Instance()->getTile(rx,ry);;
    int valorabajo = Mapa::Instance()->getTile(dx,dy);;
    int valorizquierda = Mapa::Instance()->getTile(lx,ly);;
    int valorarriba = Mapa::Instance()->getTile(ux,uy);;
    //cout << "(x,y) = " << rx << " , " << ry <<  " : "<< valorderecha << endl;
    //cout << "(x,y) = " << lx << " , " << ly <<  " : "<< valorizquierda << endl;
    cout << "(x,y) = " << dx << " , " << dy <<  " : "<< valorabajo << endl;
    
    
    
    switch(valorarriba){
        case 0: break;
        
        case 7: 
            velocidad.y += 0.3;
            break;
    }
    
    switch(valorabajo){
        case 0: 
            estoyNormal();
            break;
        case 7: 
            cout << dy;
            estoyAzul(dy * 32);
            break;
            
        case 3:              
            alturasuelo_nueva=dy*32-15;
            alturasuelo = alturasuelo_nueva;            
            break;
            
        case 4:
            alturasuelo_nueva=dy*32-15;
            alturasuelo = alturasuelo_nueva;            
            break;
            
        case 8:
            estoyRoja(dy*32);
            break;
            
    }
    
    
    
    
    switch(valorderecha){
        case 0: 
             
            break;
        
        case 2: 
            if(check_pared == false){
                check_pared = true;
                dir_aux = -1;
                direccion = 0;
                espacio = 0;
                //direccion = -1;

                sprite.setScale(-1.0f,1.0f);
            }
            break;
            
        case 7:
            if(check_pared == false){
               check_pared = true;
               dir_aux = -1;
               direccion = 0;
               espacio = 0;
               //direccion = -1;

               sprite.setScale(-1.0f,1.0f);
            }
            
            break;
            
        case 57:
            //sprite.setPosition();
            break;
        case 58:
            cout<<sprite.getPosx()<<"y"<<sprite.getPosy();
            break;
    }
    
    
    
    switch(valorizquierda){
        case 0:
             
             break;
        case 1:
            if(check_pared == false){
                check_pared = true;
                dir_aux = 1;
                direccion = 0;
                espacio = 0;
                //direccion = 1;
                sprite.setScale(1.0f,1.0f);
            }
            break;
            
            case 7:
            if(check_pared == false){
                check_pared = true;
                dir_aux = 1;
                direccion = 0;
                espacio = 0;
                //direccion = 1;
                sprite.setScale(1.0f,1.0f);
            }
            
            break;
    }
    
           
    
    
    if(check_pared == true){
        if(velocidad.y < 0){
            gravedad = kGrav*1.5;
        }
        if(velocidad.y >= 0 ){
            gravedad = kGravP;
        }
    }
    
    cout << "Gravedad: " << gravedad << "\n";
    
    
    if(sprite.getPosy() + sprite.getScaley() >= alturasuelo || espacio > 0 && check_pared == true){
            gravedad = kGrav;
            direccion = dir_aux;
            check_pared = false;
    }
    
    gravity(timeElapsed);
    
    //std::cout<<"bajo"<<velocidad.x<<"\n"; 
    
    sprite.move(velocidad.x*direccion*timeElapsed,velocidad.y*timeElapsed);
    if(sprite.getPosy() > alturasuelo){
        sprite.setPosition(sprite.getPosx(), alturasuelo);
    }
    
    //std::cout<<"arriba"<<velocidad.x<<"\n";      
   /* boxAbajo.setPosition(sprite.getPosition().x, sprite.getPosition().y+20);
    boxArriba.setPosition(sprite.getPosition().x, sprite.getPosition().y-20);
    int posxs = boxAbajo.getPosition().x;
    int posys = boxAbajo.getPosition().y;
    posx = sprite.getPosition().x;
    posy = sprite.getPosition().y;*/
    
   /* int posxs = boxAbajo.getPosition().x;
    int posys = boxAbajo.getPosition().y;
    posx = sprite.getPosition().x;
    posy = sprite.getPosition().y;*/
    
    if(check_pared == false){
        actualizarSprite();
    }
    
}

int Personaje::getEspacios(){
    return espacio;
}


void Personaje::actualizarSprite(){
    if(nsprite == max_sprites){
        nsprite = 0;
    }
    sprite.setFrame(nsprite,2); // dos porke es la fila 2
    nsprite++;
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
        
    }
    
    void Personaje::estoyNormal(){
       alturasuelo = alturasuelo_nueva;
        velocidad.x = kVel;
    }
    
    sf::RectangleShape Personaje::getBoxAbajo(){
        return boxArriba;
        
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
    }
    
    