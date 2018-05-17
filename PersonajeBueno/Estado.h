/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: natalia
 *
 * Created on 16 de mayo de 2018, 15:20
 */

#ifndef ESTADO_H
#define ESTADO_H

class Estado {
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
    virtual void Update(int dt) = 0;
    virtual void Draw() = 0;
    virtual void Pause() { }
    virtual void Resume() { }
private:
    
};


#endif /* ESTADO_H */

