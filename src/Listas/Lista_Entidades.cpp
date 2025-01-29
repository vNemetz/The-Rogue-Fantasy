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

        if (!aux) { // Verifica se o ponteiro é válido (evita crash se houver nullptr na lista)
            ++it;
            continue;
        }

        if (aux->getParaDeletar()) {
            // Captura o próximo elemento ANTES de remover o atual
            Lista<ent::Entidade>::Iterator next = it;
            ++next;

            remover(aux); // Remove o elemento atual

            it = next; // Atualiza o iterator para o próximo elemento válido
        }
        
        else {
            aux->executar();
            aux->desenhar();
            aux->setNoChao(false);
            //aux->desenharHitbox();
            ++it; // Avança normalmente se não houve remoção
        }
    }
}

ent::Entidade* Lista_Entidades::operator[](unsigned int index) const {
    return LEs.operator[](index);
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
