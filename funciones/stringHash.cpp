#pragma once

#include "hashFunc.cpp"
#include <string>

//funcion de hash basada en el polynomial rolling hash function

class stringHash : public hashFunc<std::string> {
  
  virtual long long hash(std::string s) override {
   
   int p = 31;
   int m = 1000000007;
   long long hash_value=0;
   long long p_pow = 1;
   for(int i=0; i<s.length(); i++){
      hash_value = (hash_value + (s[i] - 'a' + 1)*p_pow)%m;
      p_pow = (p_pow*p)%m;
   }
   
   return hash_value;
   
   /*
   long long modulo = 1000000007;
   long long base = 31;
   long long hash=0;
   for(long i=0;i<26;i++){
      hash = (hash*base + i)% modulo;
   }
   
   return hash;
  }
   */
}
};