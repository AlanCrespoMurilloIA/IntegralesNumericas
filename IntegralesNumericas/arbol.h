#pragma once

#include <iostream>
#include "nodoArbol.h"

class Arbol {
private:
    nodoArbol* tronco = nullptr;
    
public:
    void insert(std::string, nodoArbol*);
    Arbol(std::string operando);
    nodoArbol* getTronco();
 
    
};



