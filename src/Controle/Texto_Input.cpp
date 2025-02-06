#include "Controle/Texto_Input.h"
//#include "Jogo.h"

controle::Texto_Input::Texto_Input(){

}

controle::Texto_Input::~Texto_Input()
{
}

void controle::Texto_Input::notificarApertada(std::string tecla)
{
  /*  if(tecla == sf::Keyboard::BackSpace){
        if(texto.size() > 0)
            texto.pop_back();
    }
    else if(tecla == )
*/
}

void controle::Texto_Input::notificarSolta(std::string tecla)
{
}

std::string controle::Texto_Input::getTexto() const
{
    return std::string();
}

void controle::Texto_Input::limpar()
{
}
