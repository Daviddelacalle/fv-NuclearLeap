/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ia.h"

Ia::Ia(float _posx, float _posy){
    posx = _posx;
    posy = _posy;
    dirx = 1;
    diry = 0;
}

sf::Sprite Ia::getSprite(){
    return sprite;
}

Npc1::Npc1(float _posx,float _posy):Ia(_posx,_posy){
    
    tam = 32;
    nsprite = 0;
    max_sprites = 4;
    
     if (!tex.loadFromFile("sprites/npc1.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
     
    
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(nsprite*32, 0*32, 32, 32));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
    
    //COLISIONADORES
    
    box_up = sf::RectangleShape(sf::Vector2f(28,1));
    box_up.setOrigin(14,0);
    box_up.setPosition(posx,posy-10);
    box_up.setFillColor(sf::Color::Red);
    
    box_left = sf::RectangleShape(sf::Vector2f(1,16));
    box_left.setOrigin(0,8);
    box_left.setPosition(posx-16,posy+2);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,16));
    box_right.setOrigin(0,8);
    box_right.setPosition(posx+16,posy+2);
    box_right.setFillColor(sf::Color::Red);
}

void Npc1::movimiento(sf::RectangleShape &_bloque){
    if(dirx == 1){
        if(!box_right.getGlobalBounds().intersects(_bloque.getGlobalBounds())){
            dirx = -1;
            sprite.scale(-1,1);
        }
    }
    if(dirx == -1){
        if(!box_left.getGlobalBounds().intersects(_bloque.getGlobalBounds())){
            dirx = 1;
            sprite.scale(-1,1);
        }
    }
    
    posx = posx + dirx*kVel;
    posy = posy + diry*kVel;
    
    sprite.setPosition(posx,posy);
    actualizarBox();
}

void Npc1::actualizarBox(){
    box_up.setPosition(posx,posy-(tam/2-6));
    box_left.setPosition(posx-(tam/2),posy+2);
    box_right.setPosition(posx+(tam/2),posy+2);
}

void Npc1::actualizarSprite(){
    if(nsprite == max_sprites){
        nsprite = 0;
    }
    sprite.setTextureRect(sf::IntRect(nsprite*tam, 0*tam, tam, tam));
    nsprite++;
}

sf::RectangleShape Npc1::getBox_up(){
    return box_up;
}
sf::RectangleShape Npc1::getBox_right(){
    return box_right;
}
sf::RectangleShape Npc1::getBox_left(){
    return box_left;
}

Npc3::Npc3(float _posx,float _posy):Npc1(_posx,_posy){
    tam = 64;
    max_sprites = 8;
     if (!tex.loadFromFile("sprites/npc3.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(64/2,64/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(nsprite*64, 0*64, 64, 64));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
    
    //COLISIONADORES
    box_up = sf::RectangleShape(sf::Vector2f(60,1));
    box_up.setOrigin(30,0);
    box_up.setPosition(posx,posy-32);
    box_up.setFillColor(sf::Color::Red);
    
    box_left = sf::RectangleShape(sf::Vector2f(1,60));
    box_left.setOrigin(0,16);
    box_left.setPosition(posx-32,posy+2);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,60));
    box_right.setOrigin(0,16);
    box_right.setPosition(posx+32,posy+2);
    box_right.setFillColor(sf::Color::Red);
}

Npc5::Npc5(float _posx,float _posy):Ia(_posx,_posy){
    
     if (!tex.loadFromFile("sprites/npc5/npc5-0.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(140/2,140/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*140, 0*140, 140, 140));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
}