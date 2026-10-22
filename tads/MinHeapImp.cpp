#ifndef MIN_HEAP_IMP
#define MIN_HEAP_IMP

#include "MinHeap.h"

template <class T> class MinHeapImp : public MinHeap<T> {
  private:
    T *elementos;
    int tope; 
    int capacidad;

    int padre(int pos) {
        return pos / 2;
    }

    int hijoIzq(int pos) {
        return pos * 2;
    }

    int hijoDer(int pos) {
        return pos * 2 + 1;
    }

    void intercambiar(int pos1, int pos2) {
        T aux = elementos[pos1];
        elementos[pos1] = elementos[pos2];
        elementos[pos2] = aux;
    }
    void flotar(int pos) {
        if (pos == 1)
            return;
        int posPadre = padre(pos);
        if (elementos[pos] < elementos[posPadre]) {
            intercambiar(pos, posPadre);
            flotar(posPadre);
        }
    }
    void hundir(int pos) {
        if (hijoIzq(pos) > tope)
            return;
        int posHijoMenor = hijoIzq(pos);
        if (hijoDer(pos) <= tope && elementos[hijoDer(pos)] < elementos[posHijoMenor]) {
            posHijoMenor = hijoDer(pos);
        }
        if (elementos[posHijoMenor] < elementos[pos]) {
            intercambiar(pos, posHijoMenor);
            hundir(posHijoMenor);
        }
    }

  public:
    MinHeapImp(int unaCapacidad) {
        capacidad = unaCapacidad;
        elementos = new T[capacidad + 1];
        tope = 0;
    }

    ~MinHeapImp() {
        delete[] elementos;
    }

    void insertar(T elem) {
        tope++;
        elementos[tope] = elem;
        flotar(tope);
    }

    T eliminarMin() {
        T minimo = elementos[1];
        elementos[1] = elementos[tope];
        tope--;
        if (tope > 0) {
            hundir(1);
        }
        return minimo;
    }

    int cantidad() {
        return tope;
    }

    bool esVacio() {
        return tope == 0;
    }
};

#endif