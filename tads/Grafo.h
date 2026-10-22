#ifndef GRAFO_H
#define GRAFO_H

struct Arista {
    int origen;
    int destino;
    int peso;
    Arista *sig;

    Arista(int unOrigen, int unDestino, int unPeso, Arista *unSig) {
        origen = unOrigen;
        destino = unDestino;
        peso = unPeso;
        sig = unSig;
    }
};

class Grafo {
  public:
    virtual ~Grafo() {}

    // pre: 1 <= origen, destino <= cantidad de vértices
    // pos: agrega la arista origen -> destino (y destino -> origen si no es dirigido)
    virtual void agregarArista(int origen, int destino, int peso = 1) = 0;

    // pre: 1 <= vertice <= cantidad de vértices
    // pos: devuelve la lista de aristas que salen del vértice (NULL si no tiene)
    virtual Arista *adyacentes(int vertice) = 0;

    // pre: -
    // pos: devuelve la cantidad de vértices del grafo
    virtual int cantidadVertices() = 0;
};

#endif