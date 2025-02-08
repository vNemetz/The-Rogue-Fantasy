#include "Estados/Menus/Menu.h"

namespace menus{

Menu::Menu(int min, int max, tipoEstado tipo):
Estado(tipo)
,pTexturaFundo(nullptr)
,pSpriteFundo(nullptr)
,vetorBotoes()
,minimo(min)
,maximo(max)
,botaoSelecionado(0)
{
    limparVetorBotoes();
    it = vetorBotoes.begin();
    pTexturaFundo = new sf::Texture();
    pSpriteFundo = new sf::Sprite();
}

Menu::Menu(ger::Gerenciador_Estados* pGE, int min, int max, tipoEstado tipo):
Estado(tipo,pGE)
,pTexturaFundo(nullptr)
,pSpriteFundo(nullptr)
,vetorBotoes()
,botaoSelecionado(0)
,minimo(min)
,maximo(max)
{
    limparVetorBotoes();
    it = vetorBotoes.begin();
    pTexturaFundo = new sf::Texture();
    pSpriteFundo = new sf::Sprite();
}

Menu::~Menu()
{
    delete pSpriteFundo;
    delete pTexturaFundo;
    limparVetorBotoes();
}

void Menu::alterarBotaoSelecionado(int unidade)
{
    if(unidade == 1 && botaoSelecionado != maximo && bufferTime > 0.13f){ 
        vetorBotoes[botaoSelecionado]->setTextura("Brown-Button");
        vetorBotoes[++botaoSelecionado]->setTextura("Yellow-Button");
        bufferTime = 0;
    }
    else if(unidade == (-1) && botaoSelecionado != minimo && bufferTime > 0.13f){
        vetorBotoes[botaoSelecionado]->setTextura("Brown-Button");
        vetorBotoes[--botaoSelecionado]->setTextura("Yellow-Button");
        bufferTime = 0;
    }
}



void Menu::setTexturaFundo(std::string nomeImg)
{
    pTexturaFundo = ger::Gerenciador_Grafico::getInstancia()->getTextura(nomeImg);
    setSpriteFundo();
}

void Menu::setSpriteFundo()
{
    pSpriteFundo->setTexture(*pTexturaFundo, false);
    sf::Vector2u tamanhoFundo = pTexturaFundo->getSize();
    sf::Vector2u tamanhoJanela = ger::Gerenciador_Grafico::getInstancia()->getJanela()->getSize();
    pSpriteFundo->setScale(
        static_cast<float>(tamanhoJanela.x) / tamanhoFundo.x,
        static_cast<float>(tamanhoJanela.y) / tamanhoFundo.y
    );
    //pSpriteFundo->setPosition(-565,-270);
}


void Menu::limparVetorBotoes()
{
    for(it = vetorBotoes.begin(); it != vetorBotoes.end(); it++){
        if(*it){
            delete *it;
        }
    }
    vetorBotoes.clear();
}

void Menu::adicionarBotao(std::string nomeImg, sf::Vector2f escala, std::string text, sf::Vector2f pos)
{
    ElementosGraficos::Botao* novoBotao = new ElementosGraficos::Botao(nomeImg);
    novoBotao->setEscala(escala);
    novoBotao->setPosicao(pos);
    novoBotao->setTexto(text, sf::Vector2f(1.5f, 1.5f));
    vetorBotoes.push_back(novoBotao);
}


void Menu::desenharBotoes()
{
    for(it = vetorBotoes.begin(); it != vetorBotoes.end(); it++){
        if(*it){
            ger::Gerenciador_Grafico::getInstancia()->desenharSprite((*it)->getSprite());
            ger::Gerenciador_Grafico::getInstancia()->desenharTexto((*it)->getTexto());
        }
    }
}

void Menu::checarBotoes(){
        for(it = vetorBotoes.begin(); it != vetorBotoes.end(); it++){
            if(*it){
                (*it)->checarApertado();
            }
        }
}

void Menu::desenhar()
{
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->desenharSprite(pSpriteFundo);
    desenharBotoes();
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());

}
}

 void menus::Menu::executar()
{
    desenhar();
    bufferTime +=ger::Gerenciador_Grafico::getInstancia()->getDeltaTime();
}
