#pragma once
#include "Menu.h"
#include "Estados/Fases/Fase.h"

namespace ger{
    class Gerenciador_Estados;
}
namespace menus{
class Menu_Principal : public Menu{
private:
    int faseSelecionada;
public:
    Menu_Principal();
    Menu_Principal(ger::Gerenciador_Estados* pGE = nullptr);
    ~Menu_Principal();

    void executarEstado();
};
}