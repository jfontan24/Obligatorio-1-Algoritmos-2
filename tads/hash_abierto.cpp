#pragma once
#include "Tabla.cpp"
#include "../funciones/hashFunc.cpp"
#include "ListaConFrecuencia.cpp"
#include <assert.h>

template <class K, class V> class openedHashTable : public Tabla<K, V> {

//template visto en clase

private:
  

  // bucket*[]
  ListaConFrecuencia<std::string> **array;
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
  std::string ordenar(std::string s){
    long array[26] = {0};
    for(long i=0; i<s.length(); i++){
        long pos = s[i] - 97;
        array[pos]++;
    }
    std::string cadena;
    for(long i=0; i<26; i++){
        for(long j=0; j<array[i]; j++){
          char letra = i+97;
          cadena+=letra;
        }
        
    }
    return cadena;
  }

public:
  openedHashTable(long capacidad, hashFunc<V> *h) {
    this->cantidad = 0;
    this->capacidad = capacidad;
    this->fc = 0.0;
    this->largoArray = primoSup(capacidad);
    this->array = new ListaConFrecuencia<std::string> *[largoArray]();
    this->h = h;
    this->maxPalabras=0;
  }

  virtual void set(V value) override {
    std::string pal = ordenar(value);
    long long pos = abs(this->h->hash(pal)%this->largoArray);
    ListaConFrecuencia<std::string> * l = this->array[pos];
    if (l == nullptr) {
         l = new ListaConFrecuencia<std::string>();  
         l->insert(pal,1);
         this->cantidad++;
         this->array[pos]=l;    
    }else{
          int inserte = l->aumentarFrecuencia(pal);//aumentarFrecuencia lo inserta sino estaba ese bucket
          if(inserte==1){
            this->cantidad++;
          }       
    }
    
    int tamanio = l->getFrecuencia(pal);
    if(tamanio>this->maxPalabras){
        this->maxPalabras=tamanio;
    }
    
    }
    virtual long get(V value) override{
        std::string pal = ordenar(value);
        long long pos = abs(this->h->hash(pal)%this->largoArray);
        if(this->array[pos]==nullptr)return 0;
        ListaConFrecuencia<std::string> * l = this->array[pos];
        return l->getFrecuencia(pal);
    }
       
  

  virtual long size() override { return this->cantidad; }
  virtual long getMax() override { return this->maxPalabras;}
  
};

//100 000, 10 000, ejemplo1, ejemplo2