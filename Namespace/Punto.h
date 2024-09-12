#ifndef PROGRAMACION_3_NAMESPACES_H
#define PROGRAMACION_3_NAMESPACES_H

namespace utec {
    struct Punto {
        int x = 0;
        int y = 0;
        int get_x();
        int get_y();
        Punto(int x, int y);
    };
}

#endif //PROGRAMACION_3_NAMESPACES_H
