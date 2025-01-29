#pragma once
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Obstáculos/Obstaculo.h"
#include "Entidades/Projeteis/Projetil.h"
#include "Listas/Lista_Entidades.h"
#include <vector>
#include <list>

namespace ger {

class Gerenciador_Colisoes {
private:
    std::vector<ent::pers::Inimigo*> listaInimigos;
    std::list<ent::obs::Obstaculo*> listaObstaculos;
    std::vector<ent::pers::Jogador*> listaJogadores;
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

    void incluirInimigo(ent::pers::Inimigo* pi);
    void incluirObstaculo(ent::obs::Obstaculo* po);
    void incluirJogador(ent::pers::Jogador* jog);
    void incluirProjetil(ent::prj::Projetil* pj);
    void removerProjetil(ent::prj::Projetil* pj);
    void setListaProjeteis(lis::Lista_Entidades* listaProjeteis);

    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    void tratarColisoesJogsProjeteis();
};

}
