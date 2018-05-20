/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: pato-lt
 * 
 * Created on 19 de abril de 2018, 13:54
 */
#include "SFML/Audio.hpp"
#include "Personaje.h"
#include "mapa.h"
#include "Mi_Texto.h"
#include "Motor_2D.h"
#include "Juego.h"
#include "Bloque.h"
#include "Vector.h"
#include "MutationsState.h"
#include "WinState.h"
#include "NoRadsState.h"
#include   "Mundo.h"

Personaje::Personaje(){
   
   // sprite.setPosition(224, alturasuelo);
}

void Personaje::iniciarPersonaje(){
         boxAbajo.setParams(30,2,320,630);
   
    alturasuelo = Mapa::Instance()->getAltura()*32 - 32*9.5;
    sprite.setParams(0,2,32,32,200,alturasuelo);
    lastCheck = alturasuelo;
    sprite.setScale(1.0,1.0);
    
    boxAbajo.setParams(9,2,320,630);
    boxAbajo2.setParams(9,2,320,630);
    boxAbajo3.setParams(9,2,320,630);
    
    boxArriba.setParams(9,2,320,630);
    boxArriba2.setParams(9,2,320,630);
    boxArriba3.setParams(9,2,320,630);

    boxDerecha.setParams(20,2,320,630);
    boxDerecha.rotate(90);
    
    boxIzquierda.setParams(20,2,320,630);
    boxIzquierda.rotate(90);
    
    //Y creo el spritesheet a partir de la imagen anterior
    
    posx = sprite.getPosx();
    posy = sprite.getPosy();
    
    
    direccion = 1;  
    dir_aux = direccion;
    check_pared = false;
    gravedad = kGrav;
    
    alturasuelo_nueva = Mapa::Instance()->getAltura()*32 - 32*9.5;
    espacio = 0;
    velocidadsalto = 0.8;
    nsprite = 0;
    max_sprites = 6;
    velocidad.setPosx(kVel);
    velocidad.setPosy(0);
    contEspacios=0;
    var1 = 0;
    vel_camara =10;
    checkpoint== Mapa::Instance()->getAltura()*32 - 32*9.5;
    pierdo = false;
    puntuacion = 0;
    
    std::stringstream ss;
    vidas = 5;
    ss<<vidas;
    posx_vida = 60;
    posy_vida= posy +200;
    
    text_vidas.setParams(ss.str(), 13, posx_vida,posy_vida);
    text_puntuacion.setParams('0',13, posx_vida +40, posy_vida);
    text_puntuacion.setColor(sf::Color::Black);
    sprite_vidas.setParams(4,0,32,32, posx_vida+15,posy_vida+3);
    sprite_vidas.setScale(1.5,1.5);
    sprite_puntuacion.setParams(6,0,32,32,400,posy_vida);
    sprite_puntuacion.setScale(1.5,1.5);
     
    text_perder.setParams("HAS PERDIDO", 30, 0, 0);
    inmune = 0;
     cosa= 0;
     pordos=false;
     tiempoFinal.restart();
}


Mi_Sprite Personaje::getSprite(){
   return sprite;   
}

void Personaje::gravity(float timeElapsed){
     if(sprite.getPosy() + sprite.getScaley() < alturasuelo || velocidad.getPosy() < 0) {
        velocidad.setPosy(velocidad.getPosy()+gravedad*timeElapsed);
      }
      else {
        sprite.setPosition(sprite.getPosx(), alturasuelo - sprite.getScaley());
        posx = sprite.getPosx();
        posy = sprite.getPosy();
        velocidad.setPosy(0);
        espacio=0;
        gravedad = kGrav;
        
      }
     
}

void Personaje::moverSalto(){    
    if(espacio <3 && jumpy){
      velocidad.setPosy(-velocidadsalto);         
      espacio++;
      gravedad= kGrav;

    }
    else if(espacio<2){
        velocidad.setPosy(-velocidadsalto);         
      espacio++;
      gravedad= kGrav;
    }
    
     int var1 = contEspacios;
}

