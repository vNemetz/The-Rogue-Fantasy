#pragma once
#include <iostream>
#include "Jogo.h"

/* Lista Encadeada de tipo genérico */

template <typename TL>
class Lista {
private:
    template<typename TE>
    class Elemento {
        private:
            Elemento<TE>* pProx;
            TE* pInfo;
        
        public:
            Elemento();
            ~Elemento();
            void incluir(TE* p);
            void setProx(Elemento<TE>* pE);
            Elemento<TE>* getProximo() const;
            TE* getInfo() const;
    };

    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista();
    ~Lista();

    void incluir(TL* p);
    void limpar();
    void imprimir();
    // ... (TODO)
};

/* 
 * Métodos de Lista<TL>::Elemento<TE>
 *
 */

template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::Elemento()
    : pProx(nullptr)
    , pInfo(nullptr)
{
}

template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::~Elemento() {
    delete pInfo;
    pInfo = nullptr;
    pProx = nullptr;
}

template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::incluir(TE* p) {
    pInfo = p;
}

template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pE) {
    pProx = pE;
}

template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>* Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}

template <typename TL>
template <typename TE>
TE* Lista<TL>::Elemento<TE>::getInfo() const {
    return pInfo;
}

/* 
 * Métodos de Lista<TL>
 *
 */

template <typename TL>
Lista<TL>::Lista()
    : pPrimeiro(nullptr)
    , pUltimo(nullptr)
{
}

template <typename TL>
Lista<TL>::~Lista() {
    limpar();
    pPrimeiro = nullptr;
    pUltimo = nullptr;
}

template <typename TL>
void Lista<TL>::incluir(TL* p) {
    Elemento<TL>* pNovo = new Elemento<TL>();
    pNovo->incluir(p);

    if (pUltimo) {
        pUltimo->setProx(pNovo);
        pUltimo = pNovo;
    }
    else {
        pPrimeiro = pNovo;
        pUltimo = pNovo;
    }
}

template <typename TL>
void Lista<TL>::limpar() {
    while (pPrimeiro) {
        Elemento<TL>* aux = pPrimeiro;
        pPrimeiro = pPrimeiro->getProximo();
        delete aux;
    }

    pUltimo = nullptr;
}

template <typename TL>
void Lista<TL>::imprimir() {
    Elemento<TL>* iterador = pPrimeiro;

    std::cout << "Lista: ";
    while (iterador != nullptr) {
        std::cout << *(iterador->getInfo()) << " ";
        iterador = iterador->getProximo();
    }
    std::cout << std::endl;
}
