#pragma once
#include "Fabricas/Fabrica_Entidades.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Jogador.h"
#include "Estados/Estado.h"
#include <unordered_map>

namespace fases{

class Fase : public Ente, public Estado{
protected:
    int numeroFase;
    float tamanhoFase;

    static bool doisJogadores;
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;

    std::unordered_map<char, fact::Fabrica_Entidades*> fabricas;
    lis::Lista_Entidades listaPersonagens;
    lis::Lista_Entidades listaObstaculos;
    lis::Lista_Entidades listaProjeteis;
    
    ger::Gerenciador_Colisoes* pColisoes;
    sf::Texture* pFundo; //Textura do plano de fundo (background)
    sf::Sprite spriteFundo;

public:
    Fase();
    Fase(int nFase);
    ~Fase();

    /* Criação da Fase */
    virtual void criarFundo() = 0;
    virtual void criarMapa() = 0;

    /* Criação de entidades */
    void registrarFabrica(char simbolo, fact::Fabrica_Entidades* fabrica);
    void criarEntidade(char simbolo, const sf::Vector2i pos);

    /* Execução da Fase */
    void executar();
    void desenharFundo();
    void atualizarPersonagens();
    void atualizarObstaculos();
    void atualizarProjeteis();
    
    /* Métodos Auxiliares */
    ent::pers::Jogador* getJogador1() const;
    ent::pers::Jogador* getJogador2() const;
    float getTamanhoFase() const;
    float getNumeroFase() const;
    
    //virtual void alterarEstado();
};
}