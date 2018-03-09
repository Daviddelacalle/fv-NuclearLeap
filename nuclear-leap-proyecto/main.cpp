#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream> 

#include "Rads.h"
#include "Bloque.h"

#define kVel 5

sf::Text crearPuntuacion();
void actualizarPuntuacion(int,sf::Text &_puntRads);
void recogerRads(Rads _rads[], sf::RectangleShape _sprite , int &_nrads);


using namespace std;

int main()
{
    // Creamos el texto que muestra la puntuacion
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text puntRads("Rads: ",font);
    puntRads.setCharacterSize(40);
    puntRads.setStyle(sf::Text::Bold);
    puntRads.setColor(sf::Color::Green);
    puntRads.setPosition(5,10);
    
    
    
    std::stringstream ss;
    int nrads = 0;
    ss<<nrads;
    puntRads.setString(ss.str());
    //end
    
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Y creo el spritesheet a partir de la imagen anterior
    
    sf::RectangleShape sprite = sf::RectangleShape(sf::Vector2f(32,32));
    
    
    
    sprite.setFillColor(sf::Color::Red);
    
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(320, 240);
    
    Rads rads[4] {{200,324,1},{200,348,1},{200,300,1},{100,200,5}};

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
                    
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {
                        
                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            sprite.move(kVel,0);
                        break;

                        case sf::Keyboard::Left:
                            sprite.move(-kVel,0); 
                        break;
                        
                        case sf::Keyboard::Up:
                            sprite.move(0,-kVel); 
                        break;
                        
                        case sf::Keyboard::Down:
                            sprite.move(0,kVel); 
                        break;
                        
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;
                              
                    }

            }
            
        }
        
        
        recogerRads(rads,sprite,nrads);
        actualizarPuntuacion(nrads,puntRads);

        window.clear();
        window.draw(sprite);
        window.draw(puntRads);
        window.draw(rads[0].getSprite());
        window.draw(rads[1].getSprite());
        window.draw(rads[2].getSprite());
        window.draw(rads[3].getSprite());
        window.display();
    }

    return 0;
}


Rads::Rads(int _x, int _y , int _puntuacion){
    posx = _x;
    posy = _y;
    
    int tam;
    
    puntuacion = _puntuacion;
    
    if(_puntuacion == 1){
        if (!tex.loadFromFile("sprites/Rad.png"))
        {
            std::cerr << "Error cargando la imagen sprites.png";
            exit(0);
        }
        tam = 24;
    }
    
    if(_puntuacion == 5){
        if (!tex.loadFromFile("sprites/Rad2.png"))
        {
            std::cerr << "Error cargando la imagen sprites.png";
            exit(0);
        }
        
        tam = 36;
    }
    
     //Y creo el spritesheet a partir de la imagen anterior
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(tam/2,tam/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*tam, 0*tam, tam, tam));
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(posx, posy);

    
}

sf::Sprite Rads::getSprite(){
    return sprite;
}

int Rads::getPuntuacion(){
    return puntuacion;
}

void Rads::setPosition(int _x, int _y){
    sprite.setPosition(_x,_y);
}

void actualizarPuntuacion(int _nrads, sf::Text &_puntRads){
    std::stringstream ss;
    ss<<_nrads;
    _puntRads.setString(ss.str());
}

void recogerRads(Rads _rads[], sf::RectangleShape _sprite, int &_nrads){
    
    for(int i = 0; i < 4; i++){
       if(_sprite.getGlobalBounds().intersects(_rads[i].getSprite().getGlobalBounds())){
           _nrads = _nrads + _rads[i].getPuntuacion();
           _rads[i].setPosition(1000,1000);
           
       }
    }
    
}