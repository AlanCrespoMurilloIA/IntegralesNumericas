#include "arbol.h"

nodoArbol* Arbol::insert(std::string termino, nodoArbol * nodoPadre){
    nodoArbol* nodo = new nodoArbol(termino, nodoPadre, nodoPadre->nivel+1);
    if (tronco == nullptr) //nunca deberia cumplirse esta condicion por el cosntructor de Arbol
    {
        tronco = nodo;
        return nodo;
    }
    //si no tiene hijos, apunta atu nuevo hijo
    if (nodoPadre->primogenito == nullptr)
    {
        nodoPadre->primogenito = nodo;
        return nodo;
    }

    nodoArbol *aux = nodoPadre->primogenito;
    while (aux->hermanoMenor != nullptr)
    {
        aux = aux->hermanoMenor;
    }
    aux->hermanoMenor = nodo;

    return nodo;
}
Arbol::Arbol(std::string operando)
{
    nodoArbol* nodo = new nodoArbol(operando, nullptr, 0);
    tronco = nodo;
    return;
}
nodoArbol* Arbol::getTronco()
{
    return tronco;
}
void Arbol::imprimirRama(nodoArbol*nodo)
{
    std::cout << "Nodo termino: " << nodo->termino << std::endl; 
    if (nodo == tronco)
        std::cout << "este es el nodo tronco" << std::endl;
    else
        std::cout<<" con padre: " << nodo->padre->termino;
    std::cout << " nivel: " << nodo->nivel << std::endl; 
    if (nodo->hermanoMenor == nullptr)
        std::cout << "Sin hermanos mas pequenos" << std::endl;
    else
        std::cout<<" y hermano menor " << nodo->hermanoMenor->termino << std::endl;;
    std::cout << "_______________________________________________" << std::endl;
    nodoArbol* aux = nodo->primogenito;
    while (aux != nullptr)
    {
        imprimirRama(aux);
        aux = aux->hermanoMenor;
    }
    return;
}