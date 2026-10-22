#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <class T> class MinHeap {
  public:
    virtual ~MinHeap() {}

    // pre: el heap no está lleno
    // pos: agrega elem al heap
    virtual void insertar(T elem) = 0;

    // pre: el heap no es vacío
    // pos: saca el menor elemento del heap y lo devuelve
    virtual T eliminarMin() = 0;

    // pre: -
    // pos: devuelve la cantidad de elementos del heap
    virtual int cantidad() = 0;

    // pre: -
    // pos: devuelve true si el heap no tiene elementos
    virtual bool esVacio() = 0;
};

#endif