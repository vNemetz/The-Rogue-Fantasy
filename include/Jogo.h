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
#include "Estados/Fases/Floresta.h"

namespace ent { namespace pers { class Jogador; } }

class Jogo {
private:
    ger::Gerenciador_Grafico* gerGrafico;
    ger::Gerenciador_Eventos* gerEventos;

    fases::Floresta* faseFloresta;

public:
    Jogo();
    ~Jogo();

    void executar();
    void criarFase();
};
