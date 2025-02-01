#include "Estados/Menus/Menu_Pausa.h"



menus::Menu_Pausa::Menu_Pausa():
    Menu(nullptr, 0, 2, pausa)
    ,pFase(nullptr)
    ,pMenuPrincipal(nullptr)
{

    setTexturaFundo("Menu-bg");
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f,
        HEIGHT/2.0f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "VOLTAR AO JOGO",posicaoBotao);
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f+ 100.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "AJUSTES", sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f+ 200.0f));

}

menus::Menu_Pausa::Menu_Pausa(ger::Gerenciador_Estados* pGE):
    Menu(pGE,0, 2, pausa)
    ,pFase(nullptr)
    ,pMenuPrincipal(nullptr)
{
    setTexturaFundo("Menu-bg");
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 300.0f,
        HEIGHT/3.0f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "VOLTAR AO JOGO",posicaoBotao);
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "SALVAR", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 150.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MENU PRINCIPAL", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 300.0f));

}

menus::Menu_Pausa::~Menu_Pausa()
{

}

void menus::Menu_Pausa::executarEstado() 
{
    switch (botaoSelecionado){
        case 0:
            pGEstados->setEstadoAtual(fase);
            break;
        case 1:
            pGEstados->setEstadoAtual(salvar);
            break;
        case 2:
            pGEstados->setEstadoAtual(menu);
        default:
            break;
    }
}