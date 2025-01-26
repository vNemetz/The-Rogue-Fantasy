#include "ElementosGraficos/Botao.h"

ElementosGraficos::Botao::Botao(std::string nomeImg):
pTextura(nullptr)
,pSprite(nullptr)
,pGrafico(nullptr)
{
    pTextura = new sf::Texture();
    pSprite = new sf::Sprite();
    setTextura(nomeImg);
}
ElementosGraficos::Botao::Botao():
pTextura(nullptr)
,pSprite(nullptr)
,pGrafico(nullptr)
{
    pTextura = new sf::Texture();
    pSprite = new sf::Sprite();
}
ElementosGraficos::Botao::~Botao()
{
    delete pSprite;
    delete pTextura;
}

void ElementosGraficos::Botao::alterarApertado()
{
    apertado = !apertado;
}

void ElementosGraficos::Botao::setTamanho(sf::Vector2u tam)
{
    tamanho = tam;
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

void ElementosGraficos::Botao::setPosicao(sf::Vector2f pos)
{
    pSprite->setPosition(pos);
}
