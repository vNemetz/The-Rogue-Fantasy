#pragma once
#include "Entidades/Obstáculos/Plataforma.h"
#include "Entidades/Obstáculos/Porta.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projeteis/Projetil.h"

namespace ger {

/* Padrão de Projeto / Design Pattern - Mediator */
class Mediador {
public:
    // Método para registro de entidades
    virtual void incluirEntidade(ent::Entidade* entidade) = 0;
};

class Gerenciador_Colisoes : public Mediador {
private:
    std::vector<ent::obs::Obstaculo*> listaObstaculos;
    std::vector<ent::pers::Inimigo*> listaInimigos;
    std::vector<ent::pers::Jogador*> listaJogadores;
    std::vector<ent::prj::Projetil*> listaProjeteis;

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
    void limparListas();

    /* Tratamento de colisões */
    void tratarJogadorInimigo(ent::pers::Jogador* jogador, ent::pers::Inimigo* inimigo);
    void tratarInimigoInimigo(ent::pers::Inimigo* inimigo1, ent::pers::Inimigo* inimigo2);
    void tratarPersonagemPlataforma(ent::pers::Personagem* personagem, ent::obs::Plataforma* plataforma);
    void tratarProjetilPersonagem(ent::prj::Projetil* projetil, ent::pers::Personagem* personagem);
    void tratarProjetilPlataforma(ent::prj::Projetil* projetil, ent::obs::Plataforma* plataforma);
    void tratarJogadorPorta(ent::pers::Jogador* jogador, ent::obs::Porta* porta);

    void incluirEntidade(ent::Entidade* entidade);

private:
    void incluirObstaculo(ent::obs::Obstaculo* obstaculo);
    void incluirJogador(ent::pers::Jogador* jogador);
    void incluirInimigo(ent::pers::Inimigo* inimigo);
    void incluirProjetil(ent::prj::Projetil* projetil);
};

}
