#pragma once
#include "Jogo.h"

namespace ent{
namespace obs{
class Caixa : public Obstaculo{
private:
    float fatorDeLentidao;

public:
    Caixa();
    Caixa(sf::Vector2f pos, sf::Vector2f tam, ID id =obstaculo);
    ~Caixa();

    void setFatorDeLentidao(float lentidao);
    float getFatorDeLentidao() const;
    void executar();
};

}
}
