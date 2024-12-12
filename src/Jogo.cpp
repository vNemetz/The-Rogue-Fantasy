#include "Jogo.h"
#include "Ente.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include "DebugText.h"
//...

Jogo::Jogo()
: gerGrafico(ger::Gerenciador_Grafico::getInstancia())
, gerEventos((ger::Gerenciador_Eventos::getInstancia()))
, listaEntidades()
{
    srand(time(NULL));

    jogador = new ent::pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f), vazio);
    jogador->setpGG(gerGrafico);
    
    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    listaEntidades.limpar();
    
    delete jogador;

    jogador = nullptr;
    gerGrafico = nullptr;
    gerEventos = nullptr;
}

void Jogo::inicializaEntidades() {
    listaEntidades.incluir(static_cast<ent::Entidade*>(jogador));
}

void Jogo::atualizaEntidades() {
    listaEntidades.percorrer();
}

void Jogo::executar(){
    jogador->setTarget();
    listaEntidades.incluir(jogador);

    DebugText debugText;
    
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

        // Atualiza e desenha o texto de debug
        debugText.update(jogador->getPosition(), gerGrafico->getVista());
        debugText.draw(*gerGrafico->getJanela());


        // Exibir a janela
        gerGrafico->display();
    }
}