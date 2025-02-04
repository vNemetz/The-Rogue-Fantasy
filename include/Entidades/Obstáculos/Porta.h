#pragma once

#include "Entidades/Obstáculos/Obstaculo.h"
#include "ElementosGraficos/Animacao.h"

namespace ent {
namespace obs {

enum estado {
    aberto,
    abrindo,
    fechado
};

class Porta : public Obstaculo {
private:
    static bool aberta;
    estado est;

    ElementosGraficos::Animacao animacao;

    float tempoAbrindo;
    const float duracaoAbrindo = 1.f;

public:
    Porta();
    Porta(sf::Vector2f pos, sf::Vector2f tam);
    ~Porta();

    void executar();
    void emColisao(Entidade* pE, sf::Vector2f ds);

    void atualizarEstado();

    static void setAberta(bool aberta);
    bool getAberta() const;

    estado getEstado() const;

    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};

}
}