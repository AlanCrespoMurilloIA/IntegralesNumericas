#pragma once

#include <string>
//holaaaa siuuu
class nodoArbol{
public:
    //Aquí creamos la estructura de todos los nodos
    nodoArbol();
    nodoArbol* padre = NULL;
    nodoArbol* primogenito = NULL;
    nodoArbol* hermanoMenor = NULL;
    double valAux = null;
    int nivel;
    std::string termino;
};
