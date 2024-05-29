#pragma once
#include <iostream>
#include "nodoListaHojas.h"

class ListaHojas {
private:
	nodoListaHojas* heap=nullptr;
public:
	int cantNodosHojas = 0;
	bool isEmpty();
	void insertNodo(nodoArbol* nodo);
	void remove(nodoArbol*nodo);
	void remove(int index);
	nodoArbol* get(int nivel);
};