#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Personagem.h"
//...

Jogo::Jogo(){
    srand(time(NULL));
    gG = new ger::Gerenciador_Grafico();
    e = new Ente(gG);
    p = new pers::Personagem(gG);

    executar();
}

Jogo::~Jogo(){
    delete e;
    delete gG;
    delete p;
    e = NULL;
    gG = NULL;
    p = NULL;
}

void Jogo::moveEntes(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            p->mover(sf::Keyboard::A);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            p->mover(sf::Keyboard::D);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            p->mover(sf::Keyboard::W);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            p->mover(sf::Keyboard::S);
        }
}

void Jogo::executar(){
    if(gG){
        while (gG->getJanela()->isOpen()) {
            sf::Event event;
            while (gG->getJanela()->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    gG->getJanela()->close();
            }

            // Limpar a janela
            gG->getJanela()->clear(sf::Color::Yellow);

            moveEntes();
            // Desenhar o sprite
            gG->desenharEnte(p);

            // Exibir a janela
            gG->getJanela()->display();
        }
    }

}
