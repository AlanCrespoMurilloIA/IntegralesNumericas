#pragma once
#include <iostream>
#include "nodoListaHojas.h"

class ListaHojas {
private:
	nodoListaHojas* heap=nullptr;
public:
	bool isEmpty();
	void insertNodo(nodoArbol* nodo);
};