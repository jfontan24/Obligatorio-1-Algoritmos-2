#pragma once

template <class T> class hashFunc {
public:
  virtual long long hash(T t) = 0;
};