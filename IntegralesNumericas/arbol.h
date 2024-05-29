#pragma once

#include <iostream>
#include "nodoArbol.h"

class Arbol {
private:
    nodoArbol* padre = NULL;
    
public:
    void insert(std::string, double, nodoArbol*);
    
};



