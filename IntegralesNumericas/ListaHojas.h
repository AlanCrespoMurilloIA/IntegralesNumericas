#pragma once
#include <iostream>
#include "nodoListaHojas.h"

class ListaHojas {
private:
	nodoListaHojas* heap=nullptr;
public:
	bool isEmpty();
	void insertNodo(nodoArbol* nodo);
	void remove(nodoArbol*nodo);
	void remove(int index);
	nodoArbol* get(int nivel);
};