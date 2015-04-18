#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  int contador = 5;

  cout << "Contador del 1 al " << contador << endl;

  for(int i = 1; i <= contador; i++)
    printf("%d, ", i);

  cout << endl;

  return 0;
}
