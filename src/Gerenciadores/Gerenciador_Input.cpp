#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include <SFML/Window/Keyboard.hpp>

namespace ger {
/* Singleton - Padrão de Projeto */
Gerenciador_Input::Gerenciador_Input()
: mapaTeclas()
, jogador(nullptr)
{
    /* Inicializa os comandos do jogo */
    
    incluir_tecla(sf::Keyboard::Key::A, [this](bool pressionado) {
        jogador->atualizarEstado(pressionado, sf::Keyboard::A);
        jogador->setEstado(ent::pers::andando);
    });

    incluir_tecla(sf::Keyboard::Key::D, [this](bool pressionado) {
        jogador->atualizarEstado(pressionado, sf::Keyboard::D);
        jogador->setEstado(ent::pers::andando);
    });

    incluir_tecla(sf::Keyboard::Key::W, [this](bool pressionado) {
        jogador->atualizarEstado(pressionado, sf::Keyboard::W);
        jogador->setEstado(ent::pers::pulado);
    });

    incluir_tecla(sf::Keyboard::Key::S, [this](bool pressionado) {
        jogador->atualizarEstado(pressionado, sf::Keyboard::S);
        jogador->setEstado(ent::pers::parado);
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
