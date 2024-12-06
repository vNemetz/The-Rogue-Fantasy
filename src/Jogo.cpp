#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
//...

Jogo::Jogo(){
    srand(time(NULL));
    gG = new ger::Gerenciador_Grafico();
    e = new Ente(gG);

    executar();
}

Jogo::~Jogo(){
    delete e;
    delete gG;
    e = NULL;
    gG = NULL;
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

        // Desenhar o sprite
        gG->desenharEnte(e);

        // Exibir a janela
        gG->getJanela()->display();
        }
    }

}
