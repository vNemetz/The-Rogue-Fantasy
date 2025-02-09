#pragma once

#include "Entidades/Obstáculos/Obstaculo.h"

namespace ent{
namespace obs{

class Espinho : public Obstaculo {
private:
    int dano;

public:
    Espinho();
    Espinho(sf::Vector2f pos, sf::Vector2f tam);
    ~Espinho();

    void executar();
};

}
}
