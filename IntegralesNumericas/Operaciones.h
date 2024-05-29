#pragma once
#include <iostream>


int modulo(int a, int b)
{
	int r, q = 0;
	if (a == 0)
	{
		r = 0;
		return r;
	};
	if (a < 0)
	{
		r = -a;
		while (r >= b)
		{
			q--;
			r = r - b;
		}
		return r;
	}
	else
	{
		r = a;
		while (r >= b)
		{
			r = r - b;
			q = q + 1;
		}
		return r;
	}
}
/*Entrega el coeficiente de una division (a/b). No funciona si b es negativo o a y b son negativos */
int division(int a, int b)
{
	int r, q = 0;
	if (a == 0)
		return 0;
	if (a < 0)
	{
		r = -a;
		while (r >= b)
		{
			q--;
			r = r - b;
		}
		return q;
	}
	else
	{
		r = a;
		while (r >= b)
		{
			r = r - b;
			q = q + 1;
		}
		return q;
	}

}
/*Recibe cota superior (A), cota inf (B), cant intervalos*/
int calcularIntervalo(int b, int a, int numIntervalos)
{
	return division(a - b, numIntervalos);
}
/*Evalua funcion. FALTA PONER FUNCION*/
double evaluarFuncion(int punto)
{
	int solucion=0;
	return solucion;
}
