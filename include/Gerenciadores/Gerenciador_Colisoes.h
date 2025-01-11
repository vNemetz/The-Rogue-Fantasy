#pragma once
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Obstaculo.h"
#include <vector>
#include <list>

namespace ger {

class Gerenciador_Colisoes {
private:
    std::vector<ent::pers::Inimigo*> listaInimigos;
    std::list<ent::obs::Obstaculo*> listaObstaculos;
    //std::set<ent::Projetil*> LPs;

    ent::pers::Jogador* jogador;

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
    
    void setJogador(ent::pers::Jogador* jog);

    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();

    /*
    void tratarColisoesJogsProjeteis();
    void incluirProjetil(ent::Projetil* pj);
    */
};

}
