#pragma once
#include "Menu.h"
#include "ElementosGraficos/Texto.h"
#include "Estados/Fases/Fase.h"

namespace menus{
class Menu_Fim : public Menu{
private:

    ElementosGraficos::Texto titulo;
    ElementosGraficos::Texto pontos;
    ElementosGraficos::Texto nome;
    ElementosGraficos::Texto nomeJogador;

    unsigned int pontosParaIncrementar;
    fases::Fase* pFase;

public:

    Menu_Fim();
    Menu_Fim(ger::Gerenciador_Estados* pGE = nullptr, fases::Fase* fase = nullptr);
    ~Menu_Fim();

    void escreverNoArquivo();
    void executar() override;
};

}