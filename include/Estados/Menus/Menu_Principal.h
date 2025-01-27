#pragma once
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Menu.h"
namespace menus{
class Menu_Principal : public Menu{
private:

public:
    Menu_Principal();
    Menu_Principal(ger::Gerenciador_Estados* pGE);
    ~Menu_Principal();
};
}