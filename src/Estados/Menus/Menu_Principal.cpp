#include "Estados/Menus/Menu_Principal.h"
#include "Gerenciadores/Gerenciador_Estados.h"



menus::Menu_Principal::Menu_Principal():
     Menu(nullptr, 0, 3, menu)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR SOZINHO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MULTIJOGADOR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f+ 200.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/2.0f+ 400.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FECHAR JOGO", sf::Vector2f(WIDTH/2.0f -380.0f, HEIGHT/3.0f+ 600.0f));
}

menus::Menu_Principal::Menu_Principal(ger::Gerenciador_Estados *pGE):
Menu(pGE, 0, 3, menu)
{
    setTexturaFundo("Main-Menu-Bg");
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 380.0f,
        HEIGHT/3.0f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR SOZINHO", posicaoBotao);
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MULTIJOGADOR", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 150.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 300.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FECHAR JOGO",sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 450.0f));
}
menus::Menu_Principal::~Menu_Principal()
{
}



void menus::Menu_Principal::executarEstado()
{
    switch (botaoSelecionado){
        case 0:
            fases::Fase::setMultijogador(false);
            pGEstados->reiniciarJogo();
            pGEstados->setEstadoAtual(fase);
            break;
        case 1:
            fases::Fase::setMultijogador(true);
            pGEstados->reiniciarJogo();
            pGEstados->setEstadoAtual(fase);
            break;
        case 2:
            pGEstados->setEstadoAtual(placar);
            break;
        case 3:
            ger::Gerenciador_Grafico::getInstancia()->fechaJanela();
        default:
            break;
    }

}

