#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Grafico.h"
namespace ElementosGraficos{

class Botao{
private:
    sf::Texture* pTextura;  /*Elementos Gráficos do Botão*/
    sf::Sprite* pSprite;

   sf::Text* textoBotao;
    ger::Gerenciador_Grafico* pGrafico;

    sf::Vector2u tamanho;
    bool apertado;

public:
    Botao();
    Botao(std::string nomeImg);
    ~Botao();


    void setEscala(sf::Vector2f escala);
    sf::Vector2u getTamanho() const;
    void setTextura(std::string nomeImagem);
    void setSprite();
    sf::Sprite* getSprite() const;
    void setPosicao(sf::Vector2f pos);
    void setTexto(std::string text, sf::Vector2f escala);
    sf::Text* getTexto() const;


};
}
