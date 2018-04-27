/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mi_Texto.h
 * Author: natalia
 *
 * Created on 27 de abril de 2018, 13:16
 */

#ifndef MI_TEXTO_H
#define MI_TEXTO_H
#include "config.h"

class Mi_Texto {
public:
    Mi_Texto(); 
    sf::Text getTexto();
    void draw();
    void setParams(sf::String _string, int _tam, float _posx, float _posy);
    void setText(sf::String _string);
    void setPosition(float, float);
private:
    sf::Font font;
    sf::Text text;
};

#endif /* MI_TEXTO_H */

