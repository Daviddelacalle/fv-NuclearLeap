/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pato-lt
 *
 * Created on 17 de abril de 2018, 13:36
 */
#include "config.h"
#include "State.h"
#include "Personaje.h"
#include "mapa.h"
#include "Npc.h"
#include "Mi_Sprite.h"
#include "Motor_2D.h"
#include "Rads.h"
#include "Mundo.h" 
#include "Juego.h"
#include <SFML/Audio.hpp>
/*
 * 
 */


int main() {     
    
    Juego* juego = Juego::Instance();
    juego->inicializar();
    
    
    return 0;
}

