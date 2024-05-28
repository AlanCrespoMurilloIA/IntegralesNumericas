#pragma once
#include "Operaciones.h"
#include <iostream>

/*Calcula la altura. FALTA PONER FUNCIÓN*/
double calcularAltura(int punto)
{
	//return evaluarFuncion(punto);
	return 0;
}

/*Calcula area mediante Rectangulo. lado indica de cual lado se calculará la altura del rectangulo. lado pertenece a {'d','i','m'}*/
double metodoRectangulo(int cotaInf, int cotaSup, int numIntervalos, char lado)
{
	int diferencial = calcularIntervalo(cotaInf, cotaSup, numIntervalos);
	int punto;
	double solucion=0;
	for (int i = 0; i < numIntervalos; i++)
	{
		switch (lado) 
		{
			case 'i':
			{
				punto = cotaInf + diferencial * i;
				break;
			}
			case 'd':
			{
				punto = cotaInf + diferencial * (i+1);
				break;
			}
			case 'm':
			{
				int aux = (cotaInf + diferencial * i + cotaInf + diferencial * (i + 1));
				punto = division(aux, 2);
				break;
			}
		
			default:
			{
				std::cout << "ERROR... calcularIntervalo(), Rectangulo.h. Valor no reconocido";
				return -31415;
			}
		}
		solucion+=calcularAltura(punto);	
	}
	return solucion;
}
