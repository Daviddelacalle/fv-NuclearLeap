/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: david
 *
 * Created on 16 de mayo de 2018, 17:18
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <SFML/Graphics.hpp>
class Vector {
public:
    Vector();
    sf::Vector2f getVector();
    void setPosx(float);
    void setPosy(float);
    float getPosx();
    float getPosy();
private:
    sf::Vector2f sprite;
};

#endif /* VECTOR_H */

