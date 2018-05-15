/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include <sstream> 
#include "Rads.h"
#include "Mi_Sprite.h"

using namespace std;

Rads::Rads(int _x, int _y , int _puntuacion){
    //cout<<"posx "<<_x<<"\n";
    //cout<<"posy"<<_y;
    posx = _x;
    posy = _y;
    
    int tam;
    
    puntuacion = _puntuacion;    
          
    
    if(_puntuacion == 1){
       
        tam = 24;
        sprite.setParams(5,0,32,32,posx,posy);
       
       
        
    }
    
    if(_puntuacion == 5){
              
        tam = 36;
       
         sprite.setParams(6,0,32,32,posx,posy);
  
    }
    
    sprite.setOrigin(0,0);
    
     //Y creo el spritesheet a partir de la imagen anterior
    
    //Le pongo el centroide donde corresponde
    
    //Cojo el sprite que me interesa por defecto del sheet
    
    // Lo dispongo en el centro de la pantalla 


    
}

Mi_Sprite Rads::getSprite(){
    return sprite;
}

int Rads::getPuntuacion(){
    return puntuacion;
}

void Rads::setPosition(int _x, int _y){
    sprite.setPosition(_x,_y);
    
    
}

void Rads::draw(){
    sprite.draw();    
}


    