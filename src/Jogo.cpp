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
    delete faseFloresta;
}

void Jogo::inicializaEntidades() {

    /* Inclui jogador nos gerenciadores */

    gerEventos->setJogador(faseFloresta->getJogador());
    ger::Gerenciador_Input::getInstancia()->setJogador(faseFloresta->getJogador());

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
        gerGrafico->updateDeltaTime();

        gerGrafico->display(); // Exibe a janela
    }
}