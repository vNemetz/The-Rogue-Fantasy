#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>

#include "Listas/Lista_Entidades.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Fases/Floresta.h"

namespace ent { namespace pers { class Jogador; } }

class Jogo {
private:
    ger::Gerenciador_Grafico* gerGrafico;
    ger::Gerenciador_Eventos* gerEventos;
    ger::Gerenciador_Colisoes* gerColisoes;
    
    lis::Lista_Entidades listaEntidades;
    ent::pers::Jogador* jogador;

    fases::Floresta faseFloresta;

public:
    Jogo();
    ~Jogo();

    void executar();

    void inicializaEntidades();
    void atualizaEntidades();
};
