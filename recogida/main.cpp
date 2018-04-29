#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream> 

#include "Rads.h"
#include "Bloque.h"

#define kVel 5

using namespace std;

sf::Text crearPuntuacion();
void actualizarPuntuacion(int,sf::Text &_puntRads);
void recogerRads(vector<Rads*> &_rads, sf::RectangleShape _sprite , int &_nrads);


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
    
    //Rads rads[4] {{200,324,1},{200,348,1},{200,300,1},{100,200,5}};
    
    vector<Rads*> mivector(4);
    
    Rads *rad1 = new Rads(200,324,1);
    mivector[1]=rad1;
    Rads *rad2 = new Rads(200,348,1);
    mivector[2]=rad2;
    Rads *rad3 = new Rads(200,300,1);
    mivector[3]=rad3;
    Rads *rad0 = new Rads(100,200,5);
    mivector[0]=rad0;
    
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
        
        
        recogerRads(mivector,sprite,nrads);
        actualizarPuntuacion(nrads,puntRads);

        window.clear();
        
        auto it = mivector.begin();
    
        for(it = mivector.begin(); it != mivector.end(); it++){
            Rads *tmp = *it;
            window.draw(tmp->getSprite());
        }
        
        window.draw(sprite);
        window.draw(puntRads);
        window.display();
    }

    return 0;
}


Rads::Rads(int _x, int _y , int _puntuacion){
    posx = _x;
    posy = _y;
    
    int tam;
    
    puntuacion = _puntuacion;
    
     if (!tex.loadFromFile("sprites/sprites.png"))
        {
            std::cerr << "Error cargando la imagen sprites.png";
            exit(0);
        }
    
    sprite =sf::Sprite(tex);
    
    if(_puntuacion == 1){
       
        tam = 24;
       sprite.setTextureRect(sf::IntRect(5*32, 0*32, 32, 32));
       
        
    }
    
    if(_puntuacion == 5){
              
        tam = 36;
       
        sprite.setTextureRect(sf::IntRect(6*32, 0*32, 32, 32));
  
    }
    
     //Y creo el spritesheet a partir de la imagen anterior
    
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(tam/2,tam/2);
    //Cojo el sprite que me interesa por defecto del sheet
    
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

void recogerRads(vector<Rads*> &_rads, sf::RectangleShape _sprite, int &_nrads){
    
    
    auto it = _rads.begin();
    
    
    for(it; it != _rads.end(); it++){
        
        Rads *tmp = *it;
         
        
        if(_sprite.getGlobalBounds().intersects(tmp->getSprite().getGlobalBounds())){    
            _nrads = _nrads + tmp->getPuntuacion();           
            _rads.erase(it);       
            delete tmp; 
            break;
        }
        
    }
    
    
    /*
    for(int i = 0; i < 4; i++){
        auto it= _rads.begin() + i;
        Rads *tmp=*it;
       if(true){
           _nrads = _nrads + *it;
           _rads.erase(it);
           delete tmp;
           
       }
    }
    */
}