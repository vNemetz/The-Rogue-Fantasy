#pragma once
#include "Observador.h"
#include <map>


namespace ent{
    namespace pers{
        class Jogador;
    }
}
namespace fases{
    class Fase;
}

namespace controle{

class Controle_Jogador : public Observador{
private:
    ent::pers::Jogador* jogador1;
    ent::pers::Jogador* jogador2;
    fases::Fase* pFaseAtual;


public:
    Controle_Jogador();
    Controle_Jogador(formaControle  tipoControle, ger::Gerenciador_Input* pGI = nullptr, 
        ent::pers::Jogador* j1 = nullptr, ent::pers::Jogador* j2 = nullptr, fases::Fase* pAtual = nullptr);
    ~Controle_Jogador();

    void setJogador1(ent::pers::Jogador* jogador1);
    void setJogador2(ent::pers::Jogador* jogador2);
    void setFaseAtual (fases::Fase* pFaseAtual);

    void notificarApertada(sf::Keyboard::Key tecla);
    void notificarSoltada(sf::Keyboard::Key tecla);

    void criarMapa();
    

};

}