#pragma once
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Menu.h"
#include "Estados/Fases/Fase.h"
namespace menus{
class Menu_Principal : public Menu{
private:
    fases::Fase* pFase;
public:
    Menu_Principal();
    Menu_Principal(ger::Gerenciador_Estados* pGE);
    ~Menu_Principal();

    void setFase(fases::Fase* pF);
    void executarEstado(tipoEstado tipo);
};
}