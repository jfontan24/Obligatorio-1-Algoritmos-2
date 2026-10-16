#ifndef LIST_IMP
#define LIST_IMP

#include "List.h"
#include <cassert>
#include <iostream>

template <class T>
class ListImp : public List<T>
{
private:
    // define a inner class (Node) to be used by the double linked list
    class Node
    {
    public:
        T element;
        Node *next;
        Node *previous;
        Node(T element, Node *next, Node *previous) : element(element), next(next), previous(previous) {}
    };

    Node *head;
    Node *tail;
    int size;
    class arrListIterator:public iterator<T>{
    private:
        Node* actual;
    public:
        arrListIterator(Node* head){
            this->actual = head;
        }

        virtual bool hasNext() override{
            return (this->actual) != nullptr;
        }
        virtual T next() override{
            T elem = this->actual->element;
            this->actual = this->actual->next;
            return elem;
        }
    };



public:
    ListImp() : head(nullptr), size(0) {}

    void insert(T element)
    {
        Node *newNode = new Node(element, nullptr, this->tail);
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

    void insertAt(int index, T element)
    {
        assert(index >= 0 && index < size);
        Node *newNode = new Node(element, nullptr, nullptr);
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

    void remove(T element)
    {
        Node *current = head;
        while (current != nullptr)
        {
            // note: that the elment should implement == operator
            if (current->element == element)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head != nullptr)
                    {
                        head->previous = nullptr;
                    }
                }
                else if (current == tail)
                {
                    tail = current->previous;
                    if (tail != nullptr)
                    {
                        tail->next = nullptr;
                    }
                }
                else
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    void removeAt(int index)
    {
        assert(index >= 0 && index < size);
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        if (current == head)
        {
            head = current->next;
            if (head != nullptr)
            {
                head->previous = nullptr;
            }
        }
        else if (current == tail)
        {
            tail = current->previous;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
        }
        else
        {
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }
        delete current;
        size--;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    T get(int index)
    {
        assert(index >= 0 && index < size);
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->element;
    }

    int getSize()
    {
        return size;
    }

    virtual iterator<T>* getIterator()override{
        return new arrListIterator(this->head);
    }

    virtual void imprimir() override{
        Node * aux = this->head;
        while(aux->next != nullptr){
            std::cout<<aux->element.from<<" "<<aux->element.to<<std::endl;
            aux=aux->next;
        }
    }
};

#endif