#pragma once

#include <string>

class nodoArbol{
public:
    //Aquí creamos la estructura de todos los nodos
    nodoArbol(std::string, double, nodoArbol*);
    nodoArbol* padre = NULL;
    nodoArbol* primogenito = NULL;
    nodoArbol* hermanoMenor = NULL;
    double valAux = null;
    int nivel;
    std::string termino;
};

//prueba de paralelismo