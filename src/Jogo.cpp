#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Personagem.h"
#include "Jogador.h"
//...

Jogo::Jogo(){
    srand(time(NULL));
    gG = new ger::Gerenciador_Grafico();
   // e = new Ente(gG);
    j = new pers::Jogador (sf::Vector2f(20.f, 20.f),sf::Vector2f(20.f, 20.f), vazio);

    executar();
}

Jogo::~Jogo(){
   // delete e;
    delete j;
    delete gG;
    //e = NULL;
    gG = NULL;
    j = NULL;
}

void Jogo::moveEntes(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            j->mover(sf::Keyboard::A);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            j->mover(sf::Keyboard::D);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            j->mover(sf::Keyboard::W);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            j->mover(sf::Keyboard::S);
        }
}

void Jogo::executar(){
    if(gG){
        j->setpGG(gG);
        j->setTarget();
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
            gG->desenharEnte(static_cast<Ente*>(j));

            // Exibir a janela
            gG->getJanela()->display();
        }
    }

}
