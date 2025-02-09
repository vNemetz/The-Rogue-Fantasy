#include "Fabricas/Fabrica_Cavaleiro.h"
#include "Entidades/Personagens/Cavaleiro.h"

namespace fact {

Fabrica_Cavaleiro::Fabrica_Cavaleiro()
    : Fabrica_Cavaleiro(nullptr, nullptr, false, 0.f)
{
}

Fabrica_Cavaleiro::Fabrica_Cavaleiro(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho)
    : Fabrica_Entidades()
    , doisJogadores(doisJog)
    , tamanhoFase(tamanho)
    , pJog1(jog1)
    , pJog2(jog2)
{
}

Fabrica_Cavaleiro::~Fabrica_Cavaleiro()
{
}

ent::Entidade* Fabrica_Cavaleiro::criarEntidade(sf::Vector2f posicao) {
    ent::pers::Cavaleiro* cavaleiro = new ent::pers::Cavaleiro(posicao, sf::Vector2f(1.7f, 1.7f));
    
    cavaleiro->setTamanhoFase(tamanhoFase);
    cavaleiro->incluirJogador(pJog1);

    if (doisJogadores)
        cavaleiro->incluirJogador(pJog2);
    
    return static_cast<ent::Entidade*>(cavaleiro);
}

void Fabrica_Cavaleiro::setJogador1(ent::pers::Jogador *j1)
{
    if(j1){
        pJog1 = j1;
    }
}
void Fabrica_Cavaleiro::setJogador2(ent::pers::Jogador *j2)
{
    if(j2){
        pJog2 = j2;
    }
}
}