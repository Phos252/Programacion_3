#include "Punto.h"

int utec::Punto::get_x() {
    return x;
}

int utec::Punto::get_y() {
    return y;
}

utec::Punto::Punto(int x, int y): x(x), y(y){}