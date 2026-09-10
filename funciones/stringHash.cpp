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
      cadena+=std::to_string(array[i]);
   }
   long long modulo = 1000000007;
   long long base = 31;
   long long hash=0;
   for(long i=0;i<26;i++){
      hash = (hash*base + i)% modulo;
   }
   
   return hash;
  }
};