/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mundo.h
 * Author: natalia
 *
 * Created on 15 de mayo de 2018, 9:12
 */

#ifndef MUNDO_H
#define MUNDO_H
#include "config.h"
#include "State.h"
#include "Personaje.h"
#include "mapa.h"
#include "Npc.h"
#include "Mi_Sprite.h"
#include "Motor_2D.h"
#include "Rads.h" 
class Mundo {
public:
    
    static Mundo* Instance();     
    void inicializar();
    void actualizarPuntuacion(int,sf::Text &_puntRads); 
    void update( State &_pj_S ,float timeElapsed, Personaje &_pj, State &_npc_S, Npc3 &npc5);
    void render_interpolation(sf::RenderWindow &_window, State _pj_S, float _percentTick, Personaje &_pj, State _npc_S, Npc3 &_npc5); 
    float minimo(float,float);
    
    
protected:
    Mundo();
    Mundo(const Mundo & );
    Mundo &operator= (const Mundo & );
private:
    int iniciado=0;
     static Mundo* pinstance;     
     //State npc_S;
};

#endif /* MUNDO_H */

