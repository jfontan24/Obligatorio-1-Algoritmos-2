#pragma once
#include "iterator.cpp"
#include <cstdint>

struct edge{
    int64_t from,to,weight;
    edge(){};
    edge(int64_t from, int64_t to, int64_t weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    
    bool operator==(const edge &other) { return (this->from == other.from) && (this->to == other.to); }
    //bool operator==(const edge &other) { return (this->weight == other.weight); }
    bool operator<(const edge &other) { return (this->weight < other.weight); }
    bool operator>(const edge &other) { return (this->weight > other.weight); }
    bool operator<=(const edge &other) { return this->weight <= other.weight; }
    bool operator>=(const edge &other) { return this->weight >= other.weight; }
};
class Grafo{
public:
    virtual void addWeightEdge(int64_t v, int64_t w, int64_t weight)=0;
    virtual void addEdge(int64_t v, int64_t w)=0;
    virtual iterator<edge> *getNeighbours(int64_t v)=0;
    virtual int64_t** adjMatrix()=0;
    virtual iterator<edge> *getAllEdges()=0;
    virtual int64_t cantVertices()=0;
    
};