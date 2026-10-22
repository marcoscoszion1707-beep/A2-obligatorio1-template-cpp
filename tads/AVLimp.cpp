#ifndef AVL_IMP
#define AVL_IMP

#include "AVL.h"
#include <algorithm>
#include <iostream>

using namespace std;

template <class T> class AVLImp : public AVL<T> {
  private:
    struct NodoAVL {
        T dato;
        int altura;
        NodoAVL *izq;
        NodoAVL *der;

        NodoAVL(T elem) {
            dato = elem;
            altura = 1;
            izq = der = NULL;
        }
    };

    NodoAVL *raiz;

    int getAltura(NodoAVL *nodo) {
        if (!nodo)
            return 0;
        return nodo->altura;
    }

    void actualizarAltura(NodoAVL *nodo) {
        nodo->altura = 1 + max(getAltura(nodo->izq), getAltura(nodo->der));
    }

    int getBalance(NodoAVL *nodo) {
        if (!nodo)
            return 0;
        return getAltura(nodo->der) - getAltura(nodo->izq);
    }

    NodoAVL *rotacionDerecha(NodoAVL *nodo) {
        NodoAVL *hijoIzq = nodo->izq;
        NodoAVL *subarbolMedio = hijoIzq->der;
        hijoIzq->der = nodo;
        nodo->izq = subarbolMedio;
        actualizarAltura(nodo);
        actualizarAltura(hijoIzq);
        return hijoIzq;
    }

    NodoAVL *rotacionIzquierda(NodoAVL *nodo) {
        NodoAVL *hijoDer = nodo->der;
        NodoAVL *subarbolMedio = hijoDer->izq;
        hijoDer->izq = nodo;
        nodo->der = subarbolMedio;
        actualizarAltura(nodo);
        actualizarAltura(hijoDer);
        return hijoDer;
    }

    NodoAVL *balancear(NodoAVL *nodo) {
        actualizarAltura(nodo);
        int balance = getBalance(nodo);

        if (balance < -1) {
            if (getBalance(nodo->izq) > 0) {
                nodo->izq = rotacionIzquierda(nodo->izq);
            }
            return rotacionDerecha(nodo);
        }

        if (balance > 1) {
            if (getBalance(nodo->der) < 0) {
                nodo->der = rotacionDerecha(nodo->der);
            }
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    NodoAVL *insertarRec(NodoAVL *nodo, T elem) {
        if (!nodo)
            return new NodoAVL(elem);

        if (elem < nodo->dato) {
            nodo->izq = insertarRec(nodo->izq, elem);
        } else if (elem > nodo->dato) {
            nodo->der = insertarRec(nodo->der, elem);
        } else {
            return nodo;
        }

        return balancear(nodo);
    }

    bool buscarRec(NodoAVL *nodo, T elem) {
        if (!nodo)
            return false;
        if (elem == nodo->dato)
            return true;
        if (elem < nodo->dato)
            return buscarRec(nodo->izq, elem);
        return buscarRec(nodo->der, elem);
    }

    void rangoRec(NodoAVL *nodo, T min, T max) {
        if (!nodo)
            return;

        bool estaSobreElMin = nodo->dato >= min;
        bool estaBajoElMax = nodo->dato <= max;

        if (estaSobreElMin) {
            rangoRec(nodo->izq, min, max);
        }

        if (estaSobreElMin && estaBajoElMax) {
            cout << nodo->dato << endl;
        }

        if (estaBajoElMax) {
            rangoRec(nodo->der, min, max);
        }
    }

  public:
    AVLImp() {
        raiz = NULL;
    }

    void insertar(T elem) {
        raiz = insertarRec(raiz, elem);
    }

    bool buscar(T elem) {
        return buscarRec(raiz, elem);
    }

    void rango(T min, T max) {
        rangoRec(raiz, min, max);
    }
};

#endif