void Personaje::mover(float timeElapsed){
    int rx = boxDerecha.getBloque().getPosition().x / 32;
    int ry = boxDerecha.getBloque().getPosition().y / 32;
    int lx = boxIzquierda.getBloque().getPosition().x / 32;
    int ly = boxIzquierda.getBloque().getPosition().y / 32;
    int dx = boxAbajo.getBloque().getPosition().x /32;
    int dy = boxAbajo.getBloque().getPosition().y /32;
    int dx2 = boxAbajo2.getBloque().getPosition().x /32;
    int dy2 = boxAbajo2.getBloque().getPosition().y /32;
    int dx3 = boxAbajo3.getBloque().getPosition().x /32;
    int dy3 = boxAbajo3.getBloque().getPosition().y /32;
    int ux = boxArriba.getBloque().getPosition().x /32;
    int uy = boxArriba.getBloque().getPosition().y /32;
    int ux2 = boxArriba2.getBloque().getPosition().x /32;
    int uy2 = boxArriba2.getBloque().getPosition().y /32;
    int ux3 = boxArriba3.getBloque().getPosition().x /32;
    int uy3 = boxArriba3.getBloque().getPosition().y /32;
    int px = sprite.getSprite().getPosition().x / 32;
    int py = sprite.getSprite().getPosition().y / 32;
    Mapa::Instance()->activarCapa(0);
    int valorderecha = Mapa::Instance()->getTile(rx,ry);
    int valorabajo = Mapa::Instance()->getTile(dx,dy);
    int valorabajo2 = Mapa::Instance()->getTile(dx2,dy2);
    int valorabajo3 = Mapa::Instance()->getTile(dx3,dy3);
    int valorizquierda = Mapa::Instance()->getTile(lx,ly);
    int valorarriba = Mapa::Instance()->getTile(ux,uy);
    int valorarriba2 = Mapa::Instance()->getTile(ux2,uy2);
    int valorarriba3 = Mapa::Instance()->getTile(ux3,uy3);
 //cout<<lastCheck<<"y"<<sprite.getPosy()<<"\n";
   
    int valorpersonaje = Mapa::Instance()->getTile(px,py);
    Juego* juego = Juego::Instance(); 
    MutationsState* muta = MutationsState::Instance(); 
    muta->puntos = puntuacion;
    NoRadsState* norads = NoRadsState::Instance(); 
    norads->puntos = puntuacion;
    switch(valorarriba){
        case 0: break;
        
        case 7: 
            velocidad.setPosy(0.1);
            //cout<<"HOLA \n";
            break;
            
        case 8:
            velocidad.setPosy(0.1);
             break;
        case 10:
            
            win();
           
        break;
    }
    
    switch(valorarriba2){
        case 0: break;
        
        case 7: 
            velocidad.setPosy(0.1);
            //cout<<"HOLA \n";
            break;
            
        case 8:
            velocidad.setPosy(0.1);
             break;
        case 10:
            
            win();
           
        break;
    }
    
    switch(valorarriba3){
        case 0: break;
        
        case 7: 
            velocidad.setPosy(0.1);
            //cout<<"HOLA \n";
            break;
            
        case 8:
            velocidad.setPosy(0.1);
             break;
        case 10:
            
            win();
           
        break;
    }
    
    
    
    switch(valorabajo){
        case 0: 
            estoyNormal();
            break;  
        
        case 7: 
           // cout << dy;           
            estoyAzul(dy * 32);
            break;
            
        case 3:              
            
            alturasuelo = dy*32-15;
            
            break;
            
        case 4:      
            abrirMutaciones();
            alturasuelo = dy*32-15;
            checkpoint=alturasuelo; 
            break;
            
        case 8:
            estoyRoja(dy*32);
            break;
            
        case 9:
            velocidad.setPosy(-velocidadsalto - 0.6);
            break;
            
    }
    
    switch(valorabajo2){
        case 0: 
            estoyNormal();
            break;  
        
        case 7: 
           // cout << dy;           
            estoyAzul(dy * 32);
            break;
            
        case 3:              
            
            alturasuelo = dy*32-15;
            
            break;
            
        case 4:      
            abrirMutaciones();
            alturasuelo = dy*32-15;
            checkpoint=alturasuelo; 
            break;
            
        case 8:
            estoyRoja(dy*32);
            break;
            
        case 9:
            velocidad.setPosy(-velocidadsalto - 0.6);
            break;
            
    }
    
    switch(valorabajo3){
        case 0: 
            estoyNormal();
            break;  
        
        case 7: 
           // cout << dy;           
            estoyAzul(dy * 32);
            break;
            
        case 3:              
            
            alturasuelo = dy*32-15;
            
            break;
            
        case 4:      
            abrirMutaciones();
            alturasuelo = dy*32-15;
            checkpoint=alturasuelo; 
            break;
            
        case 8:
            estoyRoja(dy*32);
            break;
            
        case 9:
            velocidad.setPosy(-velocidadsalto - 0.6);
            break;
            
    }
 
    
    
    
    switch(valorderecha){
        case 0: 
             
            break;
            
        
        case 2: 
            if(check_pared == false){
                check_pared = true;
                dir_aux = -1;
                direccion = 0;
                espacio = 0;
                //direccion = -1;

                sprite.setScale(-1.0f,1.0f); 
            }
            break;
            
        case 7:
            if(check_pared == false){
               check_pared = true;
               dir_aux = -1;
               direccion = 0;
               espacio = 0;
               //direccion = -1;

                sprite.setScale(-1.0f,1.0f); 
            }
            
            break;
               
    }
    
    
    
    switch(valorizquierda){
        case 0:
            
            break;
            
            
        case 1:
            if(check_pared == false){
                check_pared = true;
                dir_aux = 1;
                direccion = 0;
                espacio = 0;
                //direccion = 1;
                sprite.setScale(1.0f,1.0f); 
            }
            break;
            
        case 7:
            if(check_pared == false){
                check_pared = true;
                dir_aux = 1;
                direccion = 0;
                espacio = 0;
                //direccion = 1;
                 sprite.setScale(1.0f,1.0f); 
            }
            
            break;
            
    }
    
    if(valorizquierda > 50 && valorizquierda%2!=0){
       
        Mapa::Instance()->activarCapa(4);
        int x = Mapa::Instance()->getCoordenadas(valorizquierda,0);
        int y = Mapa::Instance()->getCoordenadas(valorizquierda,1);
        if(valorizquierda==59){
            x=x+1.5;
            direccion=1;
            sprite.setScale(1.0f,1.0f);
        }
        if(valorizquierda==57)
            x=x-1.5;
        if(valorizquierda==61){
            x=x-1;
            direccion=-1;
            sprite.setScale(-1.0f,1.0f);
        }
        sprite.setPosition(x*32,y*32);
        Mapa::Instance()->activarCapa(0);
           
    }
    if(valorderecha > 50 && valorderecha%2!=0){
        
        Mapa::Instance()->activarCapa(4);
        int x = Mapa::Instance()->getCoordenadas(valorderecha,0);
        int y = Mapa::Instance()->getCoordenadas(valorderecha,1);
        if(valorderecha==59){
            x=x+1.5;
            direccion=1;
            sprite.setScale(1.0f,1.0f);
        }
        if(valorderecha==57)
            x=x-1.5;
        if(valorderecha==61){
            x=x-1;
            direccion=-1;
            sprite.setScale(-1.0f,1.0f);
        }
        sprite.setPosition(x*32,y*32);
        Mapa::Instance()->activarCapa(0);
          
    }    
    if(clock2.getElapsedTime().asSeconds()>12){
        pordos=false;
    }
     if(clockJump.getElapsedTime().asSeconds()>10){
        jumpy=false;
    }
    
    //cout<<inmune<<"\n";
    switch(valorpersonaje){
        case 5:     
            cout<<inmune<<"\n";
            cout<<clock.getElapsedTime().asSeconds()<<"\n";
            if(inmune < 1 && clock.getElapsedTime().asSeconds()>3){
                morir();  
                if(clock.getElapsedTime().asSeconds()<3)
                    clock.restart();
            }else{
                cout<<"holaaaaaaaaa";
                if(inmune > 0){
                    clock.restart();
                    inmune-=1;
                    sprite.setFrame(0,2);
                }
                
            }         
            break;        
    }
    

    
    if(check_pared == true){
        
        if(velocidad.getPosy() < 0){//para que no resbale
            gravedad = kGrav*1.5;
        }
        if(velocidad.getPosy() >= 0 ){
            velocidad.setPosy(0.2);
            gravedad = kGravP;
        }
    }
    
    //cout << "Checkpoint: " << checkpoint << "\n";
    
    
    if(sprite.getSprite().getPosition().y + sprite.getSprite().getScale().y >= alturasuelo  || espacio > 0 && check_pared == true){
            gravedad = kGrav;
            direccion = dir_aux;
            check_pared = false;
    }
    if (valorderecha == 0 && valorizquierda == 0 && direccion==0){
        velocidad.setPosy(0.6);
    }
    
    gravity(timeElapsed);
    
    if(velocidad.getPosy() != 0){ 
        vel_camara = velocidad.getPosy()*timeElapsed; 
        if(vel_camara < 1){ 
            vel_camara = vel_camara *-1; 
        } 
    }
    
    
    //std::cout<<"bajo"<<velocidad.x<<"\n"; 
    if(pierdo == false){
        sprite.move(velocidad.getPosx()*direccion*timeElapsed,velocidad.getPosy()*timeElapsed);
    }
    
    if(sprite.getSprite().getPosition().y > alturasuelo){
        sprite.setPosition(sprite.getSprite().getPosition().x, alturasuelo);
    }

    
    //std::cout<<"arriba"<<velocidad.x<<"\n";      
   /* boxAbajo.setPosition(sprite.getPosition().x, sprite.getPosition().y+20);
    boxArriba.setPosition(sprite.getPosition().x, sprite.getPosition().y-20);
    int posxs = boxAbajo.getPosition().x;
    int posys = boxAbajo.getPosition().y;
    posx = sprite.getPosition().x;
    posy = sprite.getPosition().y;*/
    
   /* int posxs = boxAbajo.getPosition().x;
    int posys = boxAbajo.getPosition().y;
    posx = sprite.getPosition().x;
    posy = sprite.getPosition().y;*/
    
    
    
}

