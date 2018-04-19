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


Personaje::Personaje(){
   
    if (!tex.loadFromFile("resources/Sprite.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    sf::RectangleShape colisionador(sf::Vector2f(30,5));
    colisionador.setOrigin(15,2.5);
    colisionador.setPosition(320, 630);
    colisionador.setFillColor(sf::Color::Blue);
    colision = colisionador;
    
    //Y creo el spritesheet a partir de la imagen anterior
    sprite.setTexture(tex);
    
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(18/2,21/2);
    //Cojo el sprite que me interesa por defecto del sheet
   // sprite.setTextureRect(sf::IntRect(23, 448, 23, 24));
    sprite.setTextureRect(sf::IntRect(1, 1, 18, 17));   
    sprite.setScale(2.0f,2.0f);
    
    sprite.setPosition(320, 630);     
    
    sf::Vector2f velocidad(sf::Vector2f(0,0));
    direccion = 1;    
    gravedad = 0.00016;
    alturasuelo = 630;
    espacio = 0;
    velocidadsalto = 0.19f;
    nsprite = 0;
    max_sprites = 6;
    velocidad.x = 0.03;
    
}



sf::Sprite Personaje::getSprite(){
    return sprite;   
}

void Personaje::gravity(){
     if(sprite.getPosition().y + sprite.getScale().y < alturasuelo || velocidad.y < 0) {
       velocidad.y += gravedad;
      }
      else {
      sprite.setPosition(sprite.getPosition().x, alturasuelo - sprite.getScale().y);
      velocidad.y = 0;
      espacio=0;
      }
}

void Personaje::moverSalto(){    
    if(espacio <2){
      velocidad.y = -velocidadsalto;     
       
      espacio++;
    }
     
}

void Personaje::mover(){
    
    
    if(sprite.getPosition().x > 390){ //izq
            
                 direccion = -1;
                 espacio=0;
                 sprite.setScale(-2.0f,2.0f);
            
        }
        else if (sprite.getPosition().x < 30 ){//dcha
            direccion = 1;
            espacio=0;
            sprite.setScale(2.0f,2.0f);
        
        }
    std::cout<<"bajo"<<velocidad.x<<"\n"; 
    velocidad.x=velocidad.x*direccion;
    sprite.move(velocidad.x,velocidad.y);
    std::cout<<"arriba"<<velocidad.x<<"\n";      
    colision.setPosition(sprite.getPosition().x, sprite.getPosition().y+20);
       
    
}

int Personaje::getEspacios(){
    return espacio;
}


void Personaje::actualizarSprite(){
    if(nsprite == max_sprites){
        nsprite = 0;
    }
    sprite.setTextureRect(sf::IntRect(nsprite*18, 0*18, 18, 21));
    nsprite++;
}



void Personaje::cambiarPosicion(int num, int num2){
    sprite.setPosition(num, num2);
}

void Personaje::estoyRoja(float y){
        alturasuelo =y-24;
        velocidad.x = 0.06;
}
    void Personaje::estoyAzul(float y){
        alturasuelo =y-24;
        velocidad.x = 0.03;
    }
    void Personaje::estoyPortalIda(float x, float y){
        sprite.setPosition(x,y);
        
    }
    void Personaje::estoyPortalVuelta(float x, float y){
        
    }
    void Personaje::estoySaltador(){
        
    }
    
    void Personaje::estoyNormal(){
        alturasuelo =630;
        velocidad.x = 0.03;
    }
    
    sf::RectangleShape Personaje::colisionador(){
        return colision;
        
    }

    void Personaje::setPosition(int _x, int _y){
        sprite.setPosition(_x,_y);
    }