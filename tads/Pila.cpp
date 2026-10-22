#pragma once
#include <cstdint>

class Pila {
    private:
    struct NodoLista {
        NodoLista* sig;
        int64_t dato;
    };

    NodoLista* ultimo; 
	int64_t cant;

    public:
    Pila* crearPila() {
        Pila* pila = new Pila;
        pila->ultimo = nullptr;
        pila->cant = 0;
        return pila;    
    }

    void push(int64_t e) {
        NodoLista* nuevo = new NodoLista;
        nuevo->dato = e;
        this->cant++;
        nuevo->sig = this->ultimo;
        this->ultimo = nuevo;
    }

    int top() {
        if (esVacia()) return 0;
        return this->ultimo->dato;
    }

    void pop() {
        if (this->ultimo == nullptr) return; 
        NodoLista* aBorrar = this->ultimo;
        this->ultimo = this->ultimo->sig;
        delete aBorrar;
        aBorrar = nullptr;
        this->cant--;
    }


    bool esVacia() {
        return this->ultimo == nullptr;
    }

};







