#pragma once

//basado en codigo visto en clase

template <class V> class Tabla {
public:
  virtual void set(V value) = 0;
  virtual long get(V value) = 0;
  virtual long size() = 0;
  virtual long getMax() = 0;
};