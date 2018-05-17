/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuState.h
 * Author: natalia
 *
 * Created on 16 de mayo de 2018, 15:53
 */

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "config.h"
#include "Mi_Sprite.h"
#include "inGame.h"
#include "Estado.h"

class MainMenuState : public Estado{
public:
    static MainMenuState* Instance();     
    void Init();
    void HandleInput();
    void Update(int);
    void Update(string menu);
    void Draw();
protected:        
    MainMenuState();
    MainMenuState(const MainMenuState & );
    MainMenuState &operator= (const MainMenuState & );
private:
    static MainMenuState* pinstance; 
    Mi_Sprite background;    
    bool activo;
    int estado;
    int op;
    inGame ingame;

};

#endif /* MAINMENUSTATE_H */

