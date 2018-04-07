#include <iostream>
#include <SFML/Graphics.hpp>

#include "State.h"

#define kVel 10
#define UPDATE_TICK_TIME 1000/15

using namespace std;
void updateGameStateTICK(State &_lastState, State &_newState,float timeElapsed);

void updateGameStateTICK(State &_lastState, State &_newState,float timeElapsed){
    
    int posx;
    int posy;
    
    posx = _lastState.getPosx() + (kVel);
    posy = _lastState.getPosy() + (kVel);
    /*
    posx = _lastState.getPosx() + (kVel*timeElapsed + 0.5f);
    posy = _lastState.getPosy() + (kVel*timeElapsed + 0.5f);
    */
    _newState.setPosx(posx);
    _newState.setPosy(posy);
}
void renderWithInterpolation(sf::RenderWindow &_window, State _lastState, State _newState, float _percentTick, sf::RectangleShape &_pj);

void renderWithInterpolation(sf::RenderWindow &_window, State _lastState, State _newState, float _percentTick, sf::RectangleShape &_pj){
    _window.clear();
   
    int posx = _lastState.getPosx()*(1-_percentTick) + _newState.getPosx() * _percentTick;
    int posy = _lastState.getPosy()*(1-_percentTick) + _newState.getPosy() * _percentTick;
    
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
    sf::Time timeElapsed = sf::seconds(0);
    State newState =  State(posx,posy);
    State lastState =  State(posx,posy);
    //Bucle del juego
    while (window.isOpen())
    {
        //input = getInput(window);
        //Bucle de obtención de eventos

        if(updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
            lastState.setPosx(newState.getPosx());
            lastState.setPosy(newState.getPosy());
            timeElapsed = updateClock.restart();
            
            updateGameStateTICK(lastState,newState,timeElapsed.asSeconds());
            //firsTime = false;
        }
        
        float division = (float)updateClock.getElapsedTime().asMilliseconds()/UPDATE_TICK_TIME;
        float percentTick = minimo(1.f, division);
        
        renderWithInterpolation(window,lastState,newState,percentTick,pj);
        
    }

    return 0;
}