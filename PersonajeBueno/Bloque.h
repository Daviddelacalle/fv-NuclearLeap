/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.h
 * Author: david
 *
 * Created on 16 de mayo de 2018, 16:11
 */

#ifndef BLOQUE_H
#define BLOQUE_H
#include <SFML/Graphics.hpp>
class Bloque {
public:
    Bloque();
    sf::RectangleShape getBloque();
    void setParams(float,float,float,float);
    void setPos(float,float);
    void rotate(float);
private:
    sf::RectangleShape sprite;
};

#endif /* BLOQUE_H */

