/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameOverState.h
 * Author: natalia
 *
 * Created on 16 de mayo de 2018, 21:06
 */

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "config.h"
#include "Mi_Sprite.h"
#include "inGame.h"
#include "Estado.h"
class GameOverState : public Estado{
public:
    static GameOverState* Instance();
    void Init();
    void HandleInput();
    void Update(int);
    void Update(string menu);
    void Draw();
protected:        
    GameOverState();
    GameOverState(const GameOverState & );
    GameOverState &operator= (const GameOverState & );
private:
    static GameOverState* pinstance; 
    Mi_Sprite background;    
    bool activo;
    int estado;
    inGame ingame;

};

#endif /* GAMEOVERSTATE_H */

