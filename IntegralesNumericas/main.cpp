//#include <iostream>
#include <string>
#include <sstream>
#include "Operaciones.h"
#include "arbol.h"
#include "ListaHojas.h"

struct Integral
{
	int intervaloA;
	int intervaloB;
	int cantIntervalos = 1;
	Arbol *funcion;
	float* areas;
    //Integral() : intervaloA(0), intervaloB(0), cantIntervalos(1), areas(nullptr) {}
    ListaHojas listahojas;
    ListaHojas listahojasCoeficientes;
};

std::string operandos[5] = {"+", "-", "*", "/", "exp"};
std::string operadores[8] = {"sin", "cos", "tan", "csc", "sec", "cot", "ln", "abs"};


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
        if (std::isdigit(ch) || ch == '.') {
            return true;  //solo se aceptan los dijitos 0 - 9 y el punto '.'
                           //Asi tambien evitamos numeros negativos
        }
    return false;  // El valor no es un numero
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
int categorizadorTerminos(std::string termino){
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

void crearRama(nodoArbol* padre, Integral * integral){
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
    nodoArbol* nodo=nullptr;
    if (tipo == 1){
        //Creando el nodo padre del arbol
        nodo = integral->funcion->insert(termino, padre, hijos);
        if (termino == "x")
        {
            integral->listahojas.insertNodo(nodo);
        }
        else
        {
            integral->listahojasCoeficientes.insertNodo(nodo);
        }
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
        if (operacion == "x")
        {
            integral->listahojas.insertNodo(integral->funcion->getTronco());
        }
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

/*Metodo para probar la evaluacion de un punto*/
void evaluarPunto(Integral *integral, int punto)
{
    int nivelActual=integral->listahojasCoeficientes.nivelMasGrande();
    //Este while es para sustituir 'x' con el punto
    nodoArbol* aux = integral->listahojas.get();
    while (aux != nullptr)
    {
        //Como 'x' va a ser sustituida por un punto, ese nodo ahora tendra un coeficiente
        //por lo que entra en la categoria de listahojasCoeficientes
        integral->listahojasCoeficientes.insertNodo(aux);
        integral->listahojas.remove(aux);
        if (aux->termino != "x")
        {
            std::cout << "ERROR... evaluarPunto(), se encontro un nodo no hoja en listaHojas" << std::endl;
            return;
        }
        aux->valAux = punto;
        aux = integral->listahojas.get();
    }

    while (nivelActual >= 0)
    {
        aux = integral->listahojasCoeficientes.get(nivelActual);
        if (aux == nullptr)
        {
            nivelActual--;
            continue;
        }
        //esto significa que ya hemos llegado al tronco
        if (aux->padre == nullptr)
            break;
        //falta obtener val con Operaciones.h
        //int val = aux->valAux+2;
        //int auxDouble1, auxDouble2;
        //int val = transformacion();
        if (aux->hermanoMenor == nullptr)
        {
            //asigna el valor al aux->valAux
            if (aux->termino != "x" && aux->termino != "pi" && aux->termino != "e")
                aux->valAux = std::stod(aux->termino);
            if (aux->padre->primogenito->termino != "x" && aux->padre->primogenito->termino != "pi" && aux->padre->primogenito->termino != "e")
                aux->padre->primogenito->valAux=std::stod(aux->padre->primogenito->termino);
            //asigna el valor al padre
            aux->padre->valAux = transformacion(aux->padre->primogenito->valAux, aux->valAux, aux->padre->termino);
            integral->listahojasCoeficientes.remove(aux->padre->primogenito);
        }
        else
        {
            if (aux->termino != "x" && aux->termino != "pi" && aux->termino != "e")
                aux->valAux = std::stod(aux->termino);
            if (aux->hermanoMenor->termino != "x" && aux->hermanoMenor->termino != "pi" && aux->hermanoMenor->termino != "e")
                aux->hermanoMenor->valAux = std::stod(aux->hermanoMenor->termino);
            aux->padre->valAux = transformacion(aux->valAux, aux->hermanoMenor->valAux, aux->padre->termino);
            integral->listahojasCoeficientes.remove(aux->hermanoMenor);
        }
        //ahora padre tiene un coeficiente por lo que entra en la categoria hojaCoeficientes
        if (aux->padre != nullptr)
        {
            integral->listahojasCoeficientes.insertNodo(aux->padre);
        }
        integral->listahojasCoeficientes.remove(aux);
    }
    std::cout << "La funcion evaluada en el punto es: " << aux->valAux;
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
            std::cout << "|  1.- Ingresar una funcion      |" << std::endl;
            std::cout << "|  2.- Evaluar un punto          |" << std::endl;
            std::cout << "|  3.- Resolver Trapecio         |" << std::endl;
            std::cout << "|  4.- Resolver Ronberg          |" << std::endl;
            std::cout << "|  5.- Resolver Simpson          |" << std::endl;
            std::cout << "|  6.- Salir                     |" << std::endl;
            std::cout << "|                                |" << std::endl;
            std::cout << "----------------------------------" << std::endl;
            std::cout << "Inserte la opcion deseada: ";
            opc = intChecker();
            if(opc < 1 || opc > 6)
                Error("Esa opcion no esta disponible");
        } while(opc < 1 || opc > 6);
        switch (opc){
            case 1:
                insertarFuncion(&integral);
                break;
            case 2:
                double punto;
                std::cout << "Ingrese un punto" << std::endl;
                std::cin >> punto;
                evaluarPunto(&integral,punto);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                std::cout << "Hasta luego!" << std::endl;
                break;
        }
	} while (opc != 5);
    //std::cout << transformacion("0", "3", "cos") << std::endl;
    
	return 0;
}
