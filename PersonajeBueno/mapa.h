/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mapa.h
 * Author: javi
 *
 * Created on 17 de abril de 2018, 11:20
 */

#ifndef MAPA_H
#define MAPA_H
#include "config.h"
#include "Rads.h"
#include <string>
#include <sstream> 

class Mapa: public sf::Drawable {
public:
    static Mapa* Instance();
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void activarCapa(int);
    int getTile(float, float);
    int getAltura();
    sf::Sprite getFondo();
    int getCoordenadas(int,int);
    void setFondo(int);
    int getAltZonas(int);
    int bloqRandom(std::vector<int>);
    
    
    vector<Rads*> getRads();
    void recogerRads(Mi_Sprite &_pj, int &_puntuacion);
    
protected:
    Mapa();
    Mapa(const Mapa & );
    Mapa &operator= (const Mapa & );
private:
    vector<Rads*> mivector;
    
    static Mapa* pinstance;
    int capa, _height, _width;
    int ***_tilemap;
    sf::Sprite ****_tilemapSprite;
    sf::Sprite fondo;
    sf::Texture tex_fondo, tex_plat ;
    const static int zonas=2 , sec_zona=2,  bloq_seccion=3;
    int alturas[zonas * sec_zona * bloq_seccion * 2];
    int alturasZonas[zonas];
    std::string fondos[zonas];
};

#endif /* MAPA_H */

