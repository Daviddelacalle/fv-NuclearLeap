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

State::State(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
}

void State::setPosx(int _posx){
    posx = _posx;
}
void State::setPosy(int _posy){
    posy = _posy;
}
int State::getPosx(){
    return posx;
}
int State::getPosy(){
    return posy;
}