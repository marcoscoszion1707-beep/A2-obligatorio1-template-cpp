#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.h"
#include "tads/AVLImp.cpp"

using namespace std;

int main() {
    AVL<long long> *monedas = new AVLImp<long long>();
    AVL<string> *pinturas = new AVLImp<string>();
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string operacion;
        char coleccion;
        cin >> operacion >> coleccion;
 
        if (coleccion == 'M') {
            if (operacion == "ALTA") {
                long long catalogo;
                cin >> catalogo;
                monedas->insertar(catalogo);
            } else if (operacion == "BUSCAR") {
                long long catalogo;
                cin >> catalogo;
                if (monedas->buscar(catalogo)) {
                    cout << "si" << endl;
                } else {
                    cout << "no" << endl;
                }
            } else if (operacion == "RANGO") {
                long long desde, hasta;
                cin >> desde >> hasta;
                monedas->rango(desde, hasta);
            }
        } else {
            if (operacion == "ALTA") {
                string titulo;
                cin >> titulo;
                pinturas->insertar(titulo);
            } else if (operacion == "BUSCAR") {
                string titulo;
                cin >> titulo;
                if (pinturas->buscar(titulo)) {
                    cout << "si" << endl;
                } else {
                    cout << "no" << endl;
                }
            } else if (operacion == "RANGO") {
                string desde, hasta;
                cin >> desde >> hasta;
                pinturas->rango(desde, hasta);
            }
        }
    }
    return 0;
}