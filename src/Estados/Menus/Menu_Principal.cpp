#include "Estados/Menus/Menu_Principal.h"
#include "Gerenciadores/Gerenciador_Estados.h"



menus::Menu_Principal::Menu_Principal():
     Menu(nullptr, 0, 3, menu)
    ,pFase(nullptr)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR SOZINHO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MULTIJOGADOR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f+ 200.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "AJUSTES", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f+ 400.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FECHAR JOGO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 600.0f));
}

menus::Menu_Principal::Menu_Principal(ger::Gerenciador_Estados *pGE):
Menu(pGE, 0, 3, menu)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR SOZINHO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MULTIJOGADOR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 150.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "AJUSTES", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 300.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FECHAR JOGO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 450.0f));
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

void menus::Menu_Principal::executarEstado()
{
    switch (botaoSelecionado){
        case 0:
            fases::Fase::setMultijogador(false);
            std::cout << "a\n";
            pGEstados->reiniciarJogo();
            std::cout << "b\n";
            pGEstados->setEstadoAtual(fase);
            std::cout << "c\n";
            break;
        case 1:
            fases::Fase::setMultijogador(true);
            pGEstados->reiniciarJogo();
            pGEstados->setEstadoAtual(fase);
            break;
        case 2:
            pGEstados->setEstadoAtual(config);
            break;
        case 3:
            ger::Gerenciador_Grafico::getInstancia()->fechaJanela();
        default:
            break;
    }

}

