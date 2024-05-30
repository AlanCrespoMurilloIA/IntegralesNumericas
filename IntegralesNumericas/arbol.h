#pragma once

#include <iostream>
#include "nodoArbol.h"

class Arbol {
private:
    nodoArbol* tronco = nullptr;
    
public:
    Arbol(std::string, int);
    nodoArbol* insert(std::string, nodoArbol*, int);
    nodoArbol* getTronco() {return tronco;};
    void imprimirRama(nodoArbol*nodo);
};
