#pragma once

#include "hashFunc.cpp"
#include <string>


class stringHash : public hashFunc<std::string> {
  
  virtual long long hash(std::string s) override {
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
   int p = 31;
   int m = 1000000007;
   long long hash_value=0;
   long long p_pow = 1;
   for(int i=0; i<cadena.length(); i++){
      hash_value = (hash_value + (cadena[i] - 'a' + 1)*p_pow)%m;
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