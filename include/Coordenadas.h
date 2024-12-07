#pragma once

namespace mat {

template <typename TC>
class Coord {
public:
    TC x;
    TC y;

public:
    Coord();
    Coord(TC x, TC y);
    ~Coord() {}

    // Atribuição e operadores de modificação
    void operator=(const Coord<TC>& outra);
    void operator+=(const Coord<TC>& outra);
    void operator-=(const Coord<TC>& outra);
    void operator/=(const Coord<TC>& outra);
    void operator*=(const Coord<TC>& outra);
    void operator/=(double escalar);
    void operator*=(double escalar);

    // Operadores binários que retornam um novo objeto
    Coord<TC> operator+(const Coord<TC>& outra) const;
    Coord<TC> operator-(const Coord<TC>& outra) const;
    Coord<TC> operator*(const Coord<TC>& outra) const;
    Coord<TC> operator/(const Coord<TC>& outra) const;
    Coord<TC> operator*(double escalar) const;
    Coord<TC> operator/(double escalar) const;
};

// Tipos alias
typedef Coord<double> CoordD;
typedef Coord<float> CoordF;
typedef Coord<int> CoordI;
typedef Coord<unsigned int> CoordU;

// Implementação dos métodos da classe

template <typename TC>
Coord<TC>::Coord(TC xPar, TC yPar): x(xPar), y(yPar) {}

template<typename TC>
void Coord<TC>::operator=(const Coord<TC>& outra) {
    x = outra.x;
    y = outra.y;
}

template<typename TC>
void Coord<TC>::operator+=(const Coord<TC>& outra) {
    x += outra.x;
    y += outra.y;
}

template<typename TC>
void Coord<TC>::operator-=(const Coord<TC>& outra) {
    x -= outra.x;
    y -= outra.y;
}

template<typename TC>
void Coord<TC>::operator/=(const Coord<TC>& outra) {
    x /= outra.x;
    y /= outra.y;
}

template<typename TC>
void Coord<TC>::operator*=(const Coord<TC>& outra) {
    x *= outra.x;
    y *= outra.y;
}

template<typename TC>
void Coord<TC>::operator*=(double escalar) {
    x *= escalar;
    y *= escalar;
}

template<typename TC>
void Coord<TC>::operator/=(double escalar) {
    x /= escalar;
    y /= escalar;
}

// Operadores binários com retorno de novo objeto
template<typename TC>
Coord<TC> Coord<TC>::operator+(const Coord<TC>& outra) const {
    return Coord<TC>(x + outra.x, y + outra.y);
}

template<typename TC>
Coord<TC> Coord<TC>::operator-(const Coord<TC>& outra) const {
    return Coord<TC>(x - outra.x, y - outra.y);
}

template<typename TC>
Coord<TC> Coord<TC>::operator*(const Coord<TC>& outra) const {
    return Coord<TC>(x * outra.x, y * outra.y);
}

template<typename TC>
Coord<TC> Coord<TC>::operator/(const Coord<TC>& outra) const {
    return Coord<TC>(x / outra.x, y / outra.y);
}

template<typename TC>
Coord<TC> Coord<TC>::operator*(double escalar) const {
    return Coord<TC>(x * escalar, y * escalar);
}

template<typename TC>
Coord<TC> Coord<TC>::operator/(double escalar) const {
    return Coord<TC>(x / escalar, y / escalar);
}

}