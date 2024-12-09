#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Personagem.h"
#include "Jogador.h"
//...

Jogo::Jogo() 
: gerGrafico(ger::Gerenciador_Grafico::getInstancia()){
    srand(time(NULL));
    gerEventos = new ger::Gerenciador_Eventos(gerGrafico);
   // e = new Ente(gerGrafico);
    jogador = new pers::Jogador (sf::Vector2f(20.f, 20.f),sf::Vector2f(20.f, 20.f), vazio);

    executar();
}

Jogo::~Jogo(){
   // delete e;
    delete jogador;
    delete gerGrafico;
    delete gerEventos;
    //e = NULL;
    gerGrafico = NULL;
    gerEventos = NULL;
    jogador = NULL;
}

void Jogo::moveEntes(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            jogador->mover(sf::Keyboard::A);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            jogador->mover(sf::Keyboard::D);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            jogador->mover(sf::Keyboard::W);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            jogador->mover(sf::Keyboard::S);
        }
}

void Jogo::executar(){
    if(gerGrafico){
        jogador->setpGG(gerGrafico);
        jogador->setTarget();

        // Loop principal do jogo
        while (gerGrafico->getJanelaAberta()) {
            // Gerencia os eventos
            gerEventos->gerenciar();

            // Limpar a janela
            gerGrafico->limpaJanela();
            moveEntes();
            // Desenhar o jogador (ente)
            gerGrafico->desenharEnte(static_cast<Ente*>(jogador));

            // Exibir a janela
            gerGrafico->getJanela()->display();
        }
    }
}