#pragma once
template <class T> class HeapBinario{
public:
    virtual void push(T elem)=0;
    virtual T top()=0;
    virtual T pop()=0;
    virtual int size()=0;
    virtual bool isEmpty()=0;
}