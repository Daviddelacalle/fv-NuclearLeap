/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LoadXML.h
 * Author: natalia
 *
 * Created on 15 de mayo de 2018, 18:11
 */

#ifndef LOADXML_H
#define LOADXML_H
#include "config.h"
#include "Rads.h"
#include "Npc.h"

class LoadXML {
public:
    LoadXML();
    int bloqRandom(std::vector<int>);
private:
    int capa, _height, _width;
    int ***_tilemap;
    sf::Sprite ****_tilemapSprite;
    sf::Sprite fondo;
    sf::Texture tex_fondo, tex_plat ;
    const static int zonas=2 , sec_zona=2,  bloq_seccion=3;
    int alturas[zonas * sec_zona * bloq_seccion * 2];
    int alturasZonas[zonas];
    std::string fondos[zonas];
    
    vector< vector<sf::Sprite> > animRueda;
    vector<sf::Sprite> animFuego;
    
    vector<Rads*> v_rads;
    vector<Npc1*> v_npc1;
    vector<Npc3*> v_npc3;
    vector<Npc5*> v_npc5;

};

#endif /* LOADXML_H */

