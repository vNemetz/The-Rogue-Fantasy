#include "ElementosGraficos/Botao.h"
#include <iostream>


ElementosGraficos::Botao::Botao():
pTextura(nullptr)
,pSprite(nullptr)
,pGrafico(ger::Gerenciador_Grafico::getInstancia())
{
    pTextura = new sf::Texture();
    pSprite = new sf::Sprite();
    textoBotao = new sf::Text();
    textoBotao->setFont(*ger::Gerenciador_Grafico::getInstancia()->getFonte());
}
ElementosGraficos::Botao::Botao(std::string nomeImg):
pTextura(nullptr)
,pSprite(nullptr)
,pGrafico(ger::Gerenciador_Grafico::getInstancia())
,textoBotao(nullptr)
{
    pTextura = new sf::Texture();
    pSprite = new sf::Sprite();
    textoBotao = new sf::Text();
    textoBotao->setFont(*ger::Gerenciador_Grafico::getInstancia()->getFonte());
    setTextura(nomeImg);
}
ElementosGraficos::Botao::~Botao()
{
    delete pSprite;
    delete pTextura;
    pSprite = nullptr;
    pTextura = nullptr;
    pGrafico = nullptr;
    delete textoBotao;
}

void ElementosGraficos::Botao::alterarApertado()
{
    apertado = !apertado;
}

void ElementosGraficos::Botao::setEscala(sf::Vector2f escala)
{
    pSprite->setScale(escala);
}

sf::Vector2u ElementosGraficos::Botao::getTamanho() const
{
    return tamanho;
}

void ElementosGraficos::Botao::setTextura(std::string nomeImagem)
{
    pTextura = ger::Gerenciador_Grafico::getInstancia()->getTextura(nomeImagem);
    tamanho = pTextura->getSize();
    setSprite();
}

void ElementosGraficos::Botao::setSprite()
{
    pSprite->setTexture(*pTextura, false);
}

sf::Sprite *ElementosGraficos::Botao::getSprite() const
{
    if(pSprite){
        return pSprite;
    }
    return nullptr;
}

void ElementosGraficos::Botao::setPosicao(sf::Vector2f pos)
{
    pSprite->setPosition(pos);
}

void ElementosGraficos::Botao::setTexto(std::string text, sf::Vector2f escala)
{
    textoBotao->setString(text);
    textoBotao->setScale(escala);
    sf::Vector2f tamanhoFonte = textoBotao->getGlobalBounds().getSize();
    textoBotao->setPosition(sf::Vector2f(pSprite->getPosition().x+pSprite->getGlobalBounds().getSize().x/2.0f - tamanhoFonte.x /2.0f,
        pSprite->getPosition().y+pSprite->getGlobalBounds().getSize().y/2.4f - tamanhoFonte.y / 2.0f));
}

sf::Text* ElementosGraficos::Botao::getTexto() const
{
    if(textoBotao){
    return textoBotao;
    }return nullptr;
    
}

bool ElementosGraficos::Botao::checarApertado() const
{
    return false;
}
