#pragma once
#include "Grafo.cpp"
#include <cassert>
#include "ListImp.cpp"
#include <stdint.h>
class list_graph:public Grafo{
private:
    int64_t vertices;
    bool isDirected;
    List<edge>**listArr;
public:
    list_graph(int64_t vertices, bool isDirected){
        this->vertices = vertices;
        this->isDirected=isDirected;
        this->listArr = new List<edge>*[vertices+1];
        for(int64_t i=1;i<=vertices;i++)
        {
            this->listArr[i]=new ListImp<edge>();
        }
    }

    virtual void addEdge(int64_t v, int64_t w)override{
        addWeightEdge(v,w,1);
    };
    virtual void addWeightEdge(int64_t v, int64_t w, int64_t weight)override{
        assert(v>0);
        assert(v<=this->vertices);
        assert(w>0);
        assert(w<=this->vertices);
        assert(weight!=0);//que el costo no sea 0

        edge newEdge = edge(v,w,weight);
        listArr[v]->remove(newEdge);
        listArr[v]->insert(newEdge);

        if(this->isDirected){
            edge newEdge = edge(w,v,weight);
            listArr[v]->remove(newEdge);
            listArr[v]->insert(newEdge);
        }

    };
    /*
    virtual void removeEdge(int64_t v, int64_t w)override{
        assert(false);
    };
    virtual void removeAllEdges(int64_t v)override{
        assert(false);
    };
    virtual bool hasEdge(int64_t v, int64_t w)override{
        assert(false);
    };
    virtual edge getEdge(int64_t v,int64_t w)override{
        assert(false);
    };*/
    virtual iterator<edge> *getAllEdges()override{
        List<edge>* collection = new ListImp<edge>();
        for(int64_t i=1;i<this->vertices;i++){
            iterator<edge>* it = this->listArr[i]->getIterator();
            while(it->hasNext()){
                collection->insert(it->next());
            }
        }
        return collection->getIterator();
    };
    virtual iterator<edge> *getNeighbours(int64_t v)override{
        assert(v>0);
        assert(v<=this->vertices);
        return this->listArr[v]->getIterator();
    };
    virtual int64_t** adjMatrix()override{
        int64_t** mat = new int64_t*[this->vertices+1];
        for(int64_t i=1;i<=this->vertices;i++){
            mat[i]=new int64_t[this->vertices+1];
        }
        iterator<edge>* it = getAllEdges();
        while(it->hasNext()){
            edge e= it->next();
            mat[e.from][e.to]=e.weight;
        }
        return mat;
    }
    /*
    virtual int64_t V()override{
        return this->vertices;
    };*/
};