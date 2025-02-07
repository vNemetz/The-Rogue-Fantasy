#pragma once
#include "Menu.h"
#include "Controle/Texto_Input.h"
#include "Estados/Fases/Fase.h"
#include "ElementosGraficos/Texto.h"



namespace menus{
class Menu_Fim : public Menu{
private:

    ElementosGraficos::Texto titulo;   
    ElementosGraficos::Texto pontos;
    ElementosGraficos::Texto nome;
    ElementosGraficos::Texto nomeJogador;

    unsigned int pontosParaIncrementar;
    //fases::Fase* pFase;

    controle::Texto_Input* input;



public:

    Menu_Fim();
    Menu_Fim(ger::Gerenciador_Estados* pGE = nullptr);
    ~Menu_Fim();

    void escreverNoArquivo();

    void desenhar() override;
    void ativarBufferTexto(bool alt);
    void executarEstado();

    controle::Texto_Input* getInput();
};

}