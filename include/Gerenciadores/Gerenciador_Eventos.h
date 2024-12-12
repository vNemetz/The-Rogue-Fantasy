#pragma once
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"

namespace ger {
class Gerenciador_Eventos {
private:
    // TODO: Gerenciador_Colisoes* gerColisoes;
    ent::pers::Jogador* jogador;
    Gerenciador_Input* gerInput;

    // Implementação do Singleton ao Gerenciador de Eventos:
    static ger::Gerenciador_Eventos* instancia;

private:
    Gerenciador_Eventos();

public:
    static Gerenciador_Eventos* getInstancia();
    
    ~Gerenciador_Eventos();
    
    void setJogador(ent::pers::Jogador* jog);

    void gerenciar();
};
}
