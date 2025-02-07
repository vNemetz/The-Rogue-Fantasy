#include "Estados/Menus/Menu_Fim.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Gerenciadores/Gerenciador_Input.h"



menus::Menu_Fim::Menu_Fim():
    Menu_Fim(nullptr)
{
}

menus::Menu_Fim::Menu_Fim(ger::Gerenciador_Estados *pGE):
    Menu(pGE, 0, 0, fim)
    , titulo(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "FIM DE JOGO", sf::Vector2f(4.0,4.0))
    , nome(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "Nome:  ", sf::Vector2f(1.8f, 1.8f))
    , nomeJogador(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White, "", sf::Vector2f(1.8f, 1.8f))
    , pontos(ger::Gerenciador_Grafico::getInstancia()->getFonte())
    , pontosParaIncrementar(0)
    , input(nullptr)
{
    input = new controle::Texto_Input();
    input->setAtivo(false);
    ger::Gerenciador_Input::getInstancia()->incluirObservador(static_cast<controle::Observador*>(input));
    limparVetorBotoes();
    setTexturaFundo("Menu-bg");
    sf::Vector2f pos = pSpriteFundo->getPosition();
    sf::Vector2f tam = pSpriteFundo->getGlobalBounds().getSize();
    titulo.setPosicao(sf::Vector2f(pos.x + tam.x/2.0f -500.f , pos.y + tam.y/2.0f - 400.f));
    pontos.setPosicao(sf::Vector2f(pos.x + tam.x/4.0f, pos.y + tam.y/2.0f));
    nome.setPosicao(sf::Vector2f(pos.x + tam.x/4.0f, pos.y + tam.y/2.0f));
    nomeJogador.setPosicao(sf::Vector2f(pos.x + tam.x/2.85f, pos.y + tam.y/2.0f));
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 380.0f,
    HEIGHT/1.4f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "MENU PRINCIPAL", posicaoBotao);

}

menus::Menu_Fim::~Menu_Fim()
{
    limparVetorBotoes();
    delete input;
    input = nullptr;
}

void menus::Menu_Fim::escreverNoArquivo()
{
}
void menus::Menu_Fim::desenhar()
{
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->desenharSprite(pSpriteFundo);
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(nome.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(titulo.getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(pontos.getTexto());
    nomeJogador.atualizaTexto(input->getTexto());
    ger::Gerenciador_Grafico::getInstancia()->desenharTexto(nomeJogador.getTexto());
    desenharBotoes();
 
}


void menus::Menu_Fim::executarEstado(){
    switch (botaoSelecionado){
        case 0:
            input->limpar();
            pGEstados->reiniciarJogo();
            pGEstados->setEstadoAtual(menu);
            break;
        default:
            break;
    }
}

controle::Texto_Input *menus::Menu_Fim::getInput()
{
    if(input){
        return input;
    }return nullptr;
}
void menus::Menu_Fim::ativarBufferTexto(bool alt)
{
    if(alt == true){
    }
    input->setAtivo(alt);
}
