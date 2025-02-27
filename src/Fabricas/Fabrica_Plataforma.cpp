#include "Fabricas/Fabrica_Plataforma.h"
#include "Entidades/Obstáculos/Plataforma.h"


namespace fact {

Fabrica_Plataforma::Fabrica_Plataforma()
    : Fabrica_Plataforma(0, 0, 0.f)
{
}

Fabrica_Plataforma::Fabrica_Plataforma(int nFase, int tipo, float tamanho)
    : Fabrica_Entidades()
    , tipoPlataforma(tipo)
    , tamanhoFase(tamanho)
    , numeroFase(nFase)
{
}

Fabrica_Plataforma::~Fabrica_Plataforma()
{
}

ent::Entidade* Fabrica_Plataforma::criarEntidade(sf::Vector2f posicao) {
    ent::obs::Plataforma* plataforma = new ent::obs::Plataforma(posicao, sf::Vector2f(1.7f, 1.7f), false, 50);
    plataforma->setTamanhoFase(tamanhoFase);

    // Configurar textura conforme o tipo
    if(numeroFase == 0){
        plataforma->setTextura("Grass" + std::to_string(tipoPlataforma));
        switch (tipoPlataforma){
            case 1 :
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::topoGrama);
                break;
            case 4:
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::meioGrama);
                break;
            case 500:
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::cantoGrama);
                break;
            default:
                break;
        }
    }
    else if(numeroFase ==1){
        plataforma->setTextura("Brick" + std::to_string(tipoPlataforma));
        switch (tipoPlataforma){
            case 1 :
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::topoTijolo);
                break;
            case 4:
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::meioTijolo);
                break;
            case 500:
                plataforma->setTipoPlataforma(ent::obs::tipoPlataforma::cantoTijolo);
                break;
            default:
                break;
        }
    }


    return static_cast<ent::Entidade*>(plataforma);
}

}