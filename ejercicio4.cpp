#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Grafo.h"
#include "tads/GrafoImp.cpp"
#include "tads/MinHeap.h"
#include "tads/MinHeapImp.cpp"

using namespace std;

int main() {
    int v, a;
    cin >> v >> a;
    int *prioridad = new int[v + 1];
    for (int i = 1; i <= v; i++) {
        cin >> prioridad[i];
    }
    Grafo *dependencias = new GrafoImp(true, v);
    int *gradoEntrada = new int[v + 1];
    for (int i = 1; i <= v; i++) {
        gradoEntrada[i] = 0;
    }
    for (int i = 0; i < a; i++) {
        int antes, despues;
        cin >> antes >> despues;
        dependencias->agregarArista(antes, despues);
        gradoEntrada[despues]++;
    }
    long long base = v + 1;
    MinHeap<long long> *listos = new MinHeapImp<long long>(v);
    for (int i = 1; i <= v; i++) {
        if (gradoEntrada[i] == 0) {
            listos->insertar(prioridad[i] * base + i);
        }
    }
    int *orden = new int[v];
    int compilados = 0;
    while (!listos->esVacio()) {
        long long clave = listos->eliminarMin();
        int actual = clave % base;
        orden[compilados] = actual;
        compilados++;
        Arista *ady = dependencias->adyacentes(actual);
        while (ady != NULL) {
            gradoEntrada[ady->destino]--;
            if (gradoEntrada[ady->destino] == 0) {
                listos->insertar(prioridad[ady->destino] * base + ady->destino);
            }
            ady = ady->sig;
        }
    }

    if (compilados < v) {
        cout << "imposible" << endl;
    } else {
        for (int i = 0; i < v; i++) {
            cout << orden[i] << endl;
        }
    }

    delete listos;
    delete dependencias;
    delete[] prioridad;
    delete[] gradoEntrada;
    delete[] orden;
    return 0;
}