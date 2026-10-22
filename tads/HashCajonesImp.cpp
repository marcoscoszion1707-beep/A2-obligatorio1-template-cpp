#ifndef HASH_CAJONES_IMP
#define HASH_CAJONES_IMP

#include "HashCajones.h"
#include <string>

using namespace std;

class HashCajonesImp : public HashCajones {
  private:
    struct NodoLista {
        string clave;
        int palabras;
        NodoLista *sig;

        NodoLista(string unaClave, NodoLista *unSig) {
            clave = unaClave;
            palabras = 1;
            sig = unSig;
        }
    };

    NodoLista **tabla;
    int tamanio;
    int cajones;
    int mayor;

    bool esPrimo(int numero) {
        if (numero < 2)
            return false;
        for (int i = 2; i * i <= numero; i++) {
            if (numero % i == 0)
                return false;
        }
        return true;
    }

    int primoMayorOIgual(int numero) {
        while (!esPrimo(numero)) {
            numero++;
        }
        return numero;
    }

    int funcionHash(string clave) {
        long long hash = 0;
        for (int i = 0; i < clave.length(); i++) {
            hash = (hash * 31 + clave[i]) % tamanio;
        }
        return hash;
    }

    NodoLista *buscarNodo(string clave) {
        NodoLista *actual = tabla[funcionHash(clave)];
        while (actual != NULL) {
            if (actual->clave == clave)
                return actual;
            actual = actual->sig;
        }
        return NULL;
    }

  public:
    HashCajonesImp(int cantidadMaxima) {
        tamanio = primoMayorOIgual(cantidadMaxima);
        tabla = new NodoLista *[tamanio];
        for (int i = 0; i < tamanio; i++) {
            tabla[i] = NULL;
        }
        cajones = 0;
        mayor = 0;
    }

    ~HashCajonesImp() {
        for (int i = 0; i < tamanio; i++) {
            NodoLista *actual = tabla[i];
            while (actual != NULL) {
                NodoLista *aBorrar = actual;
                actual = actual->sig;
                delete aBorrar;
            }
        }
        delete[] tabla;
    }

    void insertar(string clave) {
        NodoLista *nodo = buscarNodo(clave);
        if (nodo != NULL) {
            nodo->palabras++;
        } else {
            int posicion = funcionHash(clave);
            nodo = new NodoLista(clave, tabla[posicion]);
            tabla[posicion] = nodo;
            cajones++;
        }
        if (nodo->palabras > mayor) {
            mayor = nodo->palabras;
        }
    }

    int palabrasEnCajon(string clave) {
        NodoLista *nodo = buscarNodo(clave);
        if (nodo == NULL)
            return 0;
        return nodo->palabras;
    }

    int cantidadCajones() {
        return cajones;
    }

    int mayorCajon() {
        return mayor;
    }
};

#endif