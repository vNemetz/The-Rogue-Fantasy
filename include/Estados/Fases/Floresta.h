#pragma once
#include "Fase.h"

namespace fases{

class Floresta :public Fase{
private:
    bool faseFinalizada;
    std::vector<sf::Vector2i> goblins;
    std::vector<sf::Vector2i> aranhas;
    std::vector<sf::Vector2i> plataformasVoadoras;
    std::vector<sf::Vector2i> caixas;

public:
    Floresta();
    ~Floresta();

    virtual void criarFundo();
    virtual void criarMapa();
    void criarEntidades();

    virtual void checaObjetivo();
    void proximaFase();
};
}   