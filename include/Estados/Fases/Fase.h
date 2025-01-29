#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Jogador.h"
#include "Ente.h"

namespace fases{

class Fase : public Ente, public Estado{
protected:
    ger::Gerenciador_Colisoes* pColisoes;
    lis::Lista_Entidades listaPersonagens;
    lis::Lista_Entidades listaObstaculos;
    lis::Lista_Entidades listaProjeteis;
    sf::Texture* pFundo; //Textura do plano de fundo (background)
    
    static bool doisJogadores;
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;

    sf::Sprite spriteFundo;
    int numeroFase;
    float tamanhoFase;

public:
    Fase();
    Fase(ger::Gerenciador_Colisoes* pGC, int nFase);
    ~Fase();

    /*Criação de entidades: */
    void criarPersonagens(sf::Vector2f posicao, ID id, char tipo = '-');
    void criarGoblin(sf::Vector2f posicao);
    void criarAranha(sf::Vector2f posicao);

    void desenharFundo();

    virtual void criarFundo() = 0;
    virtual void criarMapa() = 0;
    void criarPlataformas(sf::Vector2f pos, int tipo);
    void criarObstaculos();
    void criarEntidade(char simbolo, const sf::Vector2i pos);
    
    ent::pers::Jogador* getJogador1();
    ent::pers::Jogador* getJogador2();

    void atualizaPersonagens();
    void atualizaObstaculos();
    void atualizarProjeteis();
    
    float getTamanhoFase();
    
    void executar();
    //virtual void alterarEstado();
};
}