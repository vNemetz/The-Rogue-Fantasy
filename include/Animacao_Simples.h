#pragma once

#include "Jogo.h"

namespace ElementosGraficos{
class Animacao_Simples{
private:
    sf::Texture* textura;
    sf::RectangleShape corpo;
public:
    Animacao_Simples();
    Animacao_Simples(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho, float escala);
    ~Animacao_Simples();

    void atualizar(sf::Vector2f pos);
    void desenhar();
};
}