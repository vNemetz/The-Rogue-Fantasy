#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <time.h>

#include <map>
#include <iostream>
#include <vector>
#include <string>
#define CAMINHO_JOGO 

namespace ger{class Gerenciador_Grafico;}
class Ente;
namespace pers{class Jogador;}

class Jogo{
private:
    ger::Gerenciador_Grafico *gG;
    Ente *e;
    pers::Jogador *j;
public:
    Jogo();
    ~Jogo();
    void executar();

    void moveEntes();
};