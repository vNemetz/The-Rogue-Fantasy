#include "Jogo.h"
#include "Ente.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
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

    executar();
}

Jogo::~Jogo() {
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerEstados = nullptr;
    delete faseFloresta;
}

void Jogo::criarFase() {
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
        
        faseFloresta->executar(); // Executa a fase

        gerGrafico->centralizarVista(faseFloresta->getJogador1()); // Centraliza o campo de visão no jogador
        gerGrafico->updateDeltaTime(); // Atualiza o tempo
        gerGrafico->display(); // Exibe a janela
    }
}