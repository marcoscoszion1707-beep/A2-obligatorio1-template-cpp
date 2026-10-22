#ifndef AVL_H
#define AVL_H

template <class T> class AVL {
  public:
    // pre: -
    // pos: inserta elem en el árbol. Si ya estaba, no hace nada
    virtual void insertar(T elem) = 0;

    // pre: -
    // pos: devuelve true si elem está en el árbol, false en caso contrario
    virtual bool buscar(T elem) = 0;

    // pre: min <= max
    // pos: imprime en orden los elementos x tales que min <= x <= max, uno por línea
    virtual void rango(T min, T max) = 0;
};

#endif