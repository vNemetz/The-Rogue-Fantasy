#pragma once
#include "Jogo.h"
#include "Jogador.h"
namespace ger {
class Gerenciador_Eventos {
private:
    // TODO: Gerenciador_Colisoes* gerColisoes;
    pers::Jogador* jogador; 

    //Implementação do Singleton ao Gerenciador de Eventos:
    Gerenciador_Eventos();
    static ger::Gerenciador_Eventos* instancia;
public:
    static Gerenciador_Eventos* getInstancia();
    
    void setJogador(pers::Jogador* jog);
    
    ~Gerenciador_Eventos();

    void gerenciar();
};
}