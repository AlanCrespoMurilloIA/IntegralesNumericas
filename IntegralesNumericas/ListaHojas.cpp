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
void ListaHojas::remove(nodoArbol* nodo)
{
	return;
}
void ListaHojas::remove(int index)
{
	if (isEmpty())
		return;
	nodoListaHojas* aux = heap;
	if (index == 0)
	{

	}
	for (int i = 0; i < index; i++)
	{

	}
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
	}
	return aux->nodo;
}