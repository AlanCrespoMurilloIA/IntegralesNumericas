#pragma once
#include <iostream>
#include <string>
#include <cmath>


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

double transformacion(std::string val1, std::string val2, std::string operacion){
    double resultado = 0;
    //Analizando los principales operandos
    if(operacion == "+")
        return std::stod(val1) + std::stod(val2);
    else if(operacion == "-")
        return std::stod(val1) - std::stod(val2);
    else if(operacion == "*")
        return std::stod(val1) * std::stod(val2);
    else if(operacion == "/"){
        if(std::stod(val2) == 0){
            std::cout << "ERROR transformacion()... division entre cero" << std::endl;
            return 0;
        }
        return std::stod(val1) / std::stod(val2);
    }
    
    //Analizando otras funciones
    if(operacion == "exp")
        return std::pow(std::stod(val1), std::stod(val2));
    else if(operacion == "sin")
        return std::sin(std::stod(val1));
    else if(operacion == "cos")
        return std::cos(std::stod(val1));
    else if(operacion == "tan")
        return std::tan(std::stod(val1));
    else if(operacion == "csc")
        return 1/(std::sin(std::stod(val1)));
    else if(operacion == "sec")
        return 1/(std::cos(std::stod(val1)));
    else if(operacion == "cot")
        return 1/(std::tan(std::stod(val1)));
    else if(operacion == "ln"){
        if(val1 == "0"){
            std::cout << "ERROR transformacion()... ln(0)" << std::endl;
            return 0;
        }
        return std::log(std::stod(val1));
    }
    else if(operacion == "abs")
        return std::abs(std::stod(val1));
    return resultado;
}


double transformacion(double val1, double val2, std::string operacion) {
    double resultado = 0;
    //Analizando los principales operandos
    if (operacion == "+")
        return val1 +val2;
    else if (operacion == "-")
        return val1 - val2;
    else if (operacion == "*")
        return  val1 *  val2;
    else if (operacion == "/") {
        if ( val2 == 0) {
            std::cout << "ERROR transformacion()... division entre cero" << std::endl;
            return 0;
        }
        return  val1 /  val2;
    }

    //Analizando otras funciones
    if (operacion == "exp")
        return std::pow( val1,  val2);
    else if (operacion == "sin")
        return std::sin( val1);
    else if (operacion == "cos")
        return std::cos( val1);
    else if (operacion == "tan")
        return std::tan( val1);
    else if (operacion == "csc")
        return 1 / (std::sin( val1));
    else if (operacion == "sec")
        return 1 / (std::cos( val1));
    else if (operacion == "cot")
        return 1 / (std::tan( val1));
    else if (operacion == "ln") {
        if (val1 == 0) {
            std::cout << "ERROR transformacion()... ln(0)" << std::endl;
            return 0;
        }
        return std::log( val1);
    }
    else if (operacion == "abs")
        return std::abs( val1);
    return resultado;
}