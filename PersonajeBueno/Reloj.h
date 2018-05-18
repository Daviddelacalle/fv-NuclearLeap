/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reloj.h
 * Author: david
 *
 * Created on 18 de mayo de 2018, 20:14
 */

#ifndef RELOJ_H
#define RELOJ_H
#include <SFML/Graphics.hpp>
class Reloj {
public:
    Reloj();
    sf::Clock getReloj();
    void restart();
private:
    sf::Clock reloj;
    
};

#endif /* RELOJ_H */

