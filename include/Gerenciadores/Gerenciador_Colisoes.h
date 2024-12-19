#pragma once
#include "Entidades/Inimigo.h"
#include "Entidades/Jogador.h"
#include "Entidades/Obstaculo.h"
#include <vector>
#include <list>

namespace ger {

class Gerenciador_Colisoes {
private:
    std::vector<ent::pers::Inimigo*> LIs;
    std::list<ent::obs::Obstaculo*> LOs;
    //std::set<ent::Projetil*> LPs;

    ent::pers::Jogador* jogador;
    // ...

    /* Singleton - Padrão de Projeto */
    static ger::Gerenciador_Colisoes* instancia;

private:
    Gerenciador_Colisoes();
    
public:
    static Gerenciador_Colisoes* getInstancia();
    
    ~Gerenciador_Colisoes();
    
    void executar();
    sf::Vector2f calcularColisao(ent::Entidade* pe1, ent::Entidade* pe2) const;
    const bool verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const;

    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    
    void incluirInimigo(ent::pers::Inimigo* pi);
    void incluirObstaculo(ent::obs::Obstaculo* po);

    void setJogador(ent::pers::Jogador* jog);

    /*
    void tratarColisoesJogsProjeteis();
    void incluirProjetil(ent::Projetil* pj);
    ...()
    */
};

}
