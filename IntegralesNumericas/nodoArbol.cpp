#include "nodoArbol.h"

nodoArbol::nodoArbol(std::string term, nodoArbol* ancestro, int profundidad, int hijos){
    padre = ancestro;
    termino = term;
    nivel = profundidad;
    numHijos = hijos;
}
