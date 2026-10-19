#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/minHeap.cpp"

using namespace std;

long consolidar(HeapBinario<long>* h){
    long costo = 0;
    if(h->size()==1)return costo;
    while(h->size()!=1){
        long primero = h->top();
        h->pop();
        long segundo = h->top();
        h->pop();
        h->push(primero+segundo);
        costo+=primero+segundo;
        
    }
    return costo;
    
}
int main()
{
    long cant;
    std::cin>>cant;
    cin.ignore();
    HeapBinario<long>* h = new minHeap<long>(cant);
    for(int i=1; i<=cant;i++){
        long nro;
        std::cin>>nro;
        h->push(nro);
    }
    //h->consolidar();
    long costo = consolidar(h);
    std::cout<<costo<<std::endl;
    return 0;
}
