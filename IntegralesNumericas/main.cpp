
#include <string>
//#include "trapecio.h"
#include "Operaciones.h"

struct Integral
{
	int intervaloA;
	int intervaloB;
	int cantIntervalos = 1;
	//Pila funcion;
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
	do{
        std::cout << "----------------------------------" << std::endl;
        std::cout << "|                                |" << std::endl;
        std::cout << "|      Integrales Numericas      |" << std::endl;
        std::cout << "|                                |" << std::endl;
        std::cout << "|   1.- Ingresar una funcion     |" << std::endl;
        std::cout << "|   2.- Resolver Trapecio        |" << std::endl;
        std::cout << "|   3.- Resolver Ronberg         |" << std::endl;
        std::cout << "|   4.- Resolver Simpson         |" << std::endl;
        std::cout << "|   5.- Salir                    |" << std::endl;
        std::cout << "|                                |" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Inserte la opcion deseada: ";
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
