#pragma once
#include "avl.cpp"
#include <string>
#include "funciones.cpp"

class funcionesMoneda: public funciones<std::string>{
public:
    virtual void alta(std::string codigo) override; 
    virtual void rango(std::string desde, std::string hasta) override;
    virtual void buscar(std::string codigo) override;
}