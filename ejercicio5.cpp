#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MFSet.h"
#include "tads/MFSetImp.cpp"
#include "tads/MinHeap.h"
#include "tads/MinHeapImp.cpp"

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    int *refugioA = new int[e];
    int *refugioB = new int[e];
    long long base = e + 1;
    MinHeap<long long> *senderos = new MinHeapImp<long long>(e);
    for (int i = 0; i < e; i++) {
        long long costo;
        cin >> refugioA[i] >> refugioB[i] >> costo;
        senderos->insertar(costo * base + i);
    }
    MFSet *grupos = new MFSetImp(v);
    long long costoTotal = 0;
    int senderosMantenidos = 0;
    while (!senderos->esVacio() && senderosMantenidos < v-1) {
        long long clave = senderos->eliminarMin();
        int indice = clave % base;
        long long costo = clave / base;
        int a = refugioA[indice];
        int b = refugioB[indice];
        if (grupos->buscar(a) != grupos->buscar(b)) {
            grupos->unir(a, b);
            costoTotal += costo;
            senderosMantenidos++;
        }
    }

    if (senderosMantenidos < v - 1) {
        cout << "imposible" << endl;
    } else {
        cout << costoTotal << endl;
    }

    delete senderos;
    delete grupos;
    delete[] refugioA;
    delete[] refugioB;
    return 0;
}