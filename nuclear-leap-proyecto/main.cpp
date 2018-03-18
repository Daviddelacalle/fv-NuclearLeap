#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream> 

#include "Rads.h"
#include "Bloque.h"
#include "Ia.h"

#define kVel 0.004
#define tMax 300
using namespace std;

int main()
{
    sf::Clock clock;
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
    
    sf::RectangleShape pos(sf::Vector2f(250,12));
    pos.setOrigin(100,6);
    pos.setPosition(200,213);
    pos.setFillColor(sf::Color::Blue);
    
    Npc1 npc1(200,200);
    
    //Bucle del juego
    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {  
            switch(event.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        
        
        sf::Time tiempo_max = sf::milliseconds(tMax);
        
        if(clock.getElapsedTime() > tiempo_max){
            npc1.actualizarSprite();
            clock.restart();
        }
        
        npc1.movimiento(pos);
        
        
        //Bucle de obtención de eventos
        window.clear();
        window.draw(pos);
        window.draw(npc1.getSprite());
        
        window.draw(npc1.getBox_up());
        window.draw(npc1.getBox_right());
        window.draw(npc1.getBox_left());
        
        window.display();
    }

    return 0;
}

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
    
    nsprite = 0;
    
     if (!tex.loadFromFile("sprites/npc1.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
     
    
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(nsprite*32, 0*32, 32, 32));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
    
    box_up = sf::RectangleShape(sf::Vector2f(28,1));
    box_up.setOrigin(14,0);
    box_up.setPosition(posx,posy-10);
    box_up.setFillColor(sf::Color::Red);
    
    box_left = sf::RectangleShape(sf::Vector2f(1,16));
    box_left.setOrigin(0,24);
    box_left.setPosition(posx-16,posy+18);
    box_left.setFillColor(sf::Color::Red);
    
    box_right = sf::RectangleShape(sf::Vector2f(1,16));
    box_right.setOrigin(0,24);
    box_right.setPosition(posx+16,posy+18);
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
    box_up.setPosition(posx,posy-10);
    box_left.setPosition(posx-16,posy+18);
    box_right.setPosition(posx+16,posy+18);
}

void Npc1::actualizarSprite(){
    if(nsprite == 4){
        nsprite = 0;
    }
    sprite.setTextureRect(sf::IntRect(nsprite*32, 0*32, 32, 32));
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

Npc3::Npc3(float _posx,float _posy):Ia(_posx,_posy){
    
     if (!tex.loadFromFile("sprites/npc3/npc3-0.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(140/2,134/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*140, 0*134, 140, 134));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
}

Npc5::Npc5(float _posx,float _posy):Ia(_posx,_posy){
    
     if (!tex.loadFromFile("sprites/npc5/npc5-0.png")){
        std::cerr << "Error cargando la imagen sprites.png";
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