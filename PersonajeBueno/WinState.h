/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WinState.h
 * Author: natalia
 *
 * Created on 18 de mayo de 2018, 13:24
 */

#ifndef WINSTATE_H
#define WINSTATE_H

#include "config.h"
#include "Mi_Sprite.h"
#include "inGame.h"
#include "Estado.h"
#include "Mi_Texto.h"
#include "config.h"

class WinState : public Estado{
public:
    static WinState* Instance();
    void Init();
    void HandleInput();
    void Update(int);
    void Update(string menu);
    void Draw();
protected:        
    WinState();
    WinState(const WinState & );
    WinState &operator= (const WinState & );
private:
     Mi_Texto reloj;
     Mi_Texto vidas;
     Mi_Texto rads;
    static WinState* pinstance; 
    Mi_Sprite background;    
    bool activo;
    int estado;
    inGame ingame;

};

#endif /* WINSTATE_H */

