#ifndef HASH_CAJONES_H
#define HASH_CAJONES_H

#include <string>

using namespace std;

class HashCajones {
  public:
    virtual ~HashCajones() {}

    // pre: -
    // pos: si el cajón de la clave no existe lo crea con 1 palabra,
    //      si ya existe le suma 1 palabra
    virtual void insertar(string clave) = 0;

    // pre: -
    // pos: devuelve cuántas palabras tiene el cajón de la clave (0 si no existe),
    //      sin modificar la tabla
    virtual int palabrasEnCajon(string clave) = 0;

    // pre: -
    // pos: devuelve la cantidad de cajones distintos
    virtual int cantidadCajones() = 0;

    // pre: -
    // pos: devuelve la cantidad de palabras del cajón más grande
    virtual int mayorCajon() = 0;
};

#endif