#include "Controle/Controle_Jogador.h"
#include "Entidades/Personagens/Jogador.h"
#include "Estados/Fases/Fase.h"
#include <functional>
namespace controle{

Controle_Jogador::Controle_Jogador():
Controle_Jogador(controleJogador, nullptr, nullptr, nullptr, nullptr)
{
}

Controle_Jogador::Controle_Jogador(formaControle tipoControle, ger::Gerenciador_Input *pGI, ent::pers::Jogador *j1, ent::pers::Jogador *j2, fases::Fase *pAtual)
: Observador(tipoControle, pGI)
{
    setFaseAtual(pAtual);
    setJogador1(j1);
    setJogador2(j2);
    criarMapa();
}

Controle_Jogador::~Controle_Jogador()
{
    mapaTeclas.clear();
}

void Controle_Jogador::setJogador1(ent::pers::Jogador *jogador1)
{
    if(jogador1)
        this->jogador1 = jogador1;
}

void Controle_Jogador::setJogador2(ent::pers::Jogador *jogador2)
{
    if(jogador2)
        this->jogador2 = jogador2;
}

void Controle_Jogador::setFaseAtual(fases::Fase *pFaseAtual)
{
    if(pFaseAtual)
        this->pFaseAtual = pFaseAtual;
}

void Controle_Jogador::notificarApertada(sf::Keyboard::Key tecla)
{
    if(ativo){
        auto it = mapaTeclas.find(tecla);
        
        // Procura a tecla no mapa, se achar executa a função como verdadeira
        if (it != mapaTeclas.end())
            it->second(true);
    }
}

void Controle_Jogador::notificarSoltada(sf::Keyboard::Key tecla)
{
    if(ativo){
        auto it = mapaTeclas.find(tecla);
        
        // Procura a tecla no mapa, se achar executa a função como falsa
        if (it != mapaTeclas.end())
            it->second(false);
    }
}

void Controle_Jogador::criarMapa()
{
   /* Inicializa os comandos do jogo */
    /* Jogador 1 - Comandos*/
    incluir_tecla(sf::Keyboard::Key::A, [this](bool pressionado) {
        if(jogador1)
            jogador1->atualizarMovimentacao(pressionado, "A");
    });

    incluir_tecla(sf::Keyboard::Key::D, [this](bool pressionado) {
        if(jogador1)
            jogador1->atualizarMovimentacao(pressionado, "D");
    });

    incluir_tecla(sf::Keyboard::Key::W, [this](bool pressionado) {
        if(jogador1)                
            jogador1->atualizarMovimentacao(pressionado, "W");
    });

    incluir_tecla(sf::Keyboard::Key::LShift, [this](bool pressionado) {
        if(jogador1)
            jogador1->atualizarMovimentacao(pressionado, "LShift");
    });

    incluir_tecla(sf::Keyboard::Key::Space, [this](bool pressionado) {
        if(jogador1)
            jogador1->atualizarMovimentacao(pressionado, "Space");
    });

    /* Jogador 2 - Comandos */
    incluir_tecla(sf::Keyboard::Key::Left, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Left");
    });

    incluir_tecla(sf::Keyboard::Key::Right, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Right");
    });

    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Up");
    });

    incluir_tecla(sf::Keyboard::Key::K, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "K");
    });

    incluir_tecla(sf::Keyboard::Key::L, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "L");
    });

    /*Esc para abrir o menu de pausa*/
    
    incluir_tecla(sf::Keyboard::Key::Escape, [this](bool pressionado) {
        if(pFaseAtual){
            pFaseAtual->setBufferTime(0);
            pFaseAtual->executarEstado(pausa);
        }
    });
}


}