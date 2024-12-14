#pragma once

#include "Jogo.h"
#include "Gerenciadores/Gerenciador_Grafico.h"

namespace ElementosGraficos{
class Animacao_Simples{
private:
    sf::Texture* textura;
    sf::RectangleShape corpo;
public:
    Animacao_Simples();
    Animacao_Simples(const char* caminho = "", sf::Vector2f posicao = sf::Vector2f(0,0), sf::Vector2f tamanho = sf::Vector2f(0,0), float escala = 0);
    ~Animacao_Simples();

    void atualizar(sf::Vector2f pos);
    void desenhar();
};
}