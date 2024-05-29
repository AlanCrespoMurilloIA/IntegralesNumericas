#pragma once

#include <iostream>
#include "nodoArbol.h"

class Arbol {
private:
    nodoArbol* tronco = nullptr;
    
public:
    nodoArbol* insert(std::string, nodoArbol*);
    Arbol(std::string operando);
    nodoArbol* getTronco();
    void imprimirRama(nodoArbol*nodo);

 
    
};



