#pragma once
#include "Fabricas/Fabrica_Entidades.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Jogador.h"
#include "Estados/Estado.h"
#include <unordered_map>

/* Para o salvamento e carregamento de fase salva: */
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace ger{
    class Gerenciador_Estados;
}
namespace fases{

class Fase : public Ente, public Estado{
protected:
    int numeroFase;
    float tamanhoFase;

    bool carregada;

    ger::Gerenciador_Estados* pEstados;
    
    int pontos;
    static bool doisJogadores;
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;

    std::unordered_map<char, fact::Fabrica_Entidades*> fabricas;
    lis::Lista_Entidades listaPersonagens;
    lis::Lista_Entidades listaInimigos;
    lis::Lista_Entidades listaJogadores;
    lis::Lista_Entidades listaObstaculos;
    lis::Lista_Entidades listaProjeteis;
    
    ger::Gerenciador_Colisoes* pColisoes;
    sf::Texture* pFundo; //Textura do plano de fundo (background)
    sf::Sprite spriteFundo;

public:
    Fase();
    Fase(int nFase, bool carreg);
    ~Fase();

    /* Criação da Fase */
    virtual void criarFundo() = 0;
    virtual void criarMapa() = 0;
    static void setMultijogador(bool multi);

    /* Criação de entidades */
    void registrarFabrica(char simbolo, fact::Fabrica_Entidades* fabrica);

    ent::Entidade* criarEntidade(char simbolo, const sf::Vector2i pos);

    /* Execução da Fase */
    void executar();
    void desenharFundo();
    void atualizarPersonagens();
    void atualizarObstaculos();
    void atualizarProjeteis();

    bool checaFimJogo();
    virtual void checaObjetivo() = 0;
    
    /* Métodos Auxiliares */
    ent::pers::Jogador* getJogador1() const;
    ent::pers::Jogador* getJogador2() const;
    float getTamanhoFase() const;
    int getNumeroFase() const;
    int getPontuacao();
    void setPontuacao(int pontos);
    
    /* Para avisar o Gerenciador de Eventos qual estado executar: */
    void executarEstado(tipoEstado tipo);

    /* Salvamento e carregamento de fase: */

    void salvarJogo(std::string caminho);
    void carregarJogo(std::string caminho);


};
}