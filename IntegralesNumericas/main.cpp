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

double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208;
double e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547;

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
            integral->listahojas.insertNodo(nodo);
        else
            integral->listahojasCoeficientes.insertNodo(nodo);
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
            integral->listahojas.insertNodo(integral->funcion->getTronco());
        else
            integral->listahojasCoeficientes.insertNodo(integral->funcion->getTronco());
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

double evaluarRama(nodoArbol* nodo){
    double resultado = 0, val1 = 0, val2 = 0;
    std::string operacion = nodo->termino;
    
    nodoArbol* primogenito = nodo->primogenito;
    nodoArbol* hermanoMenor = primogenito ? primogenito->hermanoMenor : nullptr;
    
    if (primogenito == nullptr)
        throw std::invalid_argument("El nodo debe tener al menos un primogenito");
    
    if (primogenito->primogenito == nullptr && (hermanoMenor == nullptr || hermanoMenor->primogenito == nullptr)){
        val1 = primogenito->valAux;
        if (hermanoMenor != nullptr)
            val2 = hermanoMenor->valAux;
    } else if (primogenito->primogenito != nullptr && hermanoMenor == nullptr){
        val1 = evaluarRama(primogenito);
    } else if (primogenito->primogenito != nullptr && hermanoMenor != nullptr && hermanoMenor->primogenito != nullptr) {
        val1 = evaluarRama(primogenito);
        val2 = evaluarRama(hermanoMenor);
    } else if (primogenito->primogenito != nullptr && hermanoMenor != nullptr && hermanoMenor->primogenito == nullptr) {
        val1 = evaluarRama(primogenito);
        val2 = hermanoMenor->valAux;
    } else if (primogenito->primogenito == nullptr && hermanoMenor != nullptr && hermanoMenor->primogenito != nullptr) {
        val1 = primogenito->valAux;
        val2 = evaluarRama(hermanoMenor);
    }

    // Esto asume que transformacion(val1, val2, operacion) es una funcion valida que realiza la operacion correcta
    resultado = transformacion(val1, val2, operacion);

    nodo->valAux = resultado;
    return resultado;
}

double f(Integral *integral, double coord){
    double resultado = 0;
    //Transformamos cada elemento de la lista de hojas al punto dado
    nodoListaHojas* aux = integral->listahojas.getHeap();
    if(aux == nullptr){
        Error("Aun no se ha insertado ninguna funcion");
        return 0;
    }
    while(aux != nullptr){
        //Accedemos al nodoArbol al que apunta aux y modificamos el valAux por el valor estudiado
        aux->nodo->valAux = coord;
        aux = aux->next;
    }
    //Llamamos a la funcion evaluar rama empezando en el nodoPadre
    resultado = evaluarRama(integral->funcion->getTronco());
    return resultado;
}

/*Metodo para probar la evaluacion de un punto*/
void evaluarPunto(Integral *integral){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|  Evaluando en un punto         |" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    double resultado = 0, coord = 0;
    std::string punto;
    bool band = false;
    do{
        std::cout << "Deme el punto que desea evaluar: ";
        std::cin >> punto;
        if(esNum(punto)){
            coord = std::stod(punto);
            band = true;
        }
        else if(punto == "pi"){
            coord = pi;
            band = true;
        }
        else if(punto == "e"){
            coord = e;
            band = true;
        }
        if(!band)
            Error("Inserte un numero valido");
    }while(!band);
    std::cout << "f(" << punto << ") = ";
    
    //Transformamos cada elemento de la lista de hojas al punto dado
    nodoListaHojas* aux = integral->listahojas.getHeap();
    if(aux == nullptr){
        Error("Aun no se ha insertado ninguna funcion");
        return;
    }
    while(aux != nullptr){
        //Accedemos al nodoArbol al que apunta aux y modificamos el valAux por el valor estudiado
        aux->nodo->valAux = coord;
        aux = aux->next;
    }
    //Llamamos a la funcion evaluar rama empezando en el nodoPadre
    resultado = evaluarRama(integral->funcion->getTronco());
    std::cout << resultado << std::endl;
}

double str2dou(std::string str){
    double numero = 0;
    if(esNum(str))
        numero = std::stod(str);
    else if(str == "pi")
        numero = pi;
    else if(str == "e")
        numero = e;
    return numero;
}

void Simpson(Integral *integral){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|  Evaluando metodo de Simpson   |" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::string val1, val2;
    double a = 0, b = 0, resultado = 0;
    int n = 0;
    do{
        std::cout << "Inserte el valor inferior del intervalo a estimar: ";
        std::cin >> val1;
        if(!esNum(val1) && val1 != "pi" && val1 != "e")
            Error("Inserte un numero valido");
    }while(!esNum(val1) && val1 != "pi" && val1 != "e");
    a = str2dou(val1);
    do {
        std::cout << "Inserte el valor superior del intervalo a estimar: ";
        std::cin >> val2;
        if(str2dou(val1) >= str2dou(val2))
            Error("El valor superior debe ser mayor al inferior");
    } while (a >= str2dou(val2));
    b = str2dou(val2);
    do {
        std::cout << "Inserte el numero de intervalos: ";
        n = intChecker();
        if(modulo(n, 2) != 0)
            Error("El intervalo debe ser multiplo de dos");
    } while (modulo(n, 2) != 0);
    
    double h, sum = 0;
    double x[n + 1];
    int j;
    h = (b - a)/n;
    x[0] = a;
    for(j = 1; j < (n + 1); j++)
        x[j] = a + (h * j);
    
    for(j = 1; j <= (n/2); j++)
        sum += f(integral, x[2*j - 2]) + 4*f(integral, x[2*j - 1]) + f(integral, x[2*j]);
    
    resultado = sum * (h/3);
    
    std::cout << "La integral evaluada desde el punto " << a << " hasta el punto " << b << " da como resultado un total de: " << resultado << std::endl;
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
        std::cout << std::endl;
        switch (opc){
            case 1:
                insertarFuncion(&integral);
                break;
            case 2:
                evaluarPunto(&integral);
                break;
            case 3:
                Simpson(&integral);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                std::cout << "Hasta luego!" << std::endl;
                break;
        }
    } while (opc != 6);
    return 0;
}
