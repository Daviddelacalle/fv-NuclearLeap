/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutationsState.h
 * Author: natalia
 *
 * Created on 17 de mayo de 2018, 12:30
 */

#ifndef MUTATIONSSTATE_H
#define MUTATIONSSTATE_H
#include "config.h"
#include "Mi_Sprite.h"
#include "Mi_Texto.h"
#include "Estado.h"
#include "inGame.h"

class MutationsState : public Estado{
public:
    static MutationsState* Instance();     
    void Init();
    void HandleInput();
    void Update(int);
    void Update(string menu);
    void Draw();
    int puntos;
protected:        
    MutationsState();
    MutationsState(const MutationsState & );
    MutationsState &operator= (const MutationsState & );
private:
    static MutationsState* pinstance; 
    Mi_Sprite background;    
    bool activo;
    int estado;
    int op;
    inGame ingame;
    Mi_Texto texto;
    std::stringstream ss;

};

#endif /* MUTATIONSSTATE_H */

