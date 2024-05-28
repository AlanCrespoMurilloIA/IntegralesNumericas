#pragma once
#include "Nodo.h"

class Pila
{
private:
	Nodo* heap=nullptr;

public:
		int evaluarPunto(int coordX, int coordY);
		void push(char caracter);
		char pop();
		int tamanoPila();
		char top();





};

