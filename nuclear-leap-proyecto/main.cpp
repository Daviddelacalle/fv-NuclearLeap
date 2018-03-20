#include "config.h"
#include "Rads.h"
#include "Bloque.h"
#include "Ia.h"

int main()
{
    sf::Clock clock;
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
    
    sf::RectangleShape pj = sf::RectangleShape(sf::Vector2f(32,32));
    pj.setFillColor(sf::Color::Red);
    //Le pongo el centroide donde corresponde
    pj.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    // Lo dispongo en el centro de la pantalla
    pj.setPosition(320, 240);
    
    sf::RectangleShape plat1(sf::Vector2f(250,12));
    plat1.setOrigin(100,6);
    plat1.setPosition(400,362);
    plat1.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape plat3(sf::Vector2f(250,12));
    plat3.setOrigin(100,6);
    plat3.setPosition(200,186);
    plat3.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape pared1(sf::Vector2f(8,480));
    pared1.setOrigin(4,240);
    pared1.setPosition(4,240);
    pared1.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape pared2(sf::Vector2f(8,480));
    pared2.setOrigin(4,240);
    pared2.setPosition(636,240);
    pared2.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape suelo(sf::Vector2f(640,8));
    suelo.setOrigin(320,4);
    suelo.setPosition(320,476);
    suelo.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape techo(sf::Vector2f(640,8));
    techo.setOrigin(320,4);
    techo.setPosition(320,4);
    techo.setFillColor(sf::Color::Blue);
    
    Npc3 npc3(200,150);
    Npc1 npc1(300,350);
    
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
                            pj.move(mVel,0);
                        break;

                        case sf::Keyboard::Left:
                            pj.move(-mVel,0); 
                        break;
                        
                        case sf::Keyboard::Up:
                            pj.move(0,-mVel); 
                        break;
                        
                        case sf::Keyboard::Down:
                            pj.move(0,mVel); 
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
        
        //CONTROL DE CAMBIO ANIMACION 
        
        sf::Time tiempo_max = sf::milliseconds(tMax);
        
        if(clock.getElapsedTime() > tiempo_max){
            npc3.actualizarSprite();
            npc1.actualizarSprite();
            clock.restart();
        }
        //FIN 
        
        npc3.movimiento(plat3);
        npc1.movimiento(plat1);
        
        //Bucle de obtención de eventos
        window.clear();
        window.draw(plat1);
        window.draw(plat3);
        window.draw(npc3.getSprite());
        window.draw(npc1.getSprite());
        window.draw(pared1);
        window.draw(pared2);
        window.draw(suelo);
        window.draw(techo);
        window.draw(pj);
        
        //DIBUJAR COLISIONADORES
       
        window.draw(npc3.getBox_up());
        window.draw(npc3.getBox_right());
        window.draw(npc3.getBox_left());
        window.draw(npc1.getBox_up());
        window.draw(npc1.getBox_right());
        window.draw(npc1.getBox_left());
       
        
        window.display();
    }

    return 0;
}

