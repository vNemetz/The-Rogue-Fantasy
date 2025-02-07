#include "Estados/Menus/Menu_Fim.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Gerenciadores/Gerenciador_Input.h"



menus::Menu_Fim::Menu_Fim():
    Menu_Fim(nullptr)
{
}

menus::Menu_Fim::Menu_Fim(ger::Gerenciador_Estados *pGE):
    Menu(pGE, 0, 1, fim)
    , titulo(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "VOCÊ MORREU!", sf::Vector2f(2.0,2.0))
    , nome(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "Nome:  ")
    , nomeJogador(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "")
    , pontos(ger::Gerenciador_Grafico::getInstancia()->getFonte())
    , pontosParaIncrementar(0)
    , input()
{
    limparVetorBotoes();
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 380.0f,
    HEIGHT/1.4f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "MENU PRINCIPAL", posicaoBotao);
    ger::Gerenciador_Input::getInstancia()->setMenuFim(this);
}

menus::Menu_Fim::~Menu_Fim()
{
    limparVetorBotoes();
}

void menus::Menu_Fim::escreverNoArquivo()
{
}
void menus::Menu_Fim::desenhar()
{
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(nome.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(titulo.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(pontos.getTexto());
    nomeJogador.atualizaTexto(input.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(nomeJogador.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->desenharSprite(pSpriteFundo);
    desenharBotoes();
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());


}


void menus::Menu_Fim::executarEstado(){
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

void menus::Menu_Fim::ativarBufferTexto(bool alt)
{
    input.setAtivo(alt);
}
