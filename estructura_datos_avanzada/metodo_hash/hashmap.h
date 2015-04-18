#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include "hashitem.h"

typedef unsigned int uInt;

template <class K, class V>
class HashMap{
private:
    // const int sttsFound = 0;
    typedef struct{
      uInt indexFetched;
      int status;
    } CollisionData;
    K key;
    V value;
    int tableSize,
      totalElements,
      extraSize;
    uInt wordVal;
    HashItem<V> *table;

  public:
    HashMap(int);
    bool put(K, V);
    uInt hashAlgorithm(K);
    uInt processingKeyChain(char*);
    uInt processingKeyElement(uInt);
    uInt indexingKey(uInt);
    void indexingValue(uInt);
    void sortIndexByLowest(uInt);
};

template <class K, class V>
HashMap<K, V>::HashMap(int tablaSize = 10){
  tableSize = tablaSize;
  totalElements = 0;
  wordVal = 0;
  extraSize = 10;
  table = NULL;
}

template <class K, class V>
bool HashMap<K, V>::put(K key, V value){
  this->key = key;
  this->value = value;
  uInt index = hashAlgorithm(key);
  if(table == NULL)
    table = new HashItem<V>[tableSize];
  totalElements++;
  indexingValue(index - 1);
  return true;
}

template <class K, class V>
uInt HashMap<K, V>::hashAlgorithm(K key){
  uInt index = 0;
  size_t size = sizeof(key);
  char *ptrKey = (char*)&key;
  char *shiftedKey = new char[size + 1];
  for(int i = 0; i < size; i++){
    if(ptrKey[i] == 0)
      shiftedKey[i] = '|';
    else
      shiftedKey[i] = ptrKey[i];
  }
  shiftedKey[size] = 0;
  index = processingKeyChain(shiftedKey);

  return index;
}

template <class K, class V>
uInt HashMap<K, V>::processingKeyChain(char *key){
  uInt letter, wordValue = 0;
  for(int i = 0; key[i] != 0; i++){
    letter = (uInt)key[i];
    wordValue += processingKeyElement(letter);
  }
  wordVal = wordValue;
  return indexingKey(wordValue);
}

template <class K, class V>
uInt HashMap<K, V>::indexingKey(uInt value){
  int n;
  uInt curVal, val;
  do{
    n = 10;
    curVal = value % n;
    val = curVal;
    while((value / n) > 10){
      n *= 10;
      curVal = value % n;
      curVal -= (value % (n / 10));
      curVal /= (n / 10);
      val += curVal;
    }
    val += (value / n);
    value = val;
  }while(val > tableSize);
  return val;
}

template <class K, class V>
uInt HashMap<K,V>::processingKeyElement(uInt elem){
  int n = 10, pos = 1;
  uInt curVal, val;
  curVal = elem % n;
  val = curVal + pos;
  while((elem / n) > 10){
    n *= 10;
    ++pos;
    curVal = elem % n;
    curVal -= (elem % (n / 10));
    curVal = (curVal == 0)
      ? (n / 10)
      : (curVal / (n / 10)) + pos;
    val += curVal;
  }
  ++pos;
  val += ((elem / n) + pos);
  int ini = (int) ((elem % 10) * 1),
   fin = (int) ((elem / n) * pos);
   val += fin + ini;
   return val;
}

template <class K, class V>
void HashMap<K, V>::indexingValue(uInt keyIndex){
  int EMPTY = 0;
  if(table[keyIndex].index == EMPTY){
    table[keyIndex].index = keyIndex + 1;
    table[keyIndex].value = value;
    table[keyIndex].tableElement = totalElements;
  }else{
    std::cout << std::endl << "Collision at: " << keyIndex << std::endl;
    uInt collision = table[keyIndex].collisions,
      expand = (collision - (collision % extraSize)) + extraSize;
    if(table[keyIndex].values == NULL){
      table[keyIndex].values = new V[extraSize];
      table[keyIndex].tableElems = new uInt[extraSize];
      table[keyIndex].gap = new uInt[extraSize];
    }
    else if(collision >= expand){
      expand += extraSize;
      V *qval = new V[expand];
      uInt *qgap = new uInt[expand],
      *qelems = new uInt[expand];

      for(int i = 0; i < collision; i++){
        qval[i] = table[keyIndex].values[i];
        qelems[i] = table[keyIndex].tableElems[i];
        qgap[i] = table[keyIndex].gap[i];
      }
      delete[] table[keyIndex].values;
      delete[] table[keyIndex].tableElems;
      delete[] table[keyIndex].gap;
      table[keyIndex].values = qval;
      table[keyIndex].tableElems = qelems;
      table[keyIndex].gap = qgap;
    }
    table[keyIndex].values[collision] = value;
    table[keyIndex].tableElems[collision] = totalElements;
    table[keyIndex].gap[collision] = wordVal;

    //HERE IT GOES
    if(collision > 0)
      sortIndexByLowest(keyIndex);
    else
      table[keyIndex].sort = "0";

    table[keyIndex].collisions++;
  }
}

template <class K, class V>
void HashMap<K, V>::sortIndexByLowest(uInt ki){

}

#endif
