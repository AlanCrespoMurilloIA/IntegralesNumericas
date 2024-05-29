#pragma once
#include "nodosLista.h"
class ListaNodos
{
public:
	nodosLista* heap;
	nodosLista* selectNodosByNivel(int nivel);
	void insert(nodoArbol nodo);


};

