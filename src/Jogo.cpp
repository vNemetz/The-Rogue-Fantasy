#include "Jogo.h"
#include "Ente.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo():
     gerGrafico(ger::Gerenciador_Grafico::getInstancia())
    , gerEventos(ger::Gerenciador_Eventos::getInstancia())
    , gerEstados(ger::Gerenciador_Estados::getInstancia())
    , faseFloresta(nullptr)
    ,menuPrincipal(nullptr)
{
    srand(time(NULL));
    Ente::setPGG(gerGrafico);
    gerEstados->inicializarEstados(); /*NUNCA colocar esse método na construtora de GerEstados (seg fault)*/
    //criarFase();
    //criarMenuPrincipal();


    executar();
}

Jogo::~Jogo() {
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerEstados = nullptr;
    //delete faseFloresta;
    //delete menuPrincipal;
}

void Jogo::criarFase() {
    if(faseFloresta == nullptr){
        faseFloresta = new fases::Floresta(ger::Gerenciador_Colisoes::getInstancia());
        faseFloresta->criarMapa();
        faseFloresta->criarFundo(); 
    }
}

void Jogo::criarMenuPrincipal()
{
    if(menuPrincipal == nullptr){
        menuPrincipal = new menus::Menu_Principal(gerEstados);
    }
}

void Jogo::executar() {
    while (gerGrafico->getJanelaAberta()) {
        gerEventos->gerenciar(); // Gerencia os eventos

        gerGrafico->limpaJanela(); // Limpa a janela
        gerEstados->requererEstado();
        //menuPrincipal->desenhar();
        //faseFloresta->executar(); // Executa a fase

        //gerGrafico->centralizarVista(faseFloresta->getJogador1()); // Centraliza o campo de visão no jogador
        gerGrafico->updateDeltaTime(); // Atualiza o tempo
        gerGrafico->display(); // Exibe a janela
    }
}