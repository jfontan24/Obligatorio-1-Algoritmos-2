#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Tabla.cpp"
#include "tads/hash_abierto.cpp"
#include "funciones/hashFunc.cpp"
#include "funciones/stringHash.cpp"
using namespace std;

int main()
{   
    long cant;
    std::cin>>cant;
    std::cin.ignore();
    Tabla<long,std::string>* t = new openedHashTable<long,std::string>(cant,new stringHash());
    for(long i=0; i<cant; i++){
        std::string pal;
        std::getline(std::cin,pal);
        t->set(pal);
    }
    long cantConsultas;
    std::cin>>cantConsultas;
    std::cin.ignore();
    for(long i=0; i<cantConsultas; i++){
        std::string consulta;
        std::getline(std::cin,consulta);
        long cantRespuestas = t->get(consulta);
        std::cout<<cantRespuestas<<std::endl;
    }
    std::string cadena = std::to_string(t->size());
    long max = t->getMax();
    cadena+= " "+std::to_string(max);
    std::cout<<cadena<<std::endl;
    return 0;
}