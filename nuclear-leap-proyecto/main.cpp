#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream> 

#include "Rads.h"
#include "Bloque.h"
#include "Ia.h"

#define kVel 5

using namespace std;

int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
    
    Npc1 npc1(200,200);
    Npc3 npc3(400,400);
    Npc5 npc5(400, 200);
    
    //Bucle del juego
    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        window.clear();
        window.draw(npc1.getSprite());
        window.draw(npc3.getSprite());
        window.draw(npc5.getSprite());
        window.display();
    }

    return 0;
}

Ia::Ia(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
        
}

sf::Sprite Ia::getSprite(){
    return sprite;
}

Npc1::Npc1(int _posx,int _posy):Ia(_posx,_posy){
    
     if (!tex.loadFromFile("sprites/npc1/npc1-0.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(48/2,48/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*48, 0*48, 48, 48));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);
}


Npc3::Npc3(int _posx,int _posy):Ia(_posx,_posy){
    
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

Npc5::Npc5(int _posx,int _posy):Ia(_posx,_posy){
    
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