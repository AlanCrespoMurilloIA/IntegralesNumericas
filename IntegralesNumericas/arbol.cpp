#include "arbol.h"

void Arbol::insert(std::string termino, nodoArbol * nodoPadre){
    nodoArbol* nodo = new nodoArbol(termino, nodoPadre);
    if (tronco == nullptr)
    {
        tronco = nodo;
        return;
    }
    nodoArbol *aux = nodoPadre->primogenito;
    while (aux != nullptr)
    {
        aux = aux->hermanoMenor;
    }
    aux->hermanoMenor = nodo;
    return;
}
Arbol::Arbol(std::string operando)
{
    insert(operando, nullptr);
    return;
}
nodoArbol* Arbol::getTronco()
{
    return tronco;
}
