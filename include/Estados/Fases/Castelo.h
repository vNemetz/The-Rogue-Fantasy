#pragma once
#include "Fase.h"

namespace fases{

class Castelo : public Fase{
private:
    std::vector<sf::Vector2i> aranhas;
    std::vector<sf::Vector2i> cavaleiros;
    std::vector<sf::Vector2i> plataformasVoadoras;
    std::vector<sf::Vector2i> espinhos;

public:
    Castelo();
    ~Castelo();

    virtual void criarFundo();
    virtual void criarMapa();

    void checaObjetivo();
    void criarEntidades();
};
}