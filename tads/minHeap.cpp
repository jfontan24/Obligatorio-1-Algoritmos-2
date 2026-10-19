#pragma once
#include "HeapBinario.cpp"

template <class T> class minHeap: public HeapBinario<T>{
private:
    T *arr;
    long largo;
    long ultPos;

    void swap(long posHijo, long posPadre){
        T aux = this->arr[posPadre];
        this->arr[posPadre]=this->arr[posHijo];
        this->arr[posHijo]=aux;
    }
    void flotar(long posActual){
        if(posActual <= 1)return;
        T padre = this->arr[posActual/2];
        T hijo = this->arr[posActual];
        if(padre<=hijo)return;
        swap(posActual,posActual/2);
        posActual=posActual/2;
        flotar(posActual);
    }
    void hundir(long posActual){
        T hijo = this->arr[posActual];
        long posHijoIzq = 2*posActual;
        long posHijoDer = 2*posActual + 1;
        if(posHijoIzq<=this->ultPos){
            if(posHijoDer<=this->ultPos){
                if(this->arr[posActual]<=this->arr[posHijoIzq]&&this->arr[posActual]<=this->arr[posHijoDer])return;
                if(this->arr[posHijoIzq]<=this->arr[posHijoDer]){
                    swap(posActual, posHijoIzq);
                    hundir(posHijoIzq);
                }else{
                    swap(posActual, posHijoDer);
                    hundir(posHijoDer);
                }
            }else{
                
                if(this->arr[posActual]<=this->arr[posHijoIzq])return;
                swap(posActual, posHijoIzq);
                hundir(posHijoIzq);
            }
        }else{
            if(posHijoDer<=this->ultPos){
                if(this->arr[posActual]<=this->arr[posHijoDer])return;
                swap(posActual, posHijoDer);
                hundir(posHijoDer);
            }else{
                return;
            }
        }
        
    }
public:
    minHeap(long largo){
        this->arr= new T[largo+1];
        this->ultPos=0;
        this->largo = largo;
    }

    //insertamos al final y flotamos
    virtual void push(T elem)override{
        if(this->ultPos >= this->largo)return;
        arr[this->ultPos+1]=elem;
        this->ultPos++;
        flotar(ultPos);
    }

    virtual T top()override{
        return this->arr[1];
    }
    virtual void pop() override{
        if(isEmpty())return;
        swap(1,this->ultPos);
        //this->arr[this->ultPos]=-1;//lo borramos
        this->ultPos--;

        hundir(1);
        
    };


    
    virtual long size() override{
        return this->ultPos;
    }
    virtual bool isEmpty() override{
        return size()==0;
    }
    /*virtual long getCosto()override{
        return this->costo;
    }*/
   
};