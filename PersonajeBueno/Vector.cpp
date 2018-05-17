/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.cpp
 * Author: david
 * 
 * Created on 16 de mayo de 2018, 17:18
 */

#include "Vector.h"

Vector::Vector() {
}
sf::Vector2f Vector::getVector(){
    return sprite;
}
void Vector::setPosx(float x){
    sprite.x=x;
}
void Vector::setPosy(float y){
    sprite.y=y;
}
float Vector::getPosx(){
    return sprite.x;
}
float Vector::getPosy(){
    return sprite.y;
}