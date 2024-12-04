#pragma once
#include "Jogo.h"

class Ente;

//namespace dos gerenciadores
namespace ger{
class Gerenciador_Grafico{
private:
    sf::RenderWindow* janela;
    sf::Texture* Fundo;
protected:
//...
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    //desenhar
    void desenharEnte(Ente* pE);
};
}