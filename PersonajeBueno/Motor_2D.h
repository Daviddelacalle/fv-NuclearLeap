/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor_2D.h
 * Author: pato-pc
 *
 * Created on 25 de abril de 2018, 19:31
 */

#ifndef MOTOR_2D_H
#define MOTOR_2D_H

#include "config.h"

class Motor_2D {
public:
    static Motor_2D* Instance();
protected:
    Motor_2D();
    Motor_2D(const Motor_2D & );
    Motor_2D &operator= (const Motor_2D & );

private: 
    static Motor_2D* pinstance;

};

#endif /* MOTOR_2D_H */

