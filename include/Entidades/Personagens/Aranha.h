#pragma once

#include "Entidades/Personagens/Inimigo.h"
#include "Listas/Lista_Entidades.h"

namespace ent {
namespace pers {

class Aranha : public Inimigo {
private:
    float raioAtaque;
    lis::Lista_Entidades* listaProjeteis;

public:
    Aranha();
    Aranha(sf::Vector2f pos, sf::Vector2f tam);
    ~Aranha();

    void executar();
    void atacar(Jogador* jogador);
    void parar();
    void setListaProjeteis(lis::Lista_Entidades* listaProjeteis);

    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};

}
}
