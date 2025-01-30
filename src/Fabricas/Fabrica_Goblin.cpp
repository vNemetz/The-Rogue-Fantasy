#include "Fabricas/Fabrica_Goblin.h"
#include "Entidades/Personagens/Goblin.h"

namespace fact {

Fabrica_Goblin::Fabrica_Goblin()
    : Fabrica_Goblin(nullptr, nullptr, false, 0.f)
{
}

Fabrica_Goblin::Fabrica_Goblin(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho)
    : Fabrica_Entidades()
    , doisJogadores(doisJog)
    , tamanhoFase(tamanho)
    , pJog1(jog1)
    , pJog2(jog2)
{
}

Fabrica_Goblin::~Fabrica_Goblin()
{
}

ent::Entidade* Fabrica_Goblin::criarEntidade(sf::Vector2f posicao) {
    ent::pers::Goblin* goblin = new ent::pers::Goblin(posicao, sf::Vector2f(1.7f, 1.7f));
    
    goblin->setTamanhoFase(tamanhoFase);
    goblin->incluirJogador(pJog1);

    if (doisJogadores)
        goblin->incluirJogador(pJog2);
    
    return static_cast<ent::Entidade*>(goblin);
}

}