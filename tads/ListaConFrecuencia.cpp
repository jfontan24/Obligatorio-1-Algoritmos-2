#pragma once

#include "ListF.cpp"
#include <cassert> 
//se basa en los metodos de ListImp.cpp dada en el template del obligatorio

template <class T> class ListaConFrecuencia : public ListF<T> 

{
private:
    // define a inner class (Node) to be used by the double linked list
    class Node
    {
    public:
        T element;
        int frecuencia;
        Node *next;
        Node *previous;
        Node(T element, int frecuencia, Node *next, Node *previous) : element(element), frecuencia(frecuencia), next(next), previous(previous) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    ListaConFrecuencia() : head(nullptr), size(0) {}

    virtual void insert(T element, int frecuencia) override
    {
        Node *newNode = new Node(element,frecuencia, nullptr, this->tail);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    virtual void insertAt(int index, T element, int frecuencia) override
    {
        assert(index >= 0 && index < size);
        Node *newNode = new Node(element,frecuencia, nullptr, nullptr);
        if (index == 0)
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else if (index == size)
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            newNode->next = current;
            newNode->previous = current->previous;
            current->previous->next = newNode;
            current->previous = newNode;
        }
        size++;
    }

    virtual bool isEmpty() override
    {
        return head == nullptr;
    }

    virtual T get(int index)override
    {
        assert(index >= 0 && index < size);
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->element;
    }
    virtual int getFrecuencia(T element)override{
        Node *current = head;
        while(current->next != nullptr && current->element!=element){
            current = current->next;
        }
        if(current->element==element){
            return current->frecuencia;
        }else{
            return 0;
        }
    }

    //devueleve un numero para saber si inserto un nuevo nodo(1) o simplemente actualizo la frecuencia de uno ya existente(0)
    virtual int aumentarFrecuencia(T element)override{
        Node *current = head;
        while(current->next != nullptr && current->element!=element){
            current = current->next;
        }
        if(current->element==element){
            current->frecuencia++;
            return 0;
        }else{
            insert(element,1);
            return 1;
        }
    }

    virtual int getSize() override
    {
        return size;
    }
};
