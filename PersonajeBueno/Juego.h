/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: natalia
 *
 * Created on 15 de mayo de 2018, 14:09
 */

#ifndef JUEGO_H
#define JUEGO_H
#include "inGame.h"
#include "Estado.h"
#include "MainMenuState.h"
#include "GameOverState.h"

class Juego {
public:
    static Juego* Instance();  
    void inicializar();    
    void cambiarMenu(int);
    bool alive;
    Estado* estadoJuego;
     
protected:
     Juego();
    Juego(const Juego & );
    Juego &operator= (const Juego & );
private:
    
    static Juego* pinstance;  
    inGame ingame;
    int estado;
    int menu;  
   
};

#endif /* JUEGO_H */

