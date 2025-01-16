#include "Listas/Lista_Entidades.h"
#include "Entidades/Entidade.h"

namespace lis {
Lista_Entidades::Lista_Entidades()
: LEs()
{
}

Lista_Entidades::~Lista_Entidades() {
    LEs.limpar();
}

void Lista_Entidades::incluir(ent::Entidade* pE) {
    LEs.incluir(pE);
}

void Lista_Entidades::remover(ent::Entidade* pE) {
    LEs.remover(pE);
}

void Lista_Entidades::limpar() {
    LEs.limpar();
}

void Lista_Entidades::percorrer() {
    Lista<ent::Entidade>::Iterator it = begin();

    while (it != end()) {
        ent::Entidade* aux = *it;
        
        aux->executar();
        aux->desenhar();
        aux->setNoChao(false); // Setta noChao como false (se estiver colidindo com chão, fica true depois)
        ++it;
    }
}

int Lista_Entidades::getTamanho() const {
    return LEs.getTamanho();
}

Lista<ent::Entidade>::Iterator Lista_Entidades::begin() const {
    return LEs.begin();
}

Lista<ent::Entidade>::Iterator Lista_Entidades::end() const {
    return LEs.end();
}

}
