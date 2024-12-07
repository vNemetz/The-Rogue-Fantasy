#pragma once

namespace mat{
    
template <typename TC>
class Coord{
public:
    TC x;
    TC y;

public:
    Coord();
    Coord(TC x, TC y);
    ~Coord(){}

    void operator=(Coord<TC> outra);
    void operator+=(Coord<TC> outra);
    void operator-=(Coord<TC> outra);
    void operator/=(Coord<TC> outra);
    void operator*=(Coord<TC> outra);
    void operator/=(double escalar);
    void operator*=(double escalar);

    Coord<TC> operator+(Coord<TC> outra);
    Coord<TC> operator-(Coord<TC> outra);
    Coord<TC> operator*(Coord<TC> outra);
    Coord<TC> operator/(Coord<TC> outra);
    Coord<TC> operator*(double escalar);
    Coord<TC> operator*(double escalar);
}

template<typename TC>
void operator=(Coord<TC> outra){
    x = outra.x;
    y = outra.y;
}
void operator+=(Coord<TC> outra){
    x += outra.x;
    y += outra.y;
}
void operator-=(Coord<TC> outra){
    x -= outra.x;
    y -= outra.y;
}
void operator/=(Coord<TC> outra){
    x /= outra.x;
    y /= outra.y;
}
void operator*=(Coord<TC> outra){
    x *= outra.x;
    y *= outra.y;
}
void operator*=(double escalar){
    x *= escalar;
    y *= escalar;
}void operator/=(double escalar){
    x /= escalar;
    y /= escalar;
}
Coord<TC> operator+(Coord<TC> outra){
    x+=outra.x;
    y+=outra.y;
    return this;
}
Coord<TC> operator-(Coord<TC> outra){
    x-=outra.x;
    y-=outra.y;
    return this;
}
Coord<TC> operator*(Coord<TC> outra){
    x*=outra.x;
    y*=outra.y;
    return this;
}
Coord<TC> operator/(Coord<TC> outra){
    x/=outra.x;
    y/=outra.y;
    return this;
}
Coord<TC> operator*(double escalar){
    x *= escalar;
    y *= escalar;
    return this;
}
Coord<TC> operator/(double escalar){
    x /= escalar;
    y /= escalar;
    return this;
}



}