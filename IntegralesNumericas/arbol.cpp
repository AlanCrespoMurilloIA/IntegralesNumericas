#include "arbol.h"

Arbol::Arbol(std::string operando, int numHijos){
    nodoArbol* nodo = new nodoArbol(operando, nullptr, 0, numHijos);
    tronco = nodo;
    return;
}

nodoArbol* Arbol::insert(std::string termino, nodoArbol * padre, int hijos){
    nodoArbol* nodo = new nodoArbol(termino, padre, (padre->nivel + 1), hijos);
    if (tronco == nullptr){
        tronco = nodo;
        return nodo;
    }
    //Si no tiene hijos, apunta a su nuevo hijos
    if(padre->primogenito == nullptr){
        padre->primogenito = nodo;
        padre->contHijos++;
        return nodo;
    }
    nodoArbol* aux = padre->primogenito;
    if(padre->contHijos < padre->numHijos){
        aux->hermanoMenor = nodo;
        padre->contHijos++;
    }
    return nodo;
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
    while (aux != nullptr){
        imprimirRama(aux);
        aux = aux->hermanoMenor;
    }
    return;
}
