#pragma once

#include "Entidades/Personagem.h"
#include "Entidades/Obstaculo.h"

namespace ent {
namespace obs {

class Plataforma : public Obstaculo {
private:
    int altura;

public:
    Plataforma();
    Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt);
    ~Plataforma();

    void executar();
    void emColisao(Entidade* pE, sf::Vector2f ds);
    void emColisaoPersonagem(pers::Personagem* pPers, sf::Vector2f ds);
};

}
}
