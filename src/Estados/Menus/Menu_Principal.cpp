#include "Estados/Menus/Menu_Principal.h"
#include "Gerenciadores/Gerenciador_Estados.h"



menus::Menu_Principal::Menu_Principal():
    Menu_Principal(nullptr)
{
}

menus::Menu_Principal::Menu_Principal(ger::Gerenciador_Estados *pGE):
Menu(pGE, 0, 5, menu)
,faseSelecionada(0)
{
    setTexturaFundo("Main-Menu-Bg");
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 380.0f,
        HEIGHT/4.5f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "JOGAR SOZINHO", posicaoBotao);
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "MULTIJOGADOR", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 125.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FASE: FLORESTA",sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 250.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "CARREGAR JOGO",sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 375.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "PLACAR", sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 500.0f));
    adicionarBotao("Brown-Button", sf::Vector2f(4.0f, 3.0f), "FECHAR JOGO",sf::Vector2f(posicaoBotao.x, posicaoBotao.y + 625.0f));
}
menus::Menu_Principal::~Menu_Principal()
{
}

void menus::Menu_Principal::executar(){
    pGEstados->reiniciarJogo(faseSelecionada);
    desenhar();
    bufferTime +=ger::Gerenciador_Grafico::getInstancia()->getDeltaTime();
}


void menus::Menu_Principal::executarEstado()
{
    switch (botaoSelecionado){
        case 0:
            fases::Fase::setMultijogador(false);
            pGEstados->reiniciarJogo(faseSelecionada);
            pGEstados->setEstadoAtual(fase);
            break;
        case 1:
            fases::Fase::setMultijogador(true);
            pGEstados->reiniciarJogo(faseSelecionada);
            pGEstados->setEstadoAtual(fase);
            break;
        case 2:
            if(faseSelecionada == 0){
                faseSelecionada = 1;
                vetorBotoes[2]->setTexto("FASE: CASTELO",sf::Vector2f(1.5f, 1.5f));
            }
            else if(faseSelecionada == 1){
                vetorBotoes[2]->setTexto("FASE: FLORESTA",sf::Vector2f(1.5f, 1.5f));
                faseSelecionada = 0;
            }
            break;
        case 3:
            pGEstados->setEstadoAtual(carregar);
            break;
        case 4:
            pGEstados->setEstadoAtual(placar);
            break;
        case 5:
            ger::Gerenciador_Grafico::getInstancia()->fechaJanela();
        default:
            break;
    }

}

