#pragma once

#include <string>
//holaaaa siuuu
class nodoArbol{
public:
    //Aquí creamos la estructura de todos los nodos
    nodoArbol(std::string, nodoArbol*);
    nodoArbol* padre = nullptr;
    nodoArbol* primogenito = nullptr;
    nodoArbol* hermanoMenor = nullptr;
    double valAux = 0;
    int nivel;
    std::string termino;
};
