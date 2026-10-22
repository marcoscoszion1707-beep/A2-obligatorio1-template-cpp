#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MinHeap.h"
#include "tads/MinHeapImp.cpp"

using namespace std;

int main() {
    int n;
    cin >> n;
    MinHeap<long long> *archivos = new MinHeapImp<long long>(n);
    for (int i = 0; i < n; i++) {
        long long tamaño;
        cin >> tamaño;
        archivos->insertar(tamaño);
    }
    long long costoTotal = 0;
    while (archivos->cantidad() > 1) {
        long long masChico = archivos->eliminarMin();
        long long segundoMasChico = archivos->eliminarMin();
        long long archivoNuevo = masChico + segundoMasChico;
        costoTotal += archivoNuevo;
        archivos->insertar(archivoNuevo);
    }
    cout << costoTotal << endl;
    delete archivos;
    return 0;
}