#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace obs {

class Obstaculo : public Entidade {
protected:
    bool danoso;

public:
    Obstaculo();
    Obstaculo(sf::Vector2f pos, sf::Vector2f tam, bool dan, ID id);
    ~Obstaculo();

    virtual void executar() = 0;
};

}
}
