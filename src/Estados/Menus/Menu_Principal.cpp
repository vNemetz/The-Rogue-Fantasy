#include "Estados/Menus/Menu_Principal.h"




menus::Menu_Principal::Menu_Principal():
     Menu(0, 2)
    ,pFase(nullptr)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR", sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f+ 100.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "AJUSTES", sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f+ 200.0f));

}

menus::Menu_Principal::Menu_Principal(ger::Gerenciador_Estados *pGE):
Menu(pGE, 0, 2)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 200.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "AJUSTES", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 400.0f));
}
menus::Menu_Principal::~Menu_Principal()
{
    pFase = nullptr;
}

void menus::Menu_Principal::setFase(fases::Fase *pF)
{
    if(pF){
        this->pFase = pF;
    }
}

void menus::Menu_Principal::executarEstado(tipoEstado tipo)
{
    pGEstados->setEstadoAtual(tipo);
}
