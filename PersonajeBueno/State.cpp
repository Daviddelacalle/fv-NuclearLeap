/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.cpp
 * Author: pato-lt
 * 
 * Created on 17 de abril de 2018, 14:05
 */


#include "State.h"

State::State(){

    
}

void State::setParams(float _posx, float _posy){
    posx = _posx;
    posy = _posy;
    lastx=_posx;
    lasty=_posy;  
}

void State::setPosx(float _posx){
    lastx = posx;
    posx = _posx;
}
void State::setPosy(float _posy){
    lasty = posy;
    posy = _posy;
}

float State::getPosx(){
    return posx;
}
float State::getPosy(){
    return posy;
}

float State::getLastx(){
    return lastx;
}

float State::getLasty(){
    return lasty;
}