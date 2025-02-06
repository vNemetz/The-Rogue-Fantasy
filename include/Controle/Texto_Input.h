#pragma once
#include <iostream>

namespace controle{

class Texto_Input{
private:

    std::string texto;

public:
    Texto_Input();
    ~Texto_Input();

    void notificarApertada(std::string tecla);

    void notificarSolta(std::string tecla);

    std::string getTexto() const;

    void limpar();
};

}

