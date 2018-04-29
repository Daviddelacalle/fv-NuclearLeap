/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.cpp
 * Author: natalia
 * 
 * Created on 29 de abril de 2018, 9:12
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "MainMenu.h"
#include "Mi_Sprite.h"

MainMenu::MainMenu() {
    
    sf::Texture tex;
    
     if (!tex.loadFromFile("resources/fondo_main.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    
    sprite.setTexture(tex);
    
}

MainMenu::MainMenu(const MainMenu& orig) {
}

MainMenu::~MainMenu() {
}

void MainMenu::draw(){
    sprite.draw();
}

