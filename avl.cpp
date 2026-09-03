#pragma once
#include "bst.cpp"
#include <assert.h>

template <class T> class avl : public bst<T> {
// en mi árbol binario de busqueda no le voy a definir el tipo. Lo voy a definir desde afuera

//en la clase por defecto son privado
//en un struct por defecto son publicos
//q sea privado esq desde otra clase no se puede modificar
private: // lo pongo para aclarar
    struct node{
        T data;
        node *left = nullptr;
        node *right = nullptr;
        int height = 1;

        //
        node(T data){
            this->data = data;
        }
    };
    node* root = nullptr;
    int size(node *n){
        if(n==nullptr){
            return 0;
        }
        return 1 + size(n->left) + size(n->right);
    }
    int max(int a, int b){
        if(a>b)
            return a;
        return b;
    }
    int height(node *n){
        if(n==nullptr){
            return 0;
        }
        return n->height;
    }
    node *leftRotation(node *n){
        node *z = n;
        node *y = z->right;
        node *y_l = y->left;

        z->right = y_l;
        y->left = z;

        //es importante que llame primero a z no?
        z->height = 1+ max(height(z->left),(height(z->right)));
        y->height = 1+ max(height(y->left),(height(y->right)));
        return y;
    }
    node *rightRotation(node *n){
       node *z = n;
       node *y = z->left;
       node *y_r = y->right;
       z->left = y_r;
       y->right = z;

       z->height = 1+ max(height(z->left),(height(z->right)));
       y->height = 1+ max(height(y->left),(height(y->right)));
       return y;
    }
    node *rightLeftRotation(node *n){
        n->right =rightRotation(n->right);
        return leftRotation(n);
    }
    node *leftRightRotation(node *n){
        n->left = leftRotation(n->left);
        return rightRotation(n);
    }
    node *add(node *n, T data){
        if(n==nullptr){
            return new node(data);
        }
        //else
        if(data < n->data){
            n->left = add(n->left, data);
        }else{
            n->right = add(n->right,data);
        }
        n->height = 1 + max(height(n->left), height(n->right));
        //si no esta balanceado, lo balanceamos
        n = balance(n);
        return n;
        
    }
    node *balance(node *n){
        int bF = height(n->left) - height(n->right);
        if(bF == -2){
            //desbalance der-?
            int bFRight = height(n->right->left) - height(n->right->right);
            if(bFRight == -1){
                //desbalance der-der
                n=leftRotation(n);
            }else{
                //desbalance der-izq
                n=rightLeftRotation(n);
            }
        }else if(bF==2){
            //desbalance izq-?
            int bFLeft = height(n->left->left) - height(n->left->right);
            if(bFLeft==-1){
                //desbalance izq-der
                n=leftRightRotation(n);
            }else{
                //desbalance izq-izq
                n=rightRotation(n);
            }
        }
        return n;
    };
    

};
    
    public:
        avl() {}
        virtual void add(T data) override { this->root = add(this->root,data); }
        virtual int size() override { return size(root); }
        virtual T max () override { assert(false); }//sacar
        virtual T min () override { assert(false); }//sacar
        

};