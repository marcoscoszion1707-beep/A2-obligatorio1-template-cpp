#ifndef MFSET_IMP
#define MFSET_IMP

#include "Mfset.h"

class MFSetImp : public MFSet {
  private:
    int *padre;  
    int *altura; 
    int cantidad;

  public:
    MFSetImp(int unaCantidad) {
        cantidad = unaCantidad;
        padre = new int[cantidad + 1];
        altura = new int[cantidad + 1];
        for (int i = 0; i <= cantidad; i++) {
            padre[i] = i;
            altura[i] = 0;
        }
    }
    ~MFSetImp() {
        delete[] padre;
        delete[] altura;
    }
    int buscar(int elem) {
        if (padre[elem] == elem){
            return elem;
        }
        padre[elem] = buscar(padre[elem]);
        return padre[elem];
    }

    void unir(int a, int b) {
        int repA = buscar(a);
        int repB = buscar(b);
        if (repA == repB) return;
        if (altura[repA] < altura[repB]) {
            padre[repA] = repB;
        } else if (altura[repA] > altura[repB]) {
            padre[repB] = repA;
        } else {
            padre[repB] = repA;
            altura[repA]++;
        }
    }
};

#endif