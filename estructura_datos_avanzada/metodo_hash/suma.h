#ifndef _SUMA_H_
#define _SUMA_H_

#include <stdio.h>
#include <iostream>

template <class T>
class Suma{
  T a, b;
  public:
    int suma(T, T);
};

template <class T>
int Suma<T>::suma(T x, T y){
  a = x;
  b = y;
  return (a + b);
}

#endif
