#include "ElementosGraficos/Texto.h"


namespace ElementosGraficos{

Texto::Texto():
    Texto(nullptr)
{

}

Texto::Texto(sf::Font* font, sf::Color cor, std::string stg, sf::Vector2f esc):
    pFonte(font)
    , cor(cor)
    , string(stg)
    , escala(esc)
{

    pElementoTexto = new sf::Text();
    setTexto();    
}

Texto::~Texto(){
    delete pElementoTexto;
    pElementoTexto = nullptr;
    pFonte = nullptr;
}
}

sf::Text *ElementosGraficos::Texto::getTexto() const
{
    if(pElementoTexto){
        return pElementoTexto;
    }return nullptr;
}

void ElementosGraficos::Texto::setPosicao(sf::Vector2f pos)
{
    if(pElementoTexto)
        pElementoTexto->setPosition(pos);
}
void ElementosGraficos::Texto::setTexto()
{
    if(pFonte)
    pElementoTexto->setFont(*pFonte);
    pElementoTexto->setFillColor(cor);
    pElementoTexto->setString(string);
    pElementoTexto->setScale(escala);

}
