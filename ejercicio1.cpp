#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "avl.cpp"
#include "bst.cpp"

//using namespace std; no tendriamos que sacarlo??

int main()
{
    bst<int>* arbolMoneda = new avl<int>();
    bst<std::string>* arbolPintura = new avl<std::string>();
    int cant;
    std::cin>>cant;
    std::cin.ignore();
    for(int i=1; i<=cant; i++){
        std::string linea;
        std::getline(std::cin,linea);
        size_t inicio = 0;
        size_t fin = linea.find(' ');
        std::string operacion = linea.substr(inicio, fin);
        std::string tipo = linea.substr(fin+1, 1);
        
        if(operacion=="ALTA"){
            if(tipo=="M"){
                int codigo = std::stoi(linea.substr(fin+3));
                arbolMoneda->add(codigo);
            }else{
                std::string titulo= linea.substr(fin+3);
                arbolPintura->add(titulo);
            }                
        }else if(operacion=="BUSCAR"){
            bool encontre;
            if(tipo=="M"){
                int codigo = std::stoi(linea.substr(fin+3));
                encontre = arbolMoneda->search(codigo);
            }else{
                std::string titulo= linea.substr(fin+3);
                encontre = arbolPintura->search(titulo);
            }
            if(encontre){
                std::cout<< "si" << std::endl;
            }else{
                std::cout<< "no" << std::endl;
            }
        }else{

            
            if(tipo=="M"){
                size_t fin2 = linea.find(" ",fin+4);
                int desde = std::stoi(linea.substr(fin+3,fin2-1));
                int hasta = std::stoi(linea.substr(fin2+1));
                arbolMoneda->range(desde,hasta);
            }else{
                size_t fin2 = linea.find(" ",fin+4);
                std::string desde = linea.substr(fin+3,fin2-1);
                std::string hasta = linea.substr(fin2+1);
                arbolPintura->range(desde,hasta);
            }
        }

    }
    return 0;
}
