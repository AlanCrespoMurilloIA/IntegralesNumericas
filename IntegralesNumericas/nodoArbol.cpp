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
        valAux = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208;
    else if(term == "e")
        valAux = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547;
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
