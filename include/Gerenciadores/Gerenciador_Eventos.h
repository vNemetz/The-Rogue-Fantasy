#pragma once
#include "Gerenciadores/Gerenciador_Input.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Entidades/Personagens/Jogador.h"

namespace ger {
class Gerenciador_Eventos {
private:
    Gerenciador_Colisoes* gerColisoes;
    Gerenciador_Input* gerInput;
    
    ent::pers::Jogador* jogador;

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
