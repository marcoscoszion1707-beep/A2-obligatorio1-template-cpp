#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HashCajones.h"
#include "tads/HashCajonesImp.cpp"

using namespace std;

string claveDelCajon(string palabra) {
    int apariciones[26];
    for (int i = 0; i < 26; i++) {
        apariciones[i] = 0;
    }
    for (int i = 0; i < palabra.length(); i++) {
        apariciones[palabra[i] - 'a']++;
    }
    string clave = "";
    for (int letra = 0; letra < 26; letra++) {
        for (int j = 0; j < apariciones[letra]; j++) {
            clave += (char)('a' + letra);
        }
    }
    return clave;
}

int main() {
    int n;
    cin >> n;
    HashCajones *cajones = new HashCajonesImp(n);
    for (int i = 0; i < n; i++) {
        string palabra;
        cin >> palabra;
        cajones->insertar(claveDelCajon(palabra));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string consulta;
        cin >> consulta;
        cout << cajones->palabrasEnCajon(claveDelCajon(consulta)) << endl;
    }
    cout << cajones->cantidadCajones() << " " << cajones->mayorCajon() << endl;
    delete cajones;
    return 0;
}