#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace prj {

class Projetil : public Entidade {
protected:
    float dano;
    bool paraDireita;

public:
    Projetil();
    Projetil(sf::Vector2f pos, sf::Vector2f esc, bool aDireita);
    ~Projetil();

    virtual void executar() = 0;

    void setParaDireita(bool paraDireita);
    bool getParaDireita() const;
    void setDano(float dano);
    float getDano() const;
};

}
}