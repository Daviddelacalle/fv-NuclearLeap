
#include "State.h"

State::State(int _posx, int _posy){
    posx = _posx;
    posy = _posy;
}

void State::setPosx(int _posx){
    posx = _posx;
}
void State::setPosy(int _posy){
    posy = _posy;
}
int State::getPosx(){
    return posx;
}
int State::getPosy(){
    return posy;
}