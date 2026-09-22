#pragma once
template <class T> class HeapBinario{
public:
    virtual void push(T elem)=0;
    virtual T top()=0;
    virtual void pop()=0;
    virtual void consolidar()=0;
    virtual long size()=0;
    virtual bool isEmpty()=0;
    virtual long getCosto()=0;
    virtual void imprimir()=0;
};