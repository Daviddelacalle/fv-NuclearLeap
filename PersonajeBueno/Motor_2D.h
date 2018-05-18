/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor_2D.h
 * Author: pato-pc
 *
 * Created on 25 de abril de 2018, 19:31
 */

#ifndef MOTOR_2D_H
#define MOTOR_2D_H

#include "config.h"
#include "mapa.h"
#include <SFML/Graphics.hpp> 

class Motor_2D {
public:
    static Motor_2D* Instance();
    sf::RenderWindow* getWindow();
    sf::View* getVistaPrincipal();
    float get_clockElapsedTime();
    
    void actualizarVista(Personaje &_pj);
    void draw(sf::Sprite &_sprite);
    void draw(sf::Text &_text);
    void setVistaPrincipal();
    void restartClock();
    void setCenterVista(float);
    
protected:
    Motor_2D();
    Motor_2D(const Motor_2D & );
    Motor_2D &operator= (const Motor_2D & );

private: 
    static Motor_2D* pinstance;
    sf::RenderWindow* window;
    sf::View* vista_principal;
    sf::Clock clock;

};

#endif /* MOTOR_2D_H */

