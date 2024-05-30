#pragma once
#include <iostream>
#include <string>
#include <cmath>

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