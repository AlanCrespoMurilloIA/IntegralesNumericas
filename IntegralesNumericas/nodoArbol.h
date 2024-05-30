#pragma once

#include <string>
#include <iostream>
//holaaaa siuuu
class nodoArbol{
public:
    //Aquí creamos la estructura de todos los nodos
    nodoArbol(std::string, nodoArbol*, int, int);
    bool esNum(const std::string&);
    nodoArbol* padre = nullptr;
    nodoArbol* primogenito = nullptr;
    nodoArbol* hermanoMenor = nullptr;
    double valAux = 0;
    int nivel, numHijos = 0, contHijos = 0;
    bool checado = false;
    std::string termino;
};
