#pragma once

template <class T> 
// en mi árbol binario de busqueda no le voy a definir el tipo. Lo voy a definir desde afuera

//en la clase por defecto son privado
//en un struct por defecto son publicos
//q sea privado esq desde otra clase no se puede modificar
class bst{
public:
    //que iguale las funciones a 0 significa q es abstracto. es como si fuera un null xq una funcion no puede ser igual a null
    //que una clase sea abstracta significa que no se puede instanciar
    virtual void add(T data) = 0; // virtual significa q podemos heredar
    //virtual void remove(T data) = 0;
    virtual bool search(T data)=0;
    virtual void range(T desde, T hasta)=0;
    virtual int size()=0;
    virtual T max() = 0;
    virtual T min() = 0;
};