/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   inGame.cpp
 * Author: natalia
 * 
 * Created on 15 de mayo de 2018, 14:14
 */

#include "inGame.h"
#include "Mundo.h"
#include "config.h"

inGame::inGame() {
    
}

void inGame::iniciarPartida(){     
    Mundo* mundo = Mundo::Instance();    
    mundo->inicializar();
}



