#pragma once
#include "Jogo.h"

/* Lista Encadeada de tipo genérico */

template <typename TL>
class Lista {
private:
    // Classe Elemento para cada elemento individual
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
        TE getInfo() const;
    };

    // Ponteiros para o primeiro e último elemento da lista
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista();
    ~Lista();

    void incluir(TL* p); // Adiciona 'p' no final da lista
    void remover(TL* p); // Remove 'p' da lista
    void limpar(); // Limpa a lista

    class Iterator {
    private:
        Elemento<TL>* pAtual;
    
    public:
        Iterator(Elemento<TL>* pE);
        Iterator();
        ~Iterator();

        // Avança para o próximo elemento
        Iterator& operator++();

        // Verifica se dois iteradores são diferentes
        bool operator!=(const Iterator& outro) const;

        // Retorna o valor do elemento atual
        TL operator*() const;
    };

    // Retorna o iterador inicial (primeiro elemento)
    Iterator begin() const;
    
    // Retorna um iterador para nullptr, o fim da lista
    Iterator end() const;
};

/* 
 * Métodos de Lista<TL>::Elemento<TE>
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
TE Lista<TL>::Elemento<TE>::getInfo() const {
    return *pInfo;
}

/* 
 * Métodos de Lista<TL>
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
void Lista<TL>::remover(TL* p) {
    // TODO
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
typename Lista<TL>::Iterator Lista<TL>::begin() const {
    return Iterator(pPrimeiro);
}

template <typename TL>
typename Lista<TL>::Iterator Lista<TL>::end() const {
    return Iterator(nullptr);
}

/*
 * Métodos de Lista<TL>::Iterator
 */
template <typename TL>
Lista<TL>::Iterator::Iterator(Elemento<TL>* pE)
    : pAtual(pE)
{
}

template <typename TL>
Lista<TL>::Iterator::Iterator()
    : pAtual(nullptr)
{
}

template <typename TL>
Lista<TL>::Iterator::~Iterator() {
    pAtual = nullptr;
}

template <typename TL>
typename Lista<TL>::Iterator& Lista<TL>::Iterator::operator++() {
    if (pAtual)
        pAtual = pAtual->getProximo();

    return *this;
}

template <typename TL>
bool Lista<TL>::Iterator::operator!=(const Iterator& outro) const {
    return pAtual != outro.pAtual;
}

template <typename TL>
TL Lista<TL>::Iterator::operator*() const {
    return pAtual->getInfo();
}
