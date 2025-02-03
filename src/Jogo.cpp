#include "Jogo.h"
#include "Ente.h"

Jogo::Jogo():
     gerGrafico(ger::Gerenciador_Grafico::getInstancia())
    , gerEventos(ger::Gerenciador_Eventos::getInstancia())
    , gerEstados(ger::Gerenciador_Estados::getInstancia())

{
    srand(time(NULL));
    Ente::setPGG(gerGrafico);
    gerEstados->inicializarEstados(); /*NUNCA colocar esse método na construtora de GerEstados (seg fault)*/

    executar();
}

Jogo::~Jogo() {
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerEstados = nullptr;
}

void Jogo::executar() {
    while (gerGrafico->getJanelaAberta()) {
        gerEventos->gerenciar(); // Gerencia os eventos

        gerGrafico->limpaJanela(); // Limpa a janela
        
        gerEstados->requererEstado();
        
        gerGrafico->updateDeltaTime(); // Atualiza o tempo
        gerGrafico->display(); // Exibe a janela
    }
}