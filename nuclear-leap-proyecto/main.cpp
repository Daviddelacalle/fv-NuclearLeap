#include "config.h"
#include "Ia.h"

int main()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text puntVidas("0",font);
    puntVidas.setCharacterSize(18);
    puntVidas.setStyle(sf::Text::Bold);
    puntVidas.setColor(sf::Color::White);
    puntVidas.setPosition(35,27);


    
    std::stringstream ss;
    int vidas = 3;
    ss<<vidas;
    puntVidas.setString(ss.str());
    
    //sprite de vidas
    sf::Texture tex;
    sf::Sprite sprite;
    tex.loadFromFile("sprites/vida.png");
    
    sprite =sf::Sprite(tex);
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(85,75);
    sprite.setPosition(40,40);
    sprite.setScale(sf::Vector2f(0.3f, 0.3f));
    
    sf::Clock clock;
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
    
    sf::RectangleShape pj = sf::RectangleShape(sf::Vector2f(32,32));
    pj.setFillColor(sf::Color::Green);
    //Le pongo el centroide donde corresponde
    pj.setOrigin(32/2,32/2);
    //Cojo el sprite que me interesa por defecto del sheet
    // Lo dispongo en el centro de la pantalla
    pj.setPosition(320, 240);
    
    //sf::RectangleShape plataformas[2];
    
    vector<sf::RectangleShape*> plataformas(2);
    
    sf::RectangleShape *plat1 = new sf::RectangleShape(sf::Vector2f(250,12));
    plat1->setOrigin(100,6);
    plat1->setPosition(400,362);
    plat1->setFillColor(sf::Color::Blue);
    plataformas[0] = plat1;
    
    sf::RectangleShape *plat3 = new sf::RectangleShape(sf::Vector2f(250,12));
    plat3->setOrigin(100,6);
    plat3->setPosition(200,186);
    plat3->setFillColor(sf::Color::Blue);
    plataformas[1] = plat3;
    
    sf::RectangleShape pared1(sf::Vector2f(8,480));
    pared1.setOrigin(4,240);
    pared1.setPosition(4,240);
    pared1.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape pared2(sf::Vector2f(8,480));
    pared2.setOrigin(4,240);
    pared2.setPosition(636,240);
    pared2.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape suelo(sf::Vector2f(640,8));
    suelo.setOrigin(320,4);
    suelo.setPosition(320,476);
    suelo.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape techo(sf::Vector2f(640,8));
    techo.setOrigin(320,4);
    techo.setPosition(320,4);
    techo.setFillColor(sf::Color::Blue);
    
    Npc3 npc3(200,150);
    Npc1 *npc1 = new Npc1(300,350);
    Npc5 npc5(200,400);
    
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
                            pj.move(mVel,0);
                        break;

                        case sf::Keyboard::Left:
                            pj.move(-mVel,0); 
                        break;
                        
                        case sf::Keyboard::Up:
                            pj.move(0,-mVel); 
                        break;
                        
                        case sf::Keyboard::Down:
                            pj.move(0,mVel); 
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
        
        //CONTROL DE CAMBIO ANIMACION 
        
        sf::Time tiempo_max = sf::milliseconds(tMax);
        
        if(clock.getElapsedTime() > tiempo_max){
            npc5.actualizarSprite();
            npc3.actualizarSprite();
            if(npc1!=NULL){
                npc1->actualizarSprite();
            }
            clock.restart();
        }
        
        //FIN 
       
        if(npc1!=NULL){
            if(pj.getGlobalBounds().intersects(npc1->getBox_up().getGlobalBounds())){
                delete npc1;
                npc1 = NULL;
            }
        }
        
         if(npc1 != NULL){
            if(npc1->getSprite().getGlobalBounds().intersects(pj.getGlobalBounds())){
                if(vidas == 1){
                    cout << "HAS PERDIDO \n";
                    window.close();
                }
                else{
                    vidas = vidas-1;
                    std::stringstream ss;
                    ss<<vidas;
                    puntVidas.setString(ss.str());
                    pj.setPosition(320,240);
                    npc1 = new Npc1(300,350);
                    npc3.setPosition(200,150);
                    npc5.setPosition(200,400);
                }
                
            }
        }
        
        if(npc3.getSprite().getGlobalBounds().intersects(pj.getGlobalBounds()) || npc5.getSprite().getGlobalBounds().intersects(pj.getGlobalBounds())){
                if(vidas == 1){
                    cout << "HAS PERDIDO \n";
                    window.close();
                }
                else{
                    vidas = vidas-1;
                    std::stringstream ss;
                    ss<<vidas;
                    puntVidas.setString(ss.str());
                    pj.setPosition(320,240);
                    npc1 = new Npc1(300,350);
                    npc3.setPosition(200,150);
                    npc5.setPosition(200,400);
                }
                
            }
        
        
        
        npc3.movimiento(*plataformas[1]);
        if(npc1!=NULL){
            npc1->movimiento(*plataformas[0]);
        }
        
        npc5.movimiento(pj,plataformas);
        
        //Bucle de obtención de eventos
        window.clear();
        
        auto it = plataformas.begin();
        
        for(it = plataformas.begin(); it != plataformas.end(); it++){
            sf::RectangleShape *tmp = *it;
            window.draw(*tmp);
        }
        
        window.draw(npc3.getSprite());
        if(npc1!=NULL){
            window.draw(npc1->getSprite());
        }
        window.draw(npc5.getSprite());
        
        window.draw(pared1);
        window.draw(pared2);
        window.draw(suelo);
        window.draw(techo);
        
        window.draw(pj);
        
        //DIBUJAR COLISIONADORES
       
        
        window.draw(npc5.getBox_up());
        window.draw(npc5.getBox_right());
        window.draw(npc5.getBox_left());
        window.draw(npc5.getBox_down());
        window.draw(npc3.getBox_up());
        window.draw(npc3.getBox_right());
        window.draw(npc3.getBox_left());
        
        if(npc1 != NULL){
            window.draw(npc1->getBox_up());
            window.draw(npc1->getBox_right());
            window.draw(npc1->getBox_left());
        }
        
        
        window.draw(sprite);
        window.draw(puntVidas);
        window.display();
    }

    return 0;
}

