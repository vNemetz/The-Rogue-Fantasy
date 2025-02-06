#include "Estados/Menus/Menu_Fim.h"


menus::Menu_Fim::Menu_Fim():
    Menu_Fim(nullptr, nullptr)
{
}

menus::Menu_Fim::Menu_Fim(ger::Gerenciador_Estados *pGE, fases::Fase *fase):
    Menu(pGE, 0, 1, fim)
    , pFase(fase)
    , titulo(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "VOCÊ MORREU!", sf::Vector2f(2.0,2.0))
    , nome(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "Nome:  ")
    , nomeJogador(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "")
    , pontos(ger::Gerenciador_Grafico::getInstancia()->getFonte())
    , pontosParaIncrementar(0)
{
}

menus::Menu_Fim::~Menu_Fim()
{
}

void menus::Menu_Fim::escreverNoArquivo()
{
}

void menus::Menu_Fim::executar()
{
}
