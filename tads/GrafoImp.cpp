#ifndef GRAFO_IMP
#define GRAFO_IMP

#include "Grafo.h"

class GrafoImp : public Grafo {
  private:
    bool dirigido;
    int vertices;
    Arista **listaAdy;

  public:
    GrafoImp(bool esDirigido, int cantVertices) {
        dirigido = esDirigido;
        vertices = cantVertices;
        listaAdy = new Arista *[vertices + 1];
        for (int i = 0; i <= vertices; i++) {
            listaAdy[i] = NULL;
        }
    }
    ~GrafoImp() {
        for (int i = 0; i <= vertices; i++) {
            Arista *actual = listaAdy[i];
            while (actual != NULL) {
                Arista *aBorrar = actual;
                actual = actual->sig;
                delete aBorrar;
            }
        }
        delete[] listaAdy;
    }
    void agregarArista(int origen, int destino, int peso = 1) {
        listaAdy[origen] = new Arista(origen, destino, peso, listaAdy[origen]);
        if (!dirigido) {
            listaAdy[destino] = new Arista(destino, origen, peso, listaAdy[destino]);
        }
    }
    Arista *adyacentes(int vertice) {
        return listaAdy[vertice];
    }
    int cantidadVertices() {
        return vertices;
    }
};

#endif