#ifndef MFSET_H
#define MFSET_H

class MFSet {
  public:
    virtual ~MFSet() {}

    // pre: 1 <= elem <= cantidad de elementos
    // pos: devuelve el representante del conjunto de elem
    virtual int buscar(int elem) = 0;

    // pre: 1 <= a, b <= cantidad de elementos
    // pos: une los conjuntos de a y b (si ya estaban juntos no hace nada)
    virtual void unir(int a, int b) = 0;
};

#endif