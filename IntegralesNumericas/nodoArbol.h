#pragma once

#include <string>
//holaaaa siuuu
class nodoArbol{
public:
    //Aquí creamos la estructura de todos los nodos
    nodoArbol(std::string, double, nodoArbol*);
    nodoArbol* padre = NULL;
    nodoArbol* primogenito = NULL;
    nodoArbol* hermanoMenor = NULL;
    double valAux = 0;
    int nivel;
    std::string termino;
};
