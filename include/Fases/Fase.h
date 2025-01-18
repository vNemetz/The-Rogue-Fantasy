#pragma once
#include <SFML/Graphics.hpp>
#include <Gerenciadores/Gerenciador_Colisoes.h>
#include "Listas/Lista_Entidades.h"
#include "Ente.h"


namespace fases{

class Fase : public Ente{
protected:
    ger::Gerenciador_Colisoes* pColisoes;
    lis::Lista_Entidades listaEntidades;
    sf::Texture* pFundo; //Textura do plano de fundo (background)
    int numeroFase;
public:
    Fase();
    Fase(ger::Gerenciador_Colisoes* pGC, int nFase = 1);
    ~Fase();
    
    void gerenciarColisoes();

    /*Criação de entidades: */
    void criarPersonagem(sf::Vector2f posicao);
    void criarInimigos();
    void criarPlataformas();
    void criarObstaculos();
    virtual void criarFundo() = 0;
    virtual void criarMapa() = 0;
    void criarEntidade(char l, const sf::Vector2i pos);
    void executar();
    void desenhar();
    

};
}