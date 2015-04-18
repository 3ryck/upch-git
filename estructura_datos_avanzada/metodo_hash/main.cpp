#include <stdio.h>
#include <iostream>
#include "hashmap.h"
#include "Suma.h"

using namespace std;

int main(int argc, char* argv[]){
  Suma<char> s, t;
  HashMap< int, const char*> m;
  HashMap< int, Suma<char> > mapeo;
  HashMap< HashMap< int, Suma<char> >, Suma<char> > maps;
  s.suma('c', 'd');
  t.suma('x', 'y');
  // m.put(168, "lol");
  mapeo.put(5123456, s);
  s.suma('q', 'w');
  mapeo.put(1, s);
  s.suma('e', 'r');
  mapeo.put(2, s);
  s.suma('t', 'y');
  mapeo.put(3, s);
  s.suma('i', 'u');
  mapeo.put(1, s);
  maps.put(mapeo, t);
  char *c2 = (char*)&maps;
  for(int i = 0; i < sizeof(maps); i++){
    if(c2[i] != 0)
      cout << endl << c2[i];
  }

  // cout << "\nS: ";// << s.suma(12, 10) << endl;;

  return 0;
}
