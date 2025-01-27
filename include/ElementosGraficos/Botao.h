#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Grafico.h"
namespace ElementosGraficos{

class Botao{
private:
    sf::Texture* pTextura;
    sf::Sprite* pSprite;
    std::string textoBotao;
    ger::Gerenciador_Grafico* pGrafico;

    sf::Vector2u tamanho;
    bool apertado;

public:
    Botao();
    Botao(std::string nomeImg);
    ~Botao();
    void alterarApertado();
    void setTamanho(sf::Vector2u tam);
    sf::Vector2u getTamanho() const;
    void setTextura(std::string nomeImagem);
    void setSprite();
    sf::Sprite* getSprite() const;
    void setPosicao(sf::Vector2f pos);
    void checarApertado() const;

};
}
