#include <cassert>
#include <iterator>
#include <string>
#include <iostream>
#include <limits>
#include <cstdint>
#include "tads/Grafo.cpp"
#include "tads/list_graph.cpp"
#include "tads/minHeap.cpp"
#include "tads/modulo.cpp"
#include "tads/iterator.cpp"


int64_t* initRet(int64_t cantModulos){
    int64_t* ret = new int64_t[cantModulos+1];
    for(int64_t i=0; i<=cantModulos; i++){
        ret[i]=0;
    }
    return ret;
}
int64_t* initGradosEntrada(int64_t cantModulos, Grafo* g){
    int64_t* gradosEntrada = new int64_t[cantModulos+1];
    for(int64_t i=1;i<=cantModulos;i++){
        gradosEntrada[i]=0;
    }
    iterator<edge> *it = g->getAllEdges();
    while(it->hasNext()){
        edge e = it->next();
        gradosEntrada[e.to]++;
    }
    return gradosEntrada;
}
int64_t* ordenacionTopologica(Grafo* g, int64_t cantModulos, int64_t* arrPrio){
    HeapBinario<modulo>* h = new minHeap<modulo>(cantModulos);
    int64_t* ret= initRet(cantModulos);
    int64_t* gradosEntrada = initGradosEntrada(cantModulos,g);
    for(int64_t i=1; i<=cantModulos; i++){
        if(gradosEntrada[i]==0){
            modulo m = modulo(i,arrPrio[i]);
            h->push(m);
        }
    }
    int64_t cant = 0;
    int64_t pos = 1;
    while(!h->isEmpty()){
        modulo m = h->top();
        cant++;
        int64_t vert = m.nroVertice;
        ret[pos]=vert;
        pos++;
        h->pop();
        iterator<edge>* it = g->getNeighbours(m.nroVertice);
        while(it->hasNext()){
            edge e = it->next();
            gradosEntrada[e.to]--;
            if(gradosEntrada[e.to]==0){
                modulo mod = modulo(e.to,arrPrio[e.to]);
                h->push(mod);
                
            }
        }
    }
    if(cant<cantModulos){
        ret[0]=-1;//le ponemos -1 en la pos 0, y chequeamos que si pasa esto es xq hay ciclo
    }
    return ret;
}
int main()
{
    int64_t cantModulos, cantPreced;
    std::cin>>cantModulos>>cantPreced; //cin no lleva endl
    Grafo* g = new list_graph(cantModulos, true);
    int64_t* arrPrioridad = new int64_t[cantModulos+1];
    std::string nro;
    for(int64_t i=1; i<=cantModulos; i++){
        std::cin>>nro;
        arrPrioridad[i]= std::stoll(nro);
        std::cin.ignore();
        
    }
    for(int64_t i=0; i<cantPreced; i++){
        int64_t v;
        int64_t w;
        std::cin>>v>>w;
        g->addEdge(v,w);
    }
    
    int64_t* orden = ordenacionTopologica(g, cantModulos, arrPrioridad);
    if(orden[0]==-1){
        std::cout<<"imposible"<<std::endl;
    }else{
        for(int64_t i=1; i<=cantModulos; i++){
            std::cout<<orden[i]<<std::endl;
        }
    }
    return 0;
}