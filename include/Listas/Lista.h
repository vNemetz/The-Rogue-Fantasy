#pragma once

/* Lista Encadeada de tipo genérico */

namespace lis {

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
        TE* getInfo() const;
    };

private:
    // Ponteiros para o primeiro e último elemento da lista
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

    unsigned int tamanho;

public:
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
        TL* operator*() const;

        // Retorna o ponteiro do elemento atual
        Elemento<TL>* getElemento() const {return pAtual;}
    };

public:
    Lista();
    ~Lista();

    void incluir(TL* p); // Adiciona 'p' no final da lista
    void remover(TL* p); // Remove 'p' da lista
    void remover(unsigned int index);
    void limpar(); // Limpa a lista
    unsigned int getTamanho() const {return tamanho;}
    TL* operator[](unsigned int index) const;

    Iterator begin() const; // Retorna o iterador inicial (primeiro elemento)
    Iterator end() const; // Retorna um iterador para nullptr, o fim da lista
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
typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}

template <typename TL>
template <typename TE>
TE* Lista<TL>::Elemento<TE>::getInfo() const {
    return pInfo;
}

/* 
 * Métodos de Lista<TL>
 */
template <typename TL>
Lista<TL>::Lista()
    : pPrimeiro(nullptr)
    , pUltimo(nullptr)
    , tamanho(0)
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

    if (tamanho == 0) {
        pPrimeiro = pNovo;
        pUltimo = pNovo;
    }
    
    else {
        pUltimo->setProx(pNovo);
        pUltimo = pNovo;
    }
    
    tamanho++;
}

template <typename TL>
void Lista<TL>::remover(TL* p) {
    Iterator it = begin();
    Iterator anterior = end();

    while (it != end() && *it != p) {
        anterior = it;
        ++it;
    }

    if (it != end()) {
        Elemento<TL>* atual = it.getElemento();

        if (atual == pPrimeiro) {
            pPrimeiro = atual->getProximo();
            // Se a lista ficou vazia, atualiza pUltimo também
            if (pPrimeiro == nullptr) {
                pUltimo = nullptr;
            }
        } 
        else if (atual == pUltimo) {
            pUltimo = anterior.getElemento();
            // Define o próximo do novo último elemento como nullptr
            if (anterior != end()) {
                anterior.getElemento()->setProx(nullptr);
            }
        } 
        else {
            // Atualiza o próximo do elemento anterior
            anterior.getElemento()->setProx(atual->getProximo());
        }

        delete atual;
        tamanho--;
    }
}

template <typename TL>
void Lista<TL>::remover(unsigned int index) {
    // Verifica se o índice é válido
    if (index >= tamanho) {
        return; // Índice fora dos limites, não faz nada
    }

    Iterator it = begin();
    Iterator anterior = end(); // Representa o iterador anterior como inválido inicialmente
    unsigned int contador = 0;

    // Percorre a lista até encontrar o índice desejado
    while (it != end() && contador < index) {
        anterior = it;
        ++it;
        contador++;
    }

    // Se o índice foi encontrado, remove o elemento
    if (it != end()) {
        Elemento<TL>* atual = it.getElemento();

        // Atualiza os ponteiros da lista
        if (atual == pPrimeiro) {
            pPrimeiro = atual->getProximo();
        } else if (atual == pUltimo) {
            pUltimo = anterior.getElemento();
        } else {
            (anterior.getElemento())->setProx(atual->getProximo());
        }

        // Remove o elemento
        delete atual;
        tamanho--;
    }
}

template <typename TL>
void Lista<TL>::limpar() {
    Iterator it = begin();

    while (it != end()) {
        Elemento<TL>* aux = it.getElemento();
        ++it;
        delete aux;
    }

    pPrimeiro = nullptr;
    pUltimo = nullptr;
    tamanho = 0;
}

template <typename TL>
TL* Lista<TL>::operator[](unsigned int index) const {
    if (index >= tamanho) {
        return nullptr; // Índice fora dos limites
    }
    
    Lista<TL>::Iterator atual = begin();
    for (int i = 0; i < index; i++)
        ++atual;
    
    return *atual;
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
TL* Lista<TL>::Iterator::operator*() const {
    return pAtual->getInfo();
}

}
