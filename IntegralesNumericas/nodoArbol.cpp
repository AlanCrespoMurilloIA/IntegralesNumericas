#include "nodoArbol.h"

nodoArbol::nodoArbol(std::string term, nodoArbol* ancestro, int profundidad, int hijos){
    padre = ancestro;
    termino = term;
    nivel = profundidad;
    numHijos = hijos;
    
    //Si el termino es una constante, el valor auxiliar tambien se modifica
    if(esNum(term))
        valAux = std::stod(term);
    else if(term == "pi")
        valAux = 3.1415926535897;
    else if(term == "e")
        valAux = 2.7182818284590;
}

bool nodoArbol::esNum(const std::string& str) {
    if (str.empty())
        return false;

    for (char const &ch : str)
        if (std::isdigit(ch) || ch == '.') {
            return true;  //solo se aceptan los dijitos 0 - 9 y el punto '.'
                           //Asi tambien evitamos numeros negativos
        }
    return false;  // El valor no es un numero
}
