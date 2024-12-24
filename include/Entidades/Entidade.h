#pragma once
#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace ent {

class Entidade : public Ente {
protected:
    sf::Vector2f velocidade;
    float dt;
    bool noChao;
    //ostream buffer;
    //int x
    //int y
    //...
    
public:
    Entidade();
    Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    virtual ~Entidade();

    virtual void executar() = 0;
    //virtual void salvar() = 0;
    void salvarDataBuffer();

    sf::Vector2f getVelocidade() const;
    void setVelocidade(sf::Vector2f vel);

    
    void setNoChao(bool estado);
    //...

};
}
