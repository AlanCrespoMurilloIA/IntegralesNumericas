
#include <string> 
//#include "trapecio.h"
#include "Pila.h"

struct Integral
{
	int intervaloA;
	int intervaloB;
	int cantIntervalos = 1;
	Pila funcion;
	float* areas = nullptr;
};
//HOLA
//Como estas
// bien y tú?
void insertarFuncion(Integral integral)
{
	std::string funcion;
	std::cout << "Escriba su funcion. Use '()' donde sea necesario:" << std::endl;
	std::getline(std::cin, funcion);
	int tamano = funcion.length();
	for (int i = 0; i < tamano; i++)
	{
		return;
	}
	return;
};
int main()
{
	int opc;
	Integral integral;
	do
	{
		std::cout << "SOLVER INTEGRALES NÚMERICAS\nEliga una opción\n1) Ingrese una función\nResolver mediante:";
		std::cout << "2) Trapecio\n3) Ronberg\n4) Simpson\n5) Salir" << std::endl;
		std::cin >> opc;

		switch (opc)
		{
		case 1:
		{
			insertarFuncion(integral);
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			std::cout << "Saliendo...";
			break;
		}
		default:
		{
			std::cout << "Ingrese un valor válido" << std::endl;
			break;
		}

		}
	} while (opc != 5);
	return 0;
}
