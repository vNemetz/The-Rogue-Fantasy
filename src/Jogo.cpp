#include "Jogo.h"
#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Goblin.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
//...

Jogo::Jogo()
: gerGrafico(ger::Gerenciador_Grafico::getInstancia())
, gerEventos(ger::Gerenciador_Eventos::getInstancia())
, listaEntidades()
{
    srand(time(NULL));

    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    listaEntidades.limpar();
    
    jogador = nullptr;
    gerGrafico = nullptr;
    gerEventos = nullptr;
}

void Jogo::inicializaEntidades() {
    jogador = new ent::pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f));
    jogador->setpGG(gerGrafico);
    jogador->setTextura("/assets/images/Rogue/rogue.png");
    jogador->setVelocidade(sf::Vector2f(0.125f, 0.125f));

    // Inclui jogador nos gerenciadores
    gerEventos->setJogador(jogador);
    ger::Gerenciador_Input::getInstancia()->setJogador(jogador);

    // Criação do Goblin
    ent::pers::Goblin* goblin = new ent::pers::Goblin(sf::Vector2f(HEIGHT/2.0+600.f, WIDTH/2.0),sf::Vector2f(20.f, 20.f), jogador);
    goblin->setTextura("/assets/images/Goblin/0goblin.png");
    goblin->setVelocidade(sf::Vector2f (0.05f, 0.05f));

    // Criação da Plataforma
    ent::obs::Plataforma* obstaculo = new ent::obs::Plataforma(sf::Vector2f(HEIGHT/2.0, WIDTH/2.0+250.f), sf::Vector2f(20.f, 20.f), false, 50);
    obstaculo->setTextura("/assets/images/Tiles/Ground_grass_0001_tile.png");

    listaEntidades.incluir(static_cast<ent::Entidade*>(jogador));
    listaEntidades.incluir(static_cast<ent::Entidade*>(goblin));
    listaEntidades.incluir(static_cast<ent::Entidade*>(obstaculo));
}

void Jogo::atualizaEntidades() {
    listaEntidades.percorrer();
}

void Jogo::executar() {

    // Loop Principal
    
    while (gerGrafico->getJanelaAberta()) {
        // Gerencia os eventos
        gerEventos->gerenciar();

        // Limpa a janela
        gerGrafico->limpaJanela();
        
        // Atualiza e Desenha as Entidades
        atualizaEntidades();

        // Centraliza o campo de visão no jogador
        gerGrafico->centralizarVista(jogador);

        // Exibe a janela
        gerGrafico->display();
    }
}
