#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>

#include "Estados/Menus/Menu_Principal.h"
#include "Listas/Lista_Entidades.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Estados/Fases/Floresta.h"

namespace ent { namespace pers { class Jogador; } }

class Jogo {
private:
/*Gerenciadores*/
    ger::Gerenciador_Grafico* gerGrafico;
    ger::Gerenciador_Eventos* gerEventos;
    ger::Gerenciador_Estados* gerEstados;

    /*Estados*/
    fases::Floresta* faseFloresta;
    menus::Menu_Principal* menuPrincipal;

public:
    Jogo();
    ~Jogo();

    void executar();
    void criarFase();
    void criarMenuPrincipal();
};
