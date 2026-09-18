#pragma once
//se basa en List.h dada en template del obligatorio pero con modificaciones
template <class T> class ListF {
public:
    virtual void insert(T element, int frecuencia)=0;
    virtual void insertAt(int index, T element, int frecuencia)=0;
    virtual bool isEmpty()=0;
    virtual T get(int index)=0;
    virtual int getFrecuencia(T element)=0;
    virtual int aumentarFrecuencia(T element)=0;
    virtual int getSize()=0;
};