int Personaje::getEspacios(){
    return espacio;
}


void Personaje::actualizarSprite(){
    
   
    if(pierdo == false){
        if(sprite.get_clockElapsedTime() > 50){
        if(check_pared == false){
            if(nsprite == max_sprites){
                nsprite = 0;
            }
            if(inmune>0)
                sprite.setFrame(nsprite,4); // dos porque es la fila 2
            else
            sprite.setFrame(nsprite,2); // dos porque es la fila 2
            nsprite++;    
        sprite.restartClock();
    }
    //actualizo la pos de las vidas   
   }
    }
}



void Personaje::cambiarPosicion(int num, int num2){
    sprite.setPosition(num, num2);
}

void Personaje::estoyRoja(int y){
        alturasuelo =y-15;
        velocidad.setPosx(kVel*2);
}
    void Personaje::estoyAzul(int y){
       alturasuelo = y-15;
         velocidad.setPosx(kVel);
    }
    void Personaje::estoyPortalIda(float x, float y){
        sprite.setPosition(x,y);
        
    }
    void Personaje::estoyPortalVuelta(float x, float y){
        
    }
    void Personaje::estoySaltador(){
        moverSalto();
    }
    
    float Personaje::getVelocidad(){ 
        return vel_camara; 
    }
    
    void Personaje::estoyNormal(){
       alturasuelo = alturasuelo_nueva;
        velocidad.setPosx(kVel);
    }
 
    void Personaje::setPosition(float _x, float _y){
        sprite.setPosition(_x,_y);
    }
    
    void Personaje::actualizarBoxes(){
        boxAbajo.setPos(sprite.getPosx(), sprite.getPosy()+20);
        boxAbajo2.setPos(sprite.getPosx()+11, sprite.getPosy()+20);
        boxAbajo3.setPos(sprite.getPosx()-11, sprite.getPosy()+20);
        boxArriba.setPos(sprite.getPosx(),sprite.getPosy()-15);
        boxArriba2.setPos(sprite.getPosx()+10,sprite.getPosy()-15);
        boxArriba3.setPos(sprite.getPosx()-10,sprite.getPosy()-15);
        boxDerecha.setPos(sprite.getPosx()+15, sprite.getPosy());
        boxIzquierda.setPos(sprite.getPosx()-15, sprite.getPosy());
    }
     
    Bloque Personaje::getBoxAbajo(){
        return boxAbajo;
        
    }
    
    Bloque Personaje::getBoxAbajo2(){
        return boxAbajo2;
        
    }
    
    Bloque Personaje::getBoxAbajo3(){
        return boxAbajo3;
        
    }
    
    Bloque Personaje::getBoxArriba(){
        return boxArriba;  
    }
    
    Bloque Personaje::getBoxArriba2(){
        return boxArriba2;  
    }
    
    Bloque Personaje::getBoxArriba3(){
        return boxArriba3;  
    }
    
    Bloque Personaje::getBoxDerecha(){
        return boxDerecha;  
    }
    
    Bloque Personaje::getBoxIzquierda(){
        return boxIzquierda;  
    }
    
    void Personaje::draw(){
        sprite.draw();
        sprite_vidas.draw();
        sprite_puntuacion.draw();
        text_vidas.draw();
        text_puntuacion.draw();
        if(pierdo ==true){
            text_perder.draw();
        }
        
    }
    
     void Personaje::update(float timeElapsed){    
        Mapa* map = Mapa::Instance(); 
        mover(timeElapsed);      
        actualizarSprite();
        map->recogerRads(sprite,puntuacion);
        actualizarPuntuacion();
      
     }
     
     void Personaje::setPosVidas(){
        Motor_2D* motor = Motor_2D::Instance();
        text_vidas.setPosition(posx_vida -7 ,motor->getVistaPrincipal()->getCenter().y -330);  
        sprite_vidas.setPosition(posx_vida,motor->getVistaPrincipal()->getCenter().y-327); 
        sprite_puntuacion.setPosition(posx_vida + 330, motor->getVistaPrincipal()->getCenter().y -327);
        text_puntuacion.setPosition(posx_vida + 315, motor->getVistaPrincipal()->getCenter().y -330);
     }  
     
     void Personaje::actualizarVidas(){
         std::stringstream ss;
         ss<<vidas;
         text_vidas.setText(ss.str());
         
     }
     
     void Personaje::actualizarPuntuacion(){
         std::stringstream ss;
         ss<<puntuacion;
         text_puntuacion.setText(ss.str());
         
     }

     void Personaje::morir(){
        Juego* juego = Juego::Instance();
        Mapa* map = Mapa::Instance();
        alturasuelo=checkpoint;
        alturasuelo_nueva = checkpoint;
        sprite.setPosition(200, alturasuelo);
        vidas--;
        velocidad.setPosy(0);
        actualizarVidas();
        Motor_2D* motor = Motor_2D::Instance();     
        motor->setCenterVista(juego->pj.getSprite().getPosy());
        if(vidas==0){  
            iniciarPersonaje();          
            juego->alive = false;              
            juego->estadoJuego = GameOverState::Instance(); 
            
           // map->ResetInstance();
        }
        
        
        
    //PARTE REINICIAR NPCS
    for(int it = 0; it < map->getvNpc1().size() ; it++){
        Npc1 *tmp = map->getvNpc1()[it];
        tmp->restart();
    }
    
    for(int it = 0; it < map->getvNpc3().size() ; it++){
        Npc3 *tmp = map->getvNpc3()[it];
            tmp->restart(); 
    }
    
    for(int it = 0; it < map->getvNpc5().size() ; it++){
        Npc5 *tmp = map->getvNpc5()[it];
        tmp->restart();
    }
}
     
     void Personaje::abrirMutaciones(){
         Juego* juego = Juego::Instance();
        // if(sprite.getPosy() < (Mapa::Instance()->getAltura()*32 - 32*9.5 )-50){
         if(sprite.getPosy() < lastCheck -50 && sprite.getPosy() > 1000){ 
             lastCheck = sprite.getPosy();
             juego->pausa=true;             
            // cout<<lastCheck<<"\n";             
            // juego->alive = false;  
            juego->estadoJuego = MutationsState::Instance();
         }
        // }
            
     }
     
     void Personaje::inmunidad(){ 
         Juego* juego = Juego::Instance();
          Mundo* mundo = Mundo::Instance();
         if(puntuacion>=15){ 
            
            inmune +=1;            
            puntuacion -=15;
            sprite.setFrame(0,4);
            juego->pausa=false; 
            mundo->inicializar();
         }          
         else{
              juego->estadoJuego = NoRadsState::Instance();            
              juego->pausa=true;    
              
         }
         
         
     }
     
     void Personaje::porDos(){
         Juego* juego = Juego::Instance();
         if(puntuacion>=15){
            pordos=true;
            puntuacion -=15;
            clock2.restart();
         }else{
             cout<<"ENTROOOOOOOOOOOOOOOOOOO";
              juego->pausa=true;    
               juego->estadoJuego = NoRadsState::Instance();
         }
     }
     
     void Personaje::jump(){
         Juego* juego = Juego::Instance();
         if(puntuacion>=15){
            jumpy = true;
            puntuacion -=15;
            clockJump.restart();
         }else{
              juego->pausa=true;    
               juego->estadoJuego = NoRadsState::Instance();
         }
     }
     
     void Personaje::win(){
         std::stringstream ss2;          
         ss2<<tiempoFinal.getElapsedTime().asSeconds();
         reloj = ss2.str();
         Juego* juego = Juego::Instance();
         juego->pausa=true;   
         juego->estadoJuego = WinState::Instance();
     }
     
     int Personaje::getVidas(){
         return vidas;
     }
     
