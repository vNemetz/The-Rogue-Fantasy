#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <time.h>

#include "Coordenadas.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>


class Ente;
namespace pers{class Jogador;}

class Jogo{
private:
    pers::Jogador *jogador;

public:
    Jogo();
    ~Jogo();
    void executar();

    void moveEntes();
};