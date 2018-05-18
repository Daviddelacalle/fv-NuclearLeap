/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reloj.cpp
 * Author: david
 * 
 * Created on 18 de mayo de 2018, 20:14
 */

#include <SFML/System/Clock.hpp>

#include "Reloj.h"

Reloj::Reloj() {
}
void Reloj::restart(){
    reloj.restart();
}
sf::Clock Reloj::getReloj(){
    return reloj;
}
