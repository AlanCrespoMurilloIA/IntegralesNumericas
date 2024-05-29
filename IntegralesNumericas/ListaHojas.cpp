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
		return;
	}
	nodoListaHojas *aux = heap;
	while (aux->next != nullptr)
	{
		aux = aux->next;
	}
	aux->next = nodito;
	return;
}
void ListaHojas::remove(nodoArbol* nodo)
{
	if (isEmpty())
		return;
	nodoListaHojas* aux = heap;
	if (heap->nodo == nodo)
	{
		heap = heap->next;
		free(aux);
		return;
	}
	while (aux->next->nodo != nodo)
	{
		aux = aux->next;
		if (aux == nullptr)
		{
			std::cout << "WARNING... ListaHojas::remove(nodo), nodo ingresado no existe en la lista..." << std::endl;
			return;
		}
	}
	nodoListaHojas* temp = aux->next;
	aux->next = aux->next->next;
	free(temp);
	return;
}
void ListaHojas::remove(int index)
{
	if (isEmpty())
		return;
	nodoListaHojas* aux = heap;
	if (index == 0)
	{
		heap = heap->next;
		free(aux);
		return;
	}
	if (index >= cantNodosHojas)
		return;
	for (int i = 0; i < index-1; i++)
	{
		aux = aux->next;
	}
	nodoListaHojas* temp = aux->next;
	aux->next = aux->next->next;
	free(temp);
	return;
}
nodoArbol* ListaHojas::get(int nivel)
{
	if (isEmpty())
		return nullptr;
	nodoListaHojas* aux=heap;
	while (aux->nodo->nivel != nivel)
	{
		aux = aux->next;
		if (aux == nullptr)
			return nullptr;
	}
	return aux->nodo;
}