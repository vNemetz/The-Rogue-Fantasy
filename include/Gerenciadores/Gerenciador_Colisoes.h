#pragma once
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Obstáculos/Obstaculo.h"
#include "Entidades/Projeteis/Projetil.h"
#include "Listas/Lista_Entidades.h"
#include <list>

namespace ger {

class Gerenciador_Colisoes {
private:
    std::list<ent::obs::Obstaculo*> listaObstaculos;
    lis::Lista_Entidades* listaInimigos;
    lis::Lista_Entidades* listaJogadores;
    lis::Lista_Entidades* listaProjeteis;

    /* Singleton - Padrão de Projeto */
    static ger::Gerenciador_Colisoes* instancia;

private:
    Gerenciador_Colisoes();
    
public:
    static Gerenciador_Colisoes* getInstancia();
    
    ~Gerenciador_Colisoes();
    
    void executar();
    const bool verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const;
    sf::Vector2f calcularColisao(ent::Entidade* pe1, ent::Entidade* pe2) const;

    void incluirObstaculo(ent::obs::Obstaculo* po);
    void setListaProjeteis(lis::Lista_Entidades* listaProjeteis);
    void setListaInimigos(lis::Lista_Entidades* listaInimigos);
    void setListaJogadores(lis::Lista_Entidades* listaJogadores);
};

}
