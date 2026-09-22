#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/minHeap.cpp"

using namespace std;

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
    h->imprimir();
    h->consolidar();
    std::cout<<h->getCosto()<<std::endl;
    return 0;
}