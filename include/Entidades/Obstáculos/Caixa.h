#pragma once

#include "Entidades/Obstáculos/Obstaculo.h"

namespace ent{
namespace obs{

class Caixa : public Obstaculo {
private:
    float fatorDeLentidao;
    bool movendo;

public:
    Caixa();
    Caixa(sf::Vector2f pos, sf::Vector2f tam);
    ~Caixa();

    void executar();

    void setFatorDeLentidao(float lentidao);
    float getFatorDeLentidao() const;
    bool getMovendo() const;
    void setMovendo(bool movendo);
};

}
}
