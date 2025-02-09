#pragma once

#include "Entidades/Projeteis/Projetil.h"
#include "ElementosGraficos/Animacao.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace prj {

class Teia : public Projetil {
private:
    sf::Vector2f posicaoInicial;
    sf::Vector2f velocidadeInicial;

    ElementosGraficos::Animacao animacao;

public:
    Teia();
    Teia(sf::Vector2f pos, sf::Vector2f esc, bool aDireita);
    ~Teia();

    void executar();
    void mover();
    void setPosicaoInicial(sf::Vector2f posicaoInicial);
    void calcularDano();
};

}
}