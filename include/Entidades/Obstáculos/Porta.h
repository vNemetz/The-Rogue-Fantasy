#pragma once
#include "Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"

namespace ent{
namespace obs{

class Porta : public Obstaculo{

private:
    ElementosGraficos::Animacao animacao;
public:

    Porta();
    ~Porta();

    void atualizarAnimacao();
    void setCorpo();

    void executar();
    void emColisao(Entidade* pE, sf::Vector2f ds);

};
}
}