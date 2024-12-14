#include "Jogo.h"
#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Inimigo.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
//...

Jogo::Jogo()
: gerGrafico(ger::Gerenciador_Grafico::getInstancia())
, gerEventos((ger::Gerenciador_Eventos::getInstancia()))
, listaEntidades()
{
    srand(time(NULL));

    jogador = new ent::pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f));
    
    inimigo = new ent::pers::Inimigo(sf::Vector2f(HEIGHT/2.0+600.f, WIDTH/2.0),sf::Vector2f(20.f, 20.f), jogador);
    
    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    listaEntidades.limpar();
    
    delete jogador;
    delete inimigo;

    inimigo = nullptr;
    jogador = nullptr;
    gerGrafico = nullptr;
    gerEventos = nullptr;
}

void Jogo::inicializaEntidades() {
    jogador->setpGG(gerGrafico);
    jogador->setTarget();
    jogador->setTextura(gerGrafico->carregarTextura("/assets/images/Rogue/rogue.png"));
    jogador->setVelocidade(sf::Vector2f(0.125f, 0.125f));

    inimigo->setpGG(gerGrafico);
    inimigo->setTarget();
    inimigo->setTextura(gerGrafico->carregarTextura("/assets/images/Goblin/0goblin.png"));
    inimigo->setVelocidade(sf::Vector2f (0.05f, 0.05f));

    listaEntidades.incluir(static_cast<ent::Entidade*>(jogador));
    listaEntidades.incluir(static_cast<ent::Entidade*>(inimigo));
}

void Jogo::atualizaEntidades() {
    listaEntidades.percorrer();
}

void Jogo::executar(){
    
    // Inclui jogador nos gerenciadores
    gerEventos->setJogador(jogador);
    ger::Gerenciador_Input::getInstancia()->setJogador(jogador);

    // Loop principal do jogo
    while (gerGrafico->getJanelaAberta()) {
        // Gerencia os eventos
        gerEventos->gerenciar();

        // Limpar a janela
        gerGrafico->limpaJanela();
        
        // Atualiza as Entidades
        atualizaEntidades();
        
        // Centraliza o campo de visão no jogador
        gerGrafico->centralizarVista(static_cast<Ente*>(jogador));
        
        // Desenhar o jogador (ente)
        gerGrafico->desenharEnte(static_cast<Ente*>(jogador));
        gerGrafico->desenharEnte(static_cast<Ente*>(inimigo));

        // Exibir a janela
        gerGrafico->display();
    }
}