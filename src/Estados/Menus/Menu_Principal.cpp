#include "Estados/Menus/Menu_Principal.h"


menus::Menu_Principal::Menu_Principal():
Menu()
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button");
}

menus::Menu_Principal::Menu_Principal(ger::Gerenciador_Estados *pGE):
Menu(pGE)
{
    setTexturaFundo("Main-Menu-Bg");
    adicionarBotao("Yellow-Button");
}
menus::Menu_Principal::~Menu_Principal()
{
    pGEstados = nullptr;
}
