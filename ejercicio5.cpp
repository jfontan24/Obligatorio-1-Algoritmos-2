#include <cassert>
#include <cstdint>
#include <string>
#include <iostream>
#include <limits>
#include <stdint.h>
#include "tads/HeapBinario.cpp"
#include "tads/iterator.cpp"
#include "tads/list_graph.cpp"
#include "tads/minHeap.cpp"
#include "tads/MFSet.cpp"
#include "tads/iterator.cpp"
#include "tads/Pila.cpp"

int64_t kruskal(int64_t V,  HeapBinario<edge>* heap){
    int64_t costo = 0;
    MFSet* mfset = new MFSet(V);
    int64_t aristasAceptadas = 0;
    while(!heap->isEmpty() && aristasAceptadas<V-1){
        edge e = heap->top();
        heap->pop();
        if(mfset->find(e.from) != mfset->find(e.to)){
            mfset->merge(e.from, e.to);
            aristasAceptadas++;
            costo+=e.weight;
        }
    }
    return costo;
}

void DFS(Grafo* g, bool* &visitados, int64_t origen){
    Pila* p = new Pila();
    p->push(origen);
    visitados[origen] = true;
    while(!p->esVacia()){
        int64_t v = p->top();
        p->pop();
        iterator<edge>* it = g->getNeighbours(v);
        while(it->hasNext()){
            edge e = it->next();
            if(!visitados[e.to]){
                visitados[e.to] = true;
                p->push(e.to);
            }
        }  
    }
      
}


bool esConexa(Grafo* g){
    bool* vistados = new bool[g->cantVertices()+1];
    for (int i = 1; i<=g->cantVertices(); i++) {
        vistados[i] = false;
    }
    DFS(g, vistados, 1);
    bool esConexa = true;
    for (int i = 1; i<=g->cantVertices() && esConexa; i++) {
        esConexa = esConexa && vistados[i];
    }
    return esConexa;
}

int main()
{
    int64_t cantRefugios;
    int64_t cantSenderos;
    std::cin>>cantRefugios>>cantSenderos;
    if(cantRefugios == 1 && cantSenderos == 0){
        std::cout<<0<<std::endl;
        return 0;
    }
    HeapBinario<edge>* heap = new minHeap<edge>(cantSenderos+1);
    Grafo* g = new list_graph(cantRefugios, false);
    for(int64_t i = 1; i<=cantSenderos; i++){
        int64_t v;
        int64_t w;
        int64_t peso;
        std::cin>>v>>w>>peso;
        edge e = edge(v,w,peso);
        heap->push(e);
        g->addWeightEdge(v, w, peso);
    }
    bool conexa = esConexa(g);
    if(!conexa){
        std::cout<<"imposible"<<std::endl;
    } else {
        int64_t costo = kruskal(cantRefugios, heap);
        std::cout<<costo<<std::endl;
    }
    return 0;
}




