#pragma once

#include "Gerenciadores/Gerenciador_Grafico.h"

#define HEIGHT 1080
#define WIDTH 1920


enum ID {
    vazio = 0,
    jogador,
    plataforma,
    inimigo,
    projetil,
    obstaculo,
    porta
};

class Ente {
protected:
    ID id;

    static ger::Gerenciador_Grafico* pGG;

public:
    Ente();
    Ente(ID id);
    virtual ~Ente();
    
    virtual void executar() = 0;

    ID getID() const;
    void setID(ID id);
    
    static void setPGG(ger::Gerenciador_Grafico* pGG);
};
