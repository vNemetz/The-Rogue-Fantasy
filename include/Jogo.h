#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <time.h>

#include <iostream>
#include <vector>

using namespace std;
namespace ger{class Gerenciador_Grafico;}
class Ente;

class Jogo{
private:
    ger::Gerenciador_Grafico *gG;
    Ente *e;
public:
    Jogo();
    ~Jogo();
    void executar();
};