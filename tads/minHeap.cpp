#pragma once
#include "HeapBinario.cpp"

template <class T> class minHeap: public HeapBinario<T>{
private:
    T *arr;
    long largo;
    long costo;
    long ultPos;

    void swap(long posHijo, long posPadre){
        T aux = this->arr[posPadre];
        this->arr[posPadre]=this->arr[posHijo];
        this->arr[posHijo]=aux;
    }
    void flotar(long posHijo, long posPadre){
        T padre = this->arr[posPadre];
        T hijo = this->arr[posHijo];
        if(padre<=hijo)return;
        swap(posHijo,posPadre);
        flotar(posPadre, posPadre/2);
    }
    void hundir(long posActual){
        T hijo = this->arr[posActual];
        if()return;
        swap(posActual,posPadre);
        long posHijoIzq = 2*posActual;
        long posHijoDer = 2*posActual + 1;
        if(posHijoIzq<=this->largo){
            if(posHijoDer<=this->largo){
                if(this->arr[posHijoIzq]<=this->arr[posHijoDer]){
                    hundir(posHijoIzq);
                }else{
                    hundir(posHijoDer);
                }
            }else{
                hundir(posHijoIzq);
            }
        }else{
            if(posHijoDer<=this->largo){
                hundir(posHijoDer);
            }
        }
        
    }
public:
    minHeap(long largo, long costo){
        this->arr= arr[largo+1];
        this->costo = costo;
        this->ultPos=0;
    }

    //insertamos al final y flotamos
    virtual void push(T elem)override{
        arr[this->ultPos+1]=elem;
        this->ultPos++;
        long posPadre = pos/2;//parte entera
        flotar(ultPos,posPadre);
    }

    virtual T top()override{
        return this->arr[1];
    }
    virtual T pop() override{
        swap(1,this->ultPos);
        hundir()
    };
    virtual int size() override{

    }
    virtual bool isEmpty() override{

    }
}