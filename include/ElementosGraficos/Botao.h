#pragma once
#include "Jogo.h"
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
    void setPosicao(sf::Vector2f pos);

};
}
