#include <iostream>
#include <SFML/Graphics.hpp>
#include "mapa.h"

int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(448, 700), "P0. Fundamentos de los Videojuegos. DCCIA");
    Mapa map;
    
    sf::RectangleShape sprite = sf::RectangleShape(sf::Vector2f(32,32));
    sprite.setFillColor(sf::Color::Red);
    sprite.setOrigin(32/2,32);
    int tiles =map.getAltura();
    tiles *= 32;
    std::cout << tiles << std::endl;
    sprite.setPosition(224, tiles-32*9);
    
    
    sf::View view(sf::FloatRect(0, tiles, 448, 700));
    
    
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
                                                
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                    }

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.move(0,-10);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.move(0,10);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.move(-10,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.move(+10,0);
            }
            view.setCenter(224,sprite.getPosition().y-64);
        }
        window.setView(view);
        window.clear();      
        
        sf::Sprite mapa = map.getFondo();
        mapa.setPosition(0,view.getCenter().y-400);
        window.draw(mapa);
        
        map.activarCapa(3);
        window.draw(map);
        window.draw(sprite);
        
        window.display();
    }


    return 0;
}