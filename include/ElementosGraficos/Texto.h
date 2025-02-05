#pragma once
#include "Jogo.h"
namespace ElementosGraficos{

class Texto{
private:
    std::string string;
    sf::Font* pFonte;
    sf::Color cor;
    sf::Vector2f escala;
    
    sf::Text* pElementoTexto;

public:
    Texto();
    Texto(sf::Font* font = nullptr, sf::Color cor = sf::Color::White, std::string stg = "", sf::Vector2f esc = sf::Vector2f(0.0f, 0.0f));
    ~Texto();

    sf::Text* getTexto() const;
    void setPosicao(sf::Vector2f pos);
    void setTexto();

};


}