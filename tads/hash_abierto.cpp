#pragma once
#include "ListImp.cpp"
#include "Tabla.cpp"
#include "../funciones/hashFunc.cpp"
#include <assert.h>

template <class K, class V> class openedHashTable : public Tabla<K, V> {

private:
  

  // bucket*[]
  ListImp<std::string> **array;
  long cantidad, capacidad, largoArray, maxPalabras;
  hashFunc<V> *h;
  float fc;

  
  bool esPrimo(long num) {
    if (num <= 1)
      return false;
    if (num == 2)
      return true;
    if (num % 2 == 0)
      return false;
    for (long i = 3; i <= num / 2; i += 2) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }

  long primoSup(long num) {
    while (!esPrimo(num)){
        num++;
    }
    return num;
  }

  long abs(long x) {
    if (x < 0)
      return -x;

    return x;
  }

public:
  openedHashTable(long capacidad, hashFunc<V> *h) {
    this->cantidad = 0;
    this->capacidad = capacidad;
    this->fc = 0.0;
    this->largoArray = primoSup(capacidad);
    this->array = new ListImp<std::string> *[largoArray]();
    this->h = h;
    this->maxPalabras=0;
  }

  virtual void set(V value) override {
    long long pos = abs(this->h->hash(value)%this->largoArray);//ver si sacamos el modulo o no
    ListImp<std::string> * l = this->array[pos];
    if (l == nullptr) {
         l = new ListImp<std::string>();  
         this->cantidad++;     
    }
    l->insert(value);
    int tamanio = l->getSize();
    if(tamanio>this->maxPalabras){
        this->maxPalabras=tamanio;
    }
    
    }
    virtual long get(V value) override{
        long long pos = abs(this->h->hash(value)%this->largoArray);
        if(this->array[pos]==nullptr)return 0;
        long largo = (this->array[pos])->getSize();
        return largo;
    }
       
  

  virtual long size() override { return this->cantidad; }
  virtual long getMax() override { return this->maxPalabras;}
  
};