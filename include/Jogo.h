#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <time.h>

#include "Coordenadas.h"

#include <map>
#include <vector>
#include <string>

namespace ger{class Gerenciador_Grafico; class Gerenciador_Eventos;}
class Ente;
namespace pers{class Jogador;}

class Jogo{
private:
    ger::Gerenciador_Grafico *gerGrafico;
    ger::Gerenciador_Eventos *gerEventos;
    //Ente *e;
    pers::Jogador *jogador;

public:
    Jogo();
    ~Jogo();
    void executar();

    void moveEntes();
};