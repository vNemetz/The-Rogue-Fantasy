#pragma once
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Menu.h"
#include "Estados/Fases/Fase.h"
#include "Menu_Principal.h"

namespace menus{

class Menu_Pausa : public Menu{
private:
    fases::Fase* pFase;
    Menu_Principal* pMenuPrincipal;
public:
    Menu_Pausa();
    Menu_Pausa(ger::Gerenciador_Estados* pGE);
    ~Menu_Pausa();

    void executarEstado();
};
}