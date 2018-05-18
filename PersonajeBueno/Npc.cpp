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
#include "mapa.h"
#include "Motor_2D.h"

Npc::Npc(float _posx, float _posy) {
    posx = _posx;
    posy = _posy;
    posix = _posx;
    posiy = _posy;
    dirx = 1;
    diry = 0;
    nsprite = 0;
}

Mi_Sprite Npc::getSprite(){
    return sprite;
}

void Npc::setPosition(float _x, float _y){
    posx = _x;
    posy = _y;
    sprite.setPosition(_x,_y);
}

void Npc::actualizarSprite(){
    if(sprite.get_clockElapsedTime() > vel_actualizar){
        if(nsprite == max_sprites){
            nsprite = 0;
        }
        sprite.setFrame(nsprite , line_sprite);
        nsprite++;     
        sprite.restartClock();
    }
}

void Npc::draw(){
    sprite.draw();
}
Bloque Npc::getBox_up(){
    return box_up;
}
Bloque Npc::getBox_right(){
    return box_right;
}
Bloque Npc::getBox_left(){
    return box_left;
}
Bloque Npc::getBox_down(){
    return box_down;
}

void Npc::restart(){ 
    setPosition(posix,posiy); 
}
//NPC1

Npc1::Npc1(float _posx, float _posy):Npc(_posx,_posy){
    tam = 32;
    max_sprites = 4;
    line_sprite = 0;
    div_box = 2;
    vel_actualizar = 200;
    
     if (!tex.loadFromFile("sprites/npc1.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    sprite.setParams(0,0,32,32,_posx,_posy);
    
    
    //COLISIONADORES
    
    box_up.setParams(28,1,posx,posy-16);
    
    box_left.setParams(1,16,posx-16,posy+2);
    
    box_right.setParams(1,16,posx+16,posy+2);
    
    box_down.setParams(1,4,posx+16*dirx,posy+2);
}

void Npc1::movimiento(){
    
    int rx = box_right.getBloque().getPosition().x / 32;
    int ry = box_right.getBloque().getPosition().y / 32;
    int lx = box_left.getBloque().getPosition().x / 32;
    int ly = box_left.getBloque().getPosition().y / 32;
    int ux = box_up.getBloque().getPosition().x / 32;
    int uy = box_up.getBloque().getPosition().y / 32;
    int dx = box_down.getBloque().getPosition().x / 32;
    int dy = box_down.getBloque().getPosition().y / 32;
    
    Mapa::Instance()->activarCapa(0);
    
    int vr = Mapa::Instance()->getTile(rx,ry);
    int vl = Mapa::Instance()->getTile(lx,ly);
    int vu = Mapa::Instance()->getTile(ux,uy);
    int vd = Mapa::Instance()->getTile(dx,dy);
    
   // cout << "vd: " << vd << "\n";
    
    if(dirx == 1){
        if(vd != 7 && vd != 3 && vd != 4){
            dirx = -1;
            sprite.setScale(-1,1);
        }
    }
    
    else if(dirx == -1){
        if(vd != 7 && vd != 3 && vd != 4){
            dirx = +1;
            sprite.setScale(1,1);
        }
    }
    
    if(dirx == 1){
        if(vr != 0){
            dirx = -1;
            sprite.setScale(-1,1);
        }
    }
    
    if(dirx == -1){
        if(vl != 0){
            dirx = +1;
            sprite.setScale(1,1);
        }
    }
    
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
    
    sprite.setPosition(posx,posy);
    
}

void Npc1::update(Personaje& _pj){
    
    movimiento();
    actualizarBox();
    actualizarSprite();
    matarPj(_pj);
}

void Npc1::actualizarBox(){
    box_up.setPos(posx,posy-(tam/6));
    box_left.setPos(posx-(tam/div_box),posy+10);
    box_right.setPos(posx+(tam/div_box),posy+10);
    box_down.setPos(posx+20*dirx,posy+20);
}

void Npc1::matarPj(Personaje& _pj){
    
    if(_pj.getSprite().getSprite().getGlobalBounds().intersects(box_up.getBloque().getGlobalBounds())){
        setPosition(5000,sprite.getPosy());
    }
    else if(_pj.getSprite().getSprite().getGlobalBounds().intersects(box_left.getBloque().getGlobalBounds()) || _pj.getSprite().getSprite().getGlobalBounds().intersects(box_right.getBloque().getGlobalBounds()) ){
        if(_pj.inmune < 1 && _pj.clock.getElapsedTime().asSeconds()>3){
            setPosition(posix,posiy);
            _pj.morir();
             if(_pj.clock.getElapsedTime().asSeconds()<3)
                    _pj.clock.restart();
        }else{
                
                if(_pj.inmune > 0){
                    _pj.clock.restart();
                    _pj.inmune-=1;
                    _pj.getSprite().setFrame(0,2);
                }
        }
    }
}


//NPC3

Npc3::Npc3(float _posx, float _posy):Npc(_posx,_posy){
    tam = 64;
    max_sprites = 8;
    line_sprite = 1;
    div_box = 3;
    vel_actualizar = 100;
     if (!tex.loadFromFile("sprites/npc3.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }
    
    sprite.setParams(0,1,32,32,_posx,_posy);
    sprite.setScale(1.5,1.5);
    
    //COLISIONADORES
    box_up.setParams(60,1,posx,posy-32);
    
    box_left.setParams(1,46,posx-32,posy+2);
    
    box_right.setParams(1,46,posx+32,posy+2);
}
void Npc3::movimiento(){
    
    int rx = box_right.getBloque().getPosition().x / 32;
    int ry = box_right.getBloque().getPosition().y / 32;
    int lx = box_left.getBloque().getPosition().x / 32;
    int ly = box_left.getBloque().getPosition().y / 32;
    int ux = box_up.getBloque().getPosition().x / 32;
    int uy = box_up.getBloque().getPosition().y / 32;
    int dx = box_down.getBloque().getPosition().x / 32;
    int dy = box_down.getBloque().getPosition().y / 32;
    
    Mapa::Instance()->activarCapa(0);
    
    int vr = Mapa::Instance()->getTile(rx,ry);
    int vl = Mapa::Instance()->getTile(lx,ly);
    int vu = Mapa::Instance()->getTile(ux,uy);
    int vd = Mapa::Instance()->getTile(dx,dy);
    
    //cout << "vd: " << vd << "\n";
    
    if(dirx == 1){
        if(vd != 7 && vd != 3 && vd != 4){
            dirx = -1;
            sprite.setScale(-1.5,1.5);
        }
    }
    
    else if(dirx == -1){
        if(vd != 7 && vd != 3 && vd != 4){
            dirx = +1;
            sprite.setScale(1.5,1.5);
        }
    }
    
    if(dirx == 1){
        if(vr != 0){
            dirx = -1;
            sprite.setScale(-1.5,1.5);
        }
    }
    
    if(dirx == -1){
        if(vl != 0){
            dirx = +1;
            sprite.setScale(1.5,1.5);
        }
    }
    
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
    
    sprite.setPosition(posx,posy);
    
}

void Npc3::update(Personaje& _pj){
    
    movimiento();
    actualizarBox();
    actualizarSprite();
    matarPj(_pj);
}

void Npc3::actualizarBox(){
    box_up.setPos(posx,posy-(tam/6));
    box_left.setPos(posx-(tam/div_box),posy+10);
    box_right.setPos(posx+(tam/div_box),posy+10);
    box_down.setPos(posx+20*dirx,posy+20);
}

void Npc3::matarPj(Personaje& _pj){
    if(_pj.getSprite().getSprite().getGlobalBounds().intersects(sprite.getSprite().getGlobalBounds())){
        if(_pj.inmune < 1 && _pj.clock.getElapsedTime().asSeconds()>3){
            setPosition(posix,posiy);
           _pj.morir();
             if(_pj.clock.getElapsedTime().asSeconds()<3)
                    _pj.clock.restart();
        }else{
                
                if(_pj.inmune > 0){
                    _pj.clock.restart();
                    _pj.inmune-=1;
                    _pj.getSprite().setFrame(0,2);
                }
        }
        
    }
}

Npc5::Npc5(float _posx, float _posy):Npc(_posx, _posy){
    tam = 64;
    max_sprites = 6;
    line_sprite = 3;
    vel_actualizar = 80;
     if (!tex.loadFromFile("sprites/npc5.png")){
        std::cout << "Error cargando la imagen sprites.png";
        exit(0);
    }

    sprite.setParams(8,0,32,32,_posx,_posy);
    sprite.setScale(1.5,1.5);
    //COLISIONADORES
    box_up.setParams(60,1,posx,posy-32);
    
    box_down.setParams(60,1,posx,posy+36); 
    
    box_left.setParams(1,40,posx-32,posy);
    
    box_right.setParams(1,40,posx+32,posy);
}

void Npc5::movimiento(Personaje &_pj){
    
    float npc5Vel = npcVel*2;
    if(_pj.getSprite().getPosx() < posx){
    //El pj esta a la izquierda
        dirx = -1;
        
    }
    else if(_pj.getSprite().getPosx() > posx){
    //El pj esta a la derecha
        dirx = 1;
    }
    
    else if(_pj.getSprite().getPosx() == posx){
    //El pj esta a la misma altura x
        dirx = 0;

    }
    
    if(_pj.getSprite().getPosy() < posy){
    //El pj esta encima
        diry = -1;

    }
    else if(_pj.getSprite().getPosy() > posy){
    //El pj esta debajo
        diry = 1;

    }
    
    else if(_pj.getSprite().getPosy() == posy){
    //El pj esta a la misma altura y
        diry = 0;

    }
    
    int rx = box_right.getBloque().getPosition().x / 32;
    int ry = box_right.getBloque().getPosition().y / 32;
    int lx = box_left.getBloque().getPosition().x / 32;
    int ly = box_left.getBloque().getPosition().y / 32;
    int ux = box_up.getBloque().getPosition().x / 32;
    int uy = box_up.getBloque().getPosition().y / 32;
    int dx = box_down.getBloque().getPosition().x / 32;
    int dy = box_down.getBloque().getPosition().y / 32;
    
    Mapa::Instance()->activarCapa(0);
    
    int vr = Mapa::Instance()->getTile(rx,ry);
    int vl = Mapa::Instance()->getTile(lx,ly);
    int vu = Mapa::Instance()->getTile(ux,uy);
    int vd = Mapa::Instance()->getTile(dx,dy);
    
    if(vr != 0){
        //dirx = -1;
        setPosition(posx - npc5Vel, posy);
    }
    if(vl != 0){
        //dirx = 1;
        setPosition(posx + npc5Vel, posy);
    }
    if(vu !=0){
        //diry = +1;
        setPosition(posx, posy + npc5Vel);
    }
    if(vd != 0){
        //diry = -1;
        setPosition(posx, posy - npc5Vel);
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
    
    posx = posx + dirx*npc5Vel;
    posy = posy + diry*npc5Vel;
    
    setPosition(posx,posy);
}

void Npc5::actualizarBox(){
    box_up.setPos(posx,posy-(tam/2-6));
    box_left.setPos(posx-(tam/2),posy);
    box_right.setPos(posx+(tam/2),posy);
    box_down.setPos(posx,posy+(tam/2 - 2));
}

void Npc5::update(Personaje &_pj){
    movimiento(_pj);
    actualizarBox();
    actualizarSprite();
    matarPj(_pj);
}


void Npc5::matarPj(Personaje& _pj){
    if(_pj.getSprite().getSprite().getGlobalBounds().intersects(sprite.getSprite().getGlobalBounds())){
        if(_pj.inmune < 1 && _pj.clock.getElapsedTime().asSeconds()>3){
            restart();
            _pj.morir();
             if(_pj.clock.getElapsedTime().asSeconds()<3)
                    _pj.clock.restart();
        }else{
                
                if(_pj.inmune > 0){
                    _pj.clock.restart();
                    _pj.inmune-=1;
                    _pj.getSprite().setFrame(0,2);
                }
        }
        
    }
}
