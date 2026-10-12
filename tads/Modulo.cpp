#pragma once
#include <cstdint>
struct modulo{
    int64_t nroVertice, prio;
    modulo() {} //necesitamos esto pero nose xq
    modulo(int64_t nroVertice, int64_t prio){
        this->nroVertice = nroVertice;
        this->prio= prio;
        
    }
    
    bool operator<(const modulo &other) { return (this->prio < other.prio) || ((this->prio == other.prio) && (this->nroVertice < other.nroVertice)); }
    bool operator>(const modulo &other) { return (this->prio > other.prio) || ((this->prio == other.prio) && (this->nroVertice > other.nroVertice)); }
    bool operator<=(const modulo &other) { return this->prio <= other.prio; }
    bool operator>=(const modulo &other) { return this->prio >= other.prio; }
    bool operator==(const modulo &other) { return (this->prio == other.prio) && (this->nroVertice == other.nroVertice); }
};