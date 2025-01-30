#include "Fabricas/Fabrica_Jogador.h"
#include "Entidades/Personagens/Jogador.h"

namespace fact {

Fabrica_Jogador::Fabrica_Jogador()
    : Fabrica_Jogador(false, 0.f)
{
}

Fabrica_Jogador::Fabrica_Jogador(bool jog1, float tamanho)
    : Fabrica_Entidades()
    , jogador1(jog1)
    , tamanhoFase(tamanho)
{
}

Fabrica_Jogador::~Fabrica_Jogador()
{
}

ent::Entidade* Fabrica_Jogador::criarEntidade(sf::Vector2f posicao) {
    ent::pers::Jogador* jogador = new ent::pers::Jogador(posicao, sf::Vector2f(1.7f, 1.7f), jogador1);
    
    jogador->setTamanhoFase(tamanhoFase);
    
    return static_cast<ent::Entidade*>(jogador);
}

}