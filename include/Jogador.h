#pragma once
#include "Personagem.h"


namespace pers{
class Jogador : public pers::Personagem{
private:
    int pontos;
    bool vivo;
protected:
//...
public:
    Jogador();
    Jogador(ger::Gerenciador_Grafico* pGrafico = NULL);
    ~Jogador();
    void executar();

    void alteraVivo(); //altera o valor de "vivo"
    bool getVivo();
    void mover(sf::Keyboard::Key key);
};
}