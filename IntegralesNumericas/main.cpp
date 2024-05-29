//#include <iostream>
#include <string>
#include <sstream>
#include "Operaciones.h"
#include "arbol.h"

struct Integral
{
	int intervaloA;
	int intervaloB;
	int cantIntervalos = 1;
	Arbol *funcion;
	float* areas;
    //Integral() : intervaloA(0), intervaloB(0), cantIntervalos(1), areas(nullptr) {}

};

std::string operandos[4] = {"+", "-", "*", "/"};
std::string operadores[9] = {"sin", "cos", "tan", "csc", "sec", "cot", "ln", "abs", "exp"};


void Error(std::string text){
    std::cout << std::endl;
    if (text == "")
        std::cout << "Intente otra vez...\n";
    else
        std::cout << text << ". Intente otra vez...\n";
    std::cout << std::endl;
}

int intChecker(){
    int x; // Declaraci—n de la variable x para almacenar el nœmero entero ingresado
    while (true) // Bucle infinito para repetir la solicitud de entrada hasta que se ingrese un nœmero entero positivo v‡lido
    {
        std::string u; // Declaraci—n de la variable u para almacenar la entrada del usuario
        std::cin >> u; // Solicitar la entrada del usuario y almacenarla en u
        try // Bloque try-catch para manejar excepciones
        {
            std::stringstream stream(u); // Crear un objeto stringstream para analizar la entrada
            char test; // Variable para almacenar un car‡cter adicional
            if ((!(stream >> x)) || (stream >> test)) // Verificar si la entrada se puede convertir a un nœmero entero y si no hay caracteres adicionales
            {
                throw std::runtime_error("Failed"); // Lanzar una excepci—n si la conversi—n falla o si hay caracteres adicionales
            }
            if (x >= 0) // Verificar si el nœmero entero es cero o positivo
            {
                return x; // Devolver el nœmero entero positivo
            }
            else
            {
                Error("Ponga un nœmero entero positivo"); // Imprimir un mensaje de error si el nœmero entero no es positivo
            }
        }
        catch(...) // Manejar cualquier tipo de excepci—n
        {
            Error("Ponga un nœmero entero"); // Imprimir un mensaje de error general
        }
    }
}

bool esNum(const std::string& str) {
    if (str.empty())
        return false;

    for (char const &ch : str)
        if (!std::isdigit(ch)) {
            return false;  //Si algun valor del string es distinto de 1, 2, ..., 9, no es num
                           //Asi tambien evitamos numeros negativos
        }
    return true;  // El valor es un numero
}
bool esOperando(const std::string& op){
    for(const auto& operando : operandos)
        if(op == operando)
            return true;
    return false;
}
bool esOperador(const std::string& op){
    for(const auto& operador : operadores)
        if(op == operador)
            return true;
    return false;
}
/*Categoriza un termino*/
int categorizadorTerminos(std::string termino)
{
    int tipo = 0;
    //Tipo 1 = x o numeros
    //Tipo 2 = operandos (+, -, *, /)
    //TIpo 3 = operadores (sin, cos, etc)
    //Tipo 4 = exponencial
    if (termino == "x" || termino == "pi" || termino == "e" || esNum(termino))
        tipo = 1;
    if (esOperando(termino))
        tipo = 2;
    if (esOperador(termino))
        tipo = 3;
    if (tipo == 0)
        Error("La funcion insertada no pertenece a los diccionarios");
    return tipo;
}
void crearRama(nodoArbol* nodo)
{
    std::cout << "Ingresa el termino hijo del nodo con el termino" << nodo->termino << std::endl;
    return;
}
void insertarFuncion(Integral *integral){
    std::string operacion;
    int tipo = 0,cantTerminos=0;
        //Tipo 1 = x o numeros
        //Tipo 2 = operandos (+, -, *, /)
        //TIpo 3 = operadores (sin, cos, etc)
        //Tipo 4 = exponencial

    do{
        std::cout << "Inserte la operacion principal de la funcion: ";
        std::cin >> operacion;
        tipo = categorizadorTerminos(operacion);
    } while(tipo == 0);

    std::cout << "Tipo: " << tipo << " | Operacion: " << operacion << std::endl;
    //creamos el objeto Arbol dentro de la estructura Integral
    integral->funcion = new Arbol(operacion);
    //Si se inserto un termino tipo 1, no se puede crear más ramas
    if (tipo == 1)
        return;
    else if (operacion == "/")
    {
        //La division solo puede tener dos ramas
        for (int i = 0; i < 2; i++)
        {
            crearRama(integral->funcion->getTronco());
        }
    }
    else
    {
        //Todos los demas pueden tener 'n' ramas
        std::cout << "Ingrese la cantidad de terminos en este nivel" << std::endl;
        std::cin >> cantTerminos;
        for (int i = 0; i < cantTerminos; i++)
        {
            crearRama(integral->funcion->getTronco());
        }
    }
    




}


int main()
{
    Integral integral;
	int opc;
	do{
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
            opc = intChecker();
            if(opc < 1 || opc > 5)
                Error("Esa operaci—n no existe");
        } while(opc < 1 || opc > 5);
        switch (opc){
            case 1:
                insertarFuncion(&integral);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                std::cout << "Hasta luego!";
                break;
        }
	} while (opc != 5);
	return 0;
}
