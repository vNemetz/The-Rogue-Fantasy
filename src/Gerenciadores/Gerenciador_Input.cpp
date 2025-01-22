#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/Window/Keyboard.hpp>

namespace ger {
/* Singleton - Padrão de Projeto */
Gerenciador_Input::Gerenciador_Input()
: mapaTeclas()
, jogador(nullptr)
{
    /* Inicializa os comandos do jogo */
    /* Jogador 1 - Comandos*/
    incluir_tecla(sf::Keyboard::Key::A, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::A);
    });

    incluir_tecla(sf::Keyboard::Key::D, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::D);
    });

    incluir_tecla(sf::Keyboard::Key::W, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::W);
    });

    incluir_tecla(sf::Keyboard::Key::S, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::S);
    });

    incluir_tecla(sf::Keyboard::Key::LShift, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::LShift);
    });

    incluir_tecla(sf::Keyboard::Key::Space, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::Space);
    });

    /* Jogador 2 - Comandos */
    incluir_tecla(sf::Keyboard::Key::Left, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::Left);
    });

    incluir_tecla(sf::Keyboard::Key::Right, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::Right);
    });

    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::Up);
    });

    incluir_tecla(sf::Keyboard::Key::K, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::K);
    });

    incluir_tecla(sf::Keyboard::Key::L, [this](bool pressionado) {
        jogador->atualizarMovimentacao(pressionado, sf::Keyboard::L);
    });
}

Gerenciador_Input::~Gerenciador_Input() {
    mapaTeclas.clear();
}

Gerenciador_Input* Gerenciador_Input::instancia(nullptr);

Gerenciador_Input* Gerenciador_Input::getInstancia() {
   if(instancia == nullptr)
        instancia = new Gerenciador_Input();
    
    return instancia;
}

/* Gerenciador de Input */
void Gerenciador_Input::setJogador(ent::pers::Jogador* jog) {
    jogador = jog;
}

void Gerenciador_Input::incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla) {
    mapaTeclas[tecla] = funcaoTecla;
}

void Gerenciador_Input::teclaApertada(sf::Keyboard::Key tecla) {
    auto it = mapaTeclas.find(tecla);
    
    // Procura a tecla no mapa, se achar executa a função como verdadeira
    if (it != mapaTeclas.end())
        it->second(true);
}

void Gerenciador_Input::teclaSoltada(sf::Keyboard::Key tecla) {
    auto it = mapaTeclas.find(tecla);

    // Procura a tecla no mapa, se achar executa a função como falsa
    if (it != mapaTeclas.end())
        it->second(false);
}
}
