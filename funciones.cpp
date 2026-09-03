#pragma once
#include "bst.cpp"
#include "avl.cpp"
#include <iostream>
template <class T>
//duda: esta bien asi o separamos en moneda y pintura?
class funciones{
    public:
        virtual void alta(bst arbol, T codigo){
            arbol->add(codigo);
        }; 
        virtual void rango(bst arbol, T desde, T hasta){
            arbol->range(desde,hasta);
        };
        virtual void buscar(bst arbol, T codigo){
            bool encontre = arbol->search(codigo);
            if(encontre){
                std::cout<< "si" << endl;
            }else{
                std::cout<< "no" << endl;
            }
        };  
}