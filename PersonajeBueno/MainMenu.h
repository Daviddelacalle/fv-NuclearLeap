/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.h
 * Author: natalia
 *
 * Created on 29 de abril de 2018, 9:12
 */

#ifndef MAINMENU_H
#define MAINMENU_H
#include "config.h"
#include "Mi_Sprite.h"

class MainMenu {
public:
    MainMenu();
    MainMenu(const MainMenu& orig);
    virtual ~MainMenu();
     void draw();
   // void MoveUp();
   // void MoveDown();
   // int GetPressedItem();
   // int update();
  
     
private:
    Mi_Sprite sprite;
   // int selectedItemIndex;   
   
    
};

#endif /* MAINMENU_H */

