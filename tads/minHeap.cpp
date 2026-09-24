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
    void flotar(long posActual){
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
        if(posHijoIzq<this->ultPos){
            if(posHijoDer<this->ultPos){
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
            if(posHijoDer<this->ultPos){
                if(this->arr[posActual]<=this->arr[posHijoDer])return;
                swap(posActual, posHijoDer);
                hundir(posHijoDer);
            }else{
                return;
            }
        }
        
    }
public:
    minHeap(long largo, long costo){
        this->arr= new long[largo+1];
        this->costo = costo;
        this->ultPos=0;
        this->largo = largo;
    }

    //insertamos al final y flotamos
    virtual void push(T elem)override{
        arr[this->ultPos+1]=elem;
        this->ultPos++;
        flotar(ultPos);
    }

    virtual T top()override{
        return this->arr[1];
    }
    virtual void pop() override{
        swap(1,this->ultPos);
        this->arr[this->ultPos]=-1;//lo borramos
        this->ultPos--;

        hundir(1);
        
    };
    virtual void consolidar()override{
        if(size()==1){
            this->costo=0;
            return;
        }
        if(this->ultPos==1)return;
        T raiz=this->arr[1];
        T hijoIzq = this->arr[2];
        T hijoDer = this->arr[3];

        if(hijoIzq!=-1){
            if(hijoDer!=-1){
                if(hijoIzq<=hijoDer){
                    this->arr[2]=raiz+hijoIzq;
                    this->costo += raiz+hijoIzq;
                    hundir(2);
                    
                      
                }else{
                    this->arr[3]=raiz+hijoDer;
                    this->costo += raiz+hijoDer;
                    hundir(3);
                    
                
                }
            }else{
                this->arr[2]=raiz+hijoIzq;
                this->costo += raiz+hijoIzq;
                hundir(2);
                
            }
            
        }else{
            if(hijoDer!=-1){
                this->arr[3]=raiz+hijoDer;
                this->costo += raiz+hijoDer;
                hundir(3);
                
               
            }else{
                return;
             }
            }
        
        pop();
        
        consolidar();
        

    }
    virtual long size() override{
        return this->largo;
    }
    virtual bool isEmpty() override{
        return size()==0;
    }
    virtual long getCosto()override{
        return this->costo;
    }
   
};