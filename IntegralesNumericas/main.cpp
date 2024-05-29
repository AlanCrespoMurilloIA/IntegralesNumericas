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
int indexHijo(nodoArbol* hijo)
{
    nodoArbol* aux = hijo->padre->primogenito;
    int index = 0;
    while (aux != hijo)
    {
        aux = aux->hermanoMenor;
    }
    return index;
}

void crearRama(nodoArbol* padre, Integral * integral)
{
    int tipo = 0, hijos = 0;
    std::string termino;
    std::cout << "\n----------------------------------" << std::endl;
    std::cout << "Insertando datos del hijo " << (padre->contHijos + 1) << " de la funcion " << padre->termino << ": " << std::endl;
    std::cout << "----------------------------------\n" << std::endl;
    do {
        std::cout << "Ingrese el termino principal dentro de " << padre->termino << ". Se encuentra en el nivel " << (padre->nivel + 1) <<": ";
        std::cin >> termino;
        tipo = categorizadorTerminos(termino);
    } while (tipo == 0);
    //Tipo 1 -- 0 ramas
    //Tipo 2 -- 2 ramas
    //TIpo 3 -- 1 rama
    nodoArbol* nodo;
    if (tipo == 1){
        //Creando el nodo padre del arbol
        nodo = integral->funcion->insert(termino, padre, hijos);
        return;
    }
    //Los operandos pueden tener dos ramas
    else if (tipo == 2){
        //Creando el nodo padre del armol
        hijos = 2;
        nodo = integral->funcion->insert(termino, padre, hijos);
    }
    else if (tipo == 3){
        //Creando el nodo padre del armol
        hijos = 1;
        nodo = integral->funcion->insert(termino, padre, hijos);
    }
    for(int i = 0; i < hijos; i++)
        crearRama(nodo, integral);
    return;
}
void insertarFuncion(Integral *integral){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|     Insertando la funcion      |" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::string operacion;
    int tipo = 0, hijos = 0;
        //Tipo 1 = x o numeros
        //Tipo 2 = operandos (+, -, *, /)
        //TIpo 3 = operadores (sin, cos, etc)

    do{
        std::cout << "Inserte la operacion principal de la funcion: ";
        std::cin >> operacion;
        tipo = categorizadorTerminos(operacion);
    } while(tipo == 0);

    std::cout << "Tipo: " << tipo << " | Operacion: " << operacion << std::endl;
   
    //Tipo 1 -- 0 ramas
    //Tipo 2 -- 2 ramas
    //TIpo 3 -- 1 rama
    
    //Si se inserto un termino tipo 1, no se puede crear ramas
    if (tipo == 1){
        //Creando el nodo padre del arbol
        integral->funcion = new Arbol(operacion, hijos);
        return;
    }
    //Los operandos pueden tener dos ramas
    else if (tipo == 2){
        //Creando el nodo padre del arbol
        hijos = 2;
        integral->funcion = new Arbol(operacion, hijos);
    }
    else if (tipo == 3){
        //Creando el nodo padre del arbol
        hijos = 1;
        integral->funcion = new Arbol(operacion, hijos);
    }
    for(int i = 0; i < hijos; i++)
        crearRama(integral->funcion->getTronco(), integral);
    
    integral->funcion->imprimirRama(integral->funcion->getTronco());
}

int main(){
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
                Error("Esa opcion no esta disponible");
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
