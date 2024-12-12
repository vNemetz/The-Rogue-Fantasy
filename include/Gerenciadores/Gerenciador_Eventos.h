#pragma once
#include "Gerenciadores/Gerenciador_Input.h"
#include "Jogador.h"

namespace ger {
class Gerenciador_Eventos {
private:
    // TODO: Gerenciador_Colisoes* gerColisoes;
    pers::Jogador* jogador;
    Gerenciador_Input* gerInput;

    // Implementação do Singleton ao Gerenciador de Eventos:
    static ger::Gerenciador_Eventos* instancia;

private:
    Gerenciador_Eventos();

public:
    static Gerenciador_Eventos* getInstancia();
    
    ~Gerenciador_Eventos();
    
    void setJogador(pers::Jogador* jog);

    void gerenciar();
};
}
