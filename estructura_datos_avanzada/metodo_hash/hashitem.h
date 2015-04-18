#ifndef _HASHITEM_H_
#define _HASHITEM_H_

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>

template <class V>
class HashItem{
  public:
    std::string sort;
    unsigned int
      index,
      tableElement,
      collisions,
      *tableElems,
      *gap;
    V *values,
      value;
    HashItem(){
      index = 0;
      tableElement = 0;
      collisions = 0;
      tableElems = NULL;
      gap = NULL;
      values = NULL;
    }
};

#endif
