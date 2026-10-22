#pragma once

//basado en el codigo visto en clase

template <class T> class HeapBinario{
public:
    virtual void push(T elem)=0;
    virtual T top()=0;
    virtual void pop()=0;
    virtual long size()=0;
    virtual bool isEmpty()=0;
    
};