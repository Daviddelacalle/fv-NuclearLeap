#include <iostream>
#include <SFML/Graphics.hpp>

#include "State.h"

#define kVel 5
#define UPDATE_TICK_TIME 1000/15

using namespace std;
State updateGameStateTICK(State _lastState);

State updateGameStateTICK(State _lastState){
    
    int posx;
    int posy;
    
    posx = _lastState.getPosx() + kVel;
    posy = _lastState.getPosy() + kVel;
    
    State newState = State(posx,posy);
    return newState;
}
void renderWithInterpolation(sf::RenderWindow &_window, State _lastState, State _newState, float _percentTick, sf::RectangleShape &_pj);

void renderWithInterpolation(sf::RenderWindow &_window, State _lastState, State _newState, float _percentTick, sf::RectangleShape &_pj){
    _window.clear();
    
    float posx = _lastState.getPosx()*(1-_percentTick) + _newState.getPosx() * _percentTick;
    float posy = _lastState.getPosy()*(1-_percentTick) + _newState.getPosy() * _percentTick;
    
    _pj.setPosition(posx,posy);
    
    _window.draw(_pj);
    _window.display();
}


float minimo(float a, float b){
    float res;
    if (b < a ){
        res = b;
    }
    if (a <= b ){
        res = a;
    }
    return res;
}
int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
    
    window.setFramerateLimit(60);
    
    sf::Clock clock;
    sf::Clock updateClock;
    
    //INICIALIZAR

    int posx = 20;
    int posy = 20;
    sf::RectangleShape pj = sf::RectangleShape(sf::Vector2f(32,32));
    pj.setFillColor(sf::Color::Green);
    //Le pongo el centroide donde corresponde
    pj.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    // Lo dispongo en el centro de la pantalla
    pj.setPosition(posx, posy);

    //FIN INICIALIZAR
    
    bool firsTime = true;
    int input;
    
    State newState =  State(posx,posy);
    State lastState =  State(posx,posy);
    //Bucle del juego
    while (window.isOpen())
    {
        //input = getInput(window);
        //Bucle de obtención de eventos

        if(updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
            lastState = newState;
            sf::Time timeElapsed = updateClock.restart();
            
            newState = updateGameStateTICK(lastState);
            //firsTime = false;
        }
        
        float percentTick = minimo(1.f, updateClock.getElapsedTime().asMilliseconds()/UPDATE_TICK_TIME);
        
        renderWithInterpolation(window,lastState,newState,percentTick,pj);
        
    }

    return 0;
}