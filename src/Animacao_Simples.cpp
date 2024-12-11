#include "Animacao_Simples.h"

namespace ElementosGraficos{
    
    Animacao_Simples::Animacao_Simples(){}

    Animacao_Simples::Animacao_Simples(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho, float escala):
    textura(NULL), corpo(sf::Vector2f(tamanho.x, tamanho.y)){
        textura = ger::Gerenciador_Grafico::getInstancia()->carregarTextura(caminho);
        corpo.setPosition(sf::Vector2f(posicao.x,posicao.y));
        corpo.setScale(sf::Vector2f(escala, escala));
        corpo.setTexture(textura);
    }

    Animacao_Simples::~Animacao_Simples() {}

    void Animacao_Simples::atualizar(sf::Vector2f pos){
        corpo.setPosition(sf::Vector2f(pos.x, pos.y));
    }

    void Animacao_Simples::desenhar(){
        ger::Gerenciador_Grafico::getInstancia()->desenhar(&corpo);
    }
}
