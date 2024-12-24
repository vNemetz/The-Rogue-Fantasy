#pragma once

#include "Entidades/Obstaculo.h"

namespace ent {
namespace obs {

class Plataforma : public Obstaculo {
private:
    int altura;
    // ...

public:
    Plataforma();
    Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt);
    ~Plataforma();

    void executar();
    void obstacular(pers::Jogador* p);
    void emColisao(Entidade* pE);
    // ...
};

}
}
