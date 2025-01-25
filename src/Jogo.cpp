#include "Jogo.h"
#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Personagens/Goblin.h"
#include "Entidades/Obstáculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/System/Vector2.hpp>


Jogo::Jogo()
    : gerGrafico(ger::Gerenciador_Grafico::getInstancia())
    , gerEventos(ger::Gerenciador_Eventos::getInstancia())
    , gerEstados(ger::Gerenciador_Estados::getInstancia())
    , faseFloresta(nullptr)
{
    srand(time(NULL));
    Ente::setPGG(gerGrafico);
    criarFase();
    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerEstados = nullptr;
    delete faseFloresta;
}

void Jogo::inicializaEntidades() {
    ent::pers::Jogador* jogador = new ent::pers::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.7f, 1.7f));
    jogador->setTextura("Rogue-Stand");
    jogador->setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));

    /* Inclui jogador nos gerenciadores */
    gerEventos->setJogador(faseFloresta->getJogador());
    ger::Gerenciador_Input::getInstancia()->setJogador(faseFloresta->getJogador());
    ger::Gerenciador_Colisoes::getInstancia()->setJogador(jogador);

}

void Jogo::atualizaEntidades() {
}

void Jogo::criarFase()
{
    if(faseFloresta == nullptr){
        faseFloresta = new fases::Floresta(ger::Gerenciador_Colisoes::getInstancia());
        faseFloresta->criarMapa();
        faseFloresta->criarFundo(); 

    }
}

void Jogo::executar() {

    while (gerGrafico->getJanelaAberta()) {
        gerEventos->gerenciar(); // Gerencia os eventos

        gerGrafico->limpaJanela(); // Limpa a janela
        gerGrafico->getJanela()->setView(gerGrafico->getJanela()->getDefaultView());
        
        faseFloresta->executar();

        gerGrafico->centralizarVista(faseFloresta->getJogador()); // Centraliza o campo de visão no jogador
        gerGrafico->updateDeltaTime(); // Atualiza o tempo
        gerGrafico->display(); // Exibe a janela
    }
}