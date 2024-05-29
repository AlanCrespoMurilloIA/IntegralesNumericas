#include "nodoArbol.h"

nodoArbol::nodoArbol(std::string term, nodoArbol* ancestro,int profundidad){
    padre = ancestro;
    //valAux = valor;
    termino = term;
    nivel = profundidad;
}
