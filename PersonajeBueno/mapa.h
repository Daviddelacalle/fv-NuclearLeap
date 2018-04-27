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

class Mapa: public sf::Drawable {
public:
    static Mapa* Instance();
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void activarCapa(int);
    int getTile(float, float);
    int getAltura();
    sf::Sprite getFondo();
     sf::Vector2f getCoordenadas(int); 
    
protected:
    Mapa();
    Mapa(const Mapa & );
    Mapa &operator= (const Mapa & );
private:
    static Mapa* pinstance;
    int capa, _height, _width;
    int ***_tilemap;
    sf::Sprite ****_tilemapSprite;
    sf::Sprite fondo;
    sf::Texture tex_fondo, tex_plat ;
};

#endif /* MAPA_H */

