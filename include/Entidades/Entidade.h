#pragma once
#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace ent {

class Entidade : public Ente {
protected:
    sf::Vector2f velocidade;
    //ostream buffer;
    //int x
    //int y
    //...
    
public:
    //Construtora e Destrutora
    Entidade();
    Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    virtual ~Entidade();

    void setVelocidade(sf::Vector2f vel);

    virtual void executar() = 0;
    //virtual void salvar() = 0;
    void salvarDataBuffer();
    //...

};
}
