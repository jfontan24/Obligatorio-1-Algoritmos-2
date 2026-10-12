#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/minHeap.cpp"

using namespace std;

void consolidar(HeapBinario<long>* h){
    int primero = h->top();
    h->pop();
    int segundo = h->top();
    h->pop();
    h->push(primero+segundo);
}
int main()
{
    long cant;
    std::cin>>cant;
    cin.ignore();
    HeapBinario<long>* h = new minHeap<long>(cant, 0);
    for(int i=1; i<=cant;i++){
        long nro;
        std::cin>>nro;
        h->push(nro);
    }
    //h->consolidar();
    consolidar(h);
    std::cout<<(h->top())->getCosto()<<std::endl;
    return 0;
}
