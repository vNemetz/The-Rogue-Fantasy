#include "Estados/Menus/Menu.h"



namespace menus{

Menu::Menu():
Estado(menu)
,pTexturaFundo(nullptr)
,pSpriteFundo(nullptr)
,vetorBotoes()
{
    it = vetorBotoes.begin();
    limparVetorBotoes();
    pTexturaFundo = new sf::Texture();
    pSpriteFundo = new sf::Sprite();
}

Menu::Menu(ger::Gerenciador_Estados* pGE):
Estado(menu,pGE)
,pTexturaFundo(nullptr)
,pSpriteFundo(nullptr)
,vetorBotoes()
{
    limparVetorBotoes();
    pTexturaFundo = new sf::Texture();
    pSpriteFundo = new sf::Sprite();
}

Menu::~Menu()
{
    delete pSpriteFundo;
    delete pTexturaFundo;
    limparVetorBotoes();
}

void Menu::alterarAtivo()
{
    ativo = !ativo;
}

bool Menu::getAtivo() const
{
    return ativo;
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
    pSpriteFundo->setPosition(-565,-270);
}

void Menu::setBotaoSelecionado(int botao)
{
    botaoSelecionado = botao;
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

void Menu::adicionarBotao(std::string nomeImg)
{
    ElementosGraficos::Botao* novoBotao = new ElementosGraficos::Botao(nomeImg);
    vetorBotoes.push_back(novoBotao);
}


void Menu::desenharBotoes()
{
    for(it = vetorBotoes.begin(); it != vetorBotoes.end(); it++){
        if(*it){
            ger::Gerenciador_Grafico::getInstancia()->desenharSprite((*it)->getSprite());
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
    ger::Gerenciador_Grafico::getInstancia()->desenharSprite(pSpriteFundo);
    desenharBotoes();

}
}

 void menus::Menu::executar()
{
    desenhar();
}
