/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.h
 * Author: pato-lt
 *
 * Created on 17 de abril de 2018, 14:05
 */
#include "config.h"

#ifndef STATE_H
#define STATE_H

class State{
    
private:
    float posx;
    float posy;
    float lastx;
    float lasty;
public:
    State(float, float);
    void setPosx(float);
    void setPosy(float);
    float getPosx();
    float getPosy();
    float getLastx();
    float getLasty();

};

#endif /* STATE_H */

