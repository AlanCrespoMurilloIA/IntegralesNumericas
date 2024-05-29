#include "ListaHojas.h"

bool ListaHojas::isEmpty()
{
	if (heap == nullptr)
		return true;
	return false;
}
void ListaHojas::insertNodo(nodoArbol* nodo)
{
	nodoListaHojas* nodito = new nodoListaHojas;
	nodito->nodo = nodo;
	if (heap==nullptr)
	{
		heap = nodito;
	}
	nodoListaHojas *aux = heap;
	while (aux->next != nullptr)
	{
		aux = aux->next;
	}
	aux->next = nodito;
	return;
}