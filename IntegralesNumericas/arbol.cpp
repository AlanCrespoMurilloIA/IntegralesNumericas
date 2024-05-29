#include "arbol.h"

void Arbol::insert(std::string termino, double valor, nodoArbol * nodoPadre){
    nodoArbol* nodo = new nodoArbol(termino, valor, nodoPadre);
    
}
