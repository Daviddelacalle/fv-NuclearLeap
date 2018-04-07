/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.h
 * Author: pato-lt
 *
 * Created on 23 de marzo de 2018, 18:56
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef STATE_H
#define STATE_H

class State{
    
private:
    int posx;
    int posy;
public:
    State(int, int);
    void setPosx(int);
    void setPosy(int);
    int getPosx();
    int getPosy();
};

#endif /* STATE_H */

