/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Npc.cpp
 * Author: pato-lt
 * 
 * Created on 23 de abril de 2018, 11:54
 */

#include "Npc.h"

Npc::Npc(int _posx, int _posy) {
    posx = (float)_posx;
    posy = (float)_posy;
    dirx = 1;
    diry = 0;
    nsprite = 0;
}

sf::Sprite Npc::getSprite(){
    return sprite;
}

void Npc::setPosition(int _x, int _y){
    posx = (float)_x;
    posy = (float)_y;
}

void Npc::actualizarSprite(){
    if(nsprite == max_sprites){
        nsprite = 0;
    }
    sprite.setTextureRect(sf::IntRect(nsprite*tam, 0*tam, tam, tam));
    nsprite++;
}

sf::RectangleShape Npc::getBox_up(){
    return box_up;
}
sf::RectangleShape Npc::getBox_right(){
    return box_right;
}
sf::RectangleShape Npc::getBox_left(){
    return box_left;
}


//NPC1

Npc1::Npc1(int _posx, int _posy):Npc(_posx,_posy){
    tam = 32;
    max_sprites = 4;
    
     if (!tex.loadFromFile("sprites/npc1.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    sprite = sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(nsprite*32, 0*32, 32, 32));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
    
    //COLISIONADORES
    
    box_up = sf::RectangleShape(sf::Vector2f(28,1));
    box_up.setOrigin(14,0);
    box_up.setPosition(posx,posy-16);
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

void Npc1::movimiento(){
    /*
    if(dirx == 1){
        if(!box_right.getGlobalBounds().intersects(EL BLOQUE DEL MAPA)){
            dirx = -1;
            sprite.scale(-1,1);
            //el box de la derecha detecta que salga de la plataforma
        }
    }
    
    if(dirx == -1){
        if(!box_right.getGlobalBounds().intersects(EL BLOQUE DEL MAPA)){
            dirx = 1;
            sprite.scale(-1,1);
        }
    }
    */
    
    posx = posx + dirx*npcVel;
    posy = posy + dirx*npcVel;
    
    sprite.setPosition(posx,posy);
    actualizarBox();
    actualizarSprite();
}

void Npc1::actualizarBox(){
    box_up.setPosition(posx,posy-(tam/2));
    box_left.setPosition(posx-(tam/2),posy+2);
    box_right.setPosition(posx+(tam/2),posy+2);
}

//NPC3

Npc3::Npc3(int _posx, int _posy):Npc1(_posx,_posy){
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
    
    box_left = sf::RectangleShape(sf::Vector2f(1,46));
    box_left.setOrigin(0,16);
    box_left.setPosition(posx-32,posy+2);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,46));
    box_right.setOrigin(0,16);
    box_right.setPosition(posx+32,posy+2);
    box_right.setFillColor(sf::Color::Red);
}

Npc5::Npc5(int _posx, int _posy):Npc(_posx, _posy){
    tam = 64;
    max_sprites = 6;
     if (!tex.loadFromFile("sprites/npc5.png")){
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
    
    box_down = sf::RectangleShape(sf::Vector2f(60,1));
    box_down.setOrigin(30,0);
    box_down.setPosition(posx,posy+36);
    box_down.setFillColor(sf::Color::Red);
    
    box_left = sf::RectangleShape(sf::Vector2f(1,40));
    box_left.setOrigin(0,16);
    box_left.setPosition(posx-32,posy);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,40));
    box_right.setOrigin(0,16);
    box_right.setPosition(posx+32,posy);
    box_right.setFillColor(sf::Color::Red);
}

void Npc5::movimiento(Personaje &_pj){
    if(_pj.getSprite().getPosition().x < posx){
    //El pj esta a la izquierda
        dirx = -1;
        
    }
    else if(_pj.getSprite().getPosition().x > posx){
    //El pj esta a la derecha
        dirx = 1;
        cout << "esta a la derecha el personaje \n";
    }
    
    else if(_pj.getSprite().getPosition().x == posx){
    //El pj esta a la misma altura x
        dirx = 0;

    }
    
    if(_pj.getSprite().getPosition().y < posy){
    //El pj esta encima
        diry = -1;

    }
    else if(_pj.getSprite().getPosition().y > posy){
    //El pj esta debajo
        diry = 1;

    }
    
    else if(_pj.getSprite().getPosition().y == posy){
    //El pj esta a la misma altura y
        diry = 0;

    }
    
    /*Llamar a la funcion de javi que me dice el numero del tiled
     
     if(box_up.getPosition == plataforma){
     *  diry = +1; 
     * }
     *else if(box_down.getPosition == plataforma){
     *  diry = -1;
     * }
     * else if(box_right.getPosition == plataforma){
     *  dirx = -1;
     * }
     * else if(box_left.getPosition == plataforma){
     *  dirx = +1;
     * }
     */
    
    /**/
    if(dirx == -1){
        cout << "esta a la izquierda el personaje \n";
    }
    if(dirx == 1){
        cout << "esta a la derecha el personaje \n";
    }
    
    posx = posx + dirx*npcVel;
    posy = posy + diry*npcVel;
    
    sprite.setPosition(posx,posy);
    actualizarBox();
}

void Npc5::actualizarBox(){
    box_up.setPosition(posx,posy-(tam/2-6));
    box_left.setPosition(posx-(tam/2),posy);
    box_right.setPosition(posx+(tam/2),posy);
    box_down.setPosition(posx,posy+(tam/2 - 2));
}