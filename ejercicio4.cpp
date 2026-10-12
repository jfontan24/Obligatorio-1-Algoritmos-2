#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdint>
#include "tads/list_graph.cpp"
#include "tads/minHeap.cpp"
#include "tads/modulo.cpp"

using namespace std;

int main()
{
    int64_t cantModulos, cantPreced;
    std::cin>>cantModulos>>cantPreced; //cin no lleva endl
    Grafo* g = new list_graph(cantModulos, true);
    int64_t* arrPrioridad = new int64_t[cantModulos+1];
    std::string nro;
    for(int64_t i=1; i<=cantModulos+1; i++){
        std::cin>>nro;
        arrPrioridad[i]= std::stoll(nro);
        //std::cadena;
        //std::getLine(std::cin,cadena);
        cin.ignore();
        
    }
    HeapBinario<modulo>* h = new minHeap<modulo>();
    for(int64_t i; i<=cantPreced; i++){
        std::string v;
        std::string w;
        std::cin>>v>>w;
        int64_t origen = stoll(v);
        int64_t destino = stoll(w);
        g->addEdge(origen,destino);

    }
    return 0;
}