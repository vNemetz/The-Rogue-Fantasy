#include "Fabricas/Fabrica_Aranha.h"
#include "Entidades/Personagens/Aranha.h"

namespace fact {

Fabrica_Aranha::Fabrica_Aranha()
    : Fabrica_Aranha(nullptr, nullptr, false, 0.f, nullptr)
{
}

Fabrica_Aranha::Fabrica_Aranha(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho, lis::Lista_Entidades* listaProj)
    : Fabrica_Entidades()
    , doisJogadores(doisJog)
    , tamanhoFase(tamanho)
    , listaProjeteis(listaProj)
    , pJog1(jog1)
    , pJog2(jog2)
{
}

Fabrica_Aranha::~Fabrica_Aranha()
{
}

ent::Entidade* Fabrica_Aranha::criarEntidade(sf::Vector2f posicao) {
    ent::pers::Aranha* aranha = new ent::pers::Aranha(posicao, sf::Vector2f(1.7f, 1.7f));
    
    aranha->setTamanhoFase(tamanhoFase);
    aranha->incluirJogador(pJog1);
    aranha->setListaProjeteis(listaProjeteis);

    if (doisJogadores)
        aranha->incluirJogador(pJog2);
    
    return static_cast<ent::Entidade*>(aranha);
}

}