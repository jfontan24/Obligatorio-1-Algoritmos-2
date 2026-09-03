#pragma once
#include "avl.cpp"
#include "funciones.cpp"
#include <iostream>

class funcionesMoneda: public funciones<int>{
public:
    virtual void alta(int codigo, bst arbol) override{
        arbol->add(codigo);
    }; 
    virtual void rango(int desde, int hasta) override{
        arbol->range(desde,hasta);
    };
    virtual void buscar(int codigo) override{
        bool encontre = arbol->search(codigo);
        if(encontre){
            std::cout<< "si" << endl;
        }else{
            std::cout<< "no" << endl;
        }

    };
}
  