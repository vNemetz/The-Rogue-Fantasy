#pragma once
#include "Fase.h"

namespace fases{

class Castelo : public Fase{
private:
    std::vector<sf::Vector2i> aranhas;
    std::vector<sf::Vector2i> cavaleiros;
public:
    Castelo();
    ~Castelo();

    virtual void criarFundo();
    virtual void criarMapa();

    void checaObjetivo();
    void criarInimigos();
};
}