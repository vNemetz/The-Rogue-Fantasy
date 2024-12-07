#pragma once
#include "Jogo.h"

namespace ger {
class Gerenciador_Eventos {
private:
    // TODO: Gerenciador_Colisoes* gerColisoes;
    Gerenciador_Grafico* gerGrafico;

public:
    Gerenciador_Eventos(Gerenciador_Grafico* gG);
    ~Gerenciador_Eventos();

    void gerenciar();
};
}