#include "nodoArbol.h"

nodoArbol::nodoArbol(std::string term, nodoArbol* ancestro){
    padre = ancestro;
    //valAux = valor;
    termino = term;
}
