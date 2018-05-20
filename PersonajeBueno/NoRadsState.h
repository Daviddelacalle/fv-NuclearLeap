/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoRadsState.h
 * Author: natalia
 *
 * Created on 20 de mayo de 2018, 13:39
 */

#ifndef NORADSSTATE_H
#define NORADSSTATE_H

#include "config.h"
#include "Mi_Sprite.h"
#include "inGame.h"
#include "Estado.h"
#include "Mi_Texto.h"
#include "config.h"

class NoRadsState : public Estado{
public:
    static NoRadsState* Instance();
    void Init();
    void HandleInput();
    void Update(int);
    void Update(string menu);
    void Draw();
     int puntos;
protected:        
    NoRadsState();
    NoRadsState(const NoRadsState & );
    NoRadsState &operator= (const NoRadsState & );
private:    
    static NoRadsState* pinstance; 
    Mi_Sprite background;    
    bool activo;
    int estado;
    inGame ingame;
     Mi_Texto texto;
    std::stringstream ss;

};
#endif /* NORADSSTATE_H */

