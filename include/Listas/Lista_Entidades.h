#pragma once
#include "Lista.h"

namespace ent {class Entidade;}

namespace lis {
class Lista_Entidades {
private:
    Lista<ent::Entidade> LEs;

public:
    Lista_Entidades();
    ~Lista_Entidades();

    void incluir(ent::Entidade* pE); // Adiciona
    void remover(ent::Entidade* pE); // Remove
    void limpar(); // Limpa

    void percorrer(); // Chama atualizar() para cada elemento
    
    int getTamanho() const; // Retorna o tamanho
    
    // Iteradores para o começo e final da lista
    Lista<ent::Entidade>::Iterator begin() const;
    Lista<ent::Entidade>::Iterator end() const;
};
}