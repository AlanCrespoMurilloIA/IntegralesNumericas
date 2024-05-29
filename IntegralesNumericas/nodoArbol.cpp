#include "nodoArbol.h"

nodoArbol::nodoArbol(std::string term, double valor, nodoArbol* ancestro){
    padre = ancestro;
    valAux = valor;
    termino = term;
}
