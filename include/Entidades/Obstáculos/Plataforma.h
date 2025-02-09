#pragma once

#include "Entidades/Obstáculos/Obstaculo.h"

namespace ent {
namespace obs {

enum tipoPlataforma{
    topoGrama = 0,
    meioGrama,
    topoTijolo,
    meioTijolo
};

class Plataforma : public Obstaculo {
private:
    tipoPlataforma tipo;
    int altura;

public:
    Plataforma();
    Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt);
    ~Plataforma();

    void executar();

    tipoPlataforma getTipoPlataforma() const;
    void setTipoPlataforma(tipoPlataforma tip);
};

}
}
