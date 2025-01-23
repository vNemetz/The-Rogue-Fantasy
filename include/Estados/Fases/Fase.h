#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Obstáculos/Plataforma.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Goblin.h"
#include "Ente.h"
#include "Entidades/Entidade.h"

namespace fases{

class Fase : public Ente, public Estado{
protected:
    ger::Gerenciador_Colisoes* pColisoes;
    lis::Lista_Entidades listaPersonagens;
    lis::Lista_Entidades listaObstaculos;
    sf::Texture* pFundo; //Textura do plano de fundo (background)
    ent::pers::Jogador* pJog;
    sf::Sprite spriteFundo;
    int numeroFase;
public:
    Fase();
    Fase(ger::Gerenciador_Colisoes* pGC, int nFase = 1);
    ~Fase();
    
    void gerenciarColisoes();

    /*Criação de entidades: */
    void criarPersonagens(sf::Vector2f posicao, ID id);
    void criarPlataformas(sf::Vector2f pos, int tipo);
    void criarObstaculos();
    virtual void criarFundo() = 0;
    void desenharFundo();
    virtual void criarMapa() = 0;
    void criarEntidade(char simbolo, const sf::Vector2i pos);
    ent::pers::Jogador* getJogador();
    void atualizaPersonagens();
    void atualizaObstaculos();
    
    void executar();
    //virtual void alterarEstado();
};
}