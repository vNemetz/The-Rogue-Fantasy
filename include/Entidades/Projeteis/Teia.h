#pragma once

#include "Entidades/Projeteis/Projetil.h"

namespace ent {
namespace prj {

class Teia : public Projetil {
private:
    ElementosGraficos::Animacao animacao;

public:
    Teia();
    Teia(sf::Vector2f pos, sf::Vector2f esc, bool aDireita);
    ~Teia();

    void executar();
    void mover();

    void emColisaoPersonagem(pers::Personagem* sofredor);
    void emColisaoObstaculo();
};

}
}