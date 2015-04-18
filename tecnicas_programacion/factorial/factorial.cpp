#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  int numero, factorial = 1;

  cout << "Calcular factorial de: ";
  cin >> numero;

  for(int i = 2; i <= numero; i++)
    factorial *= i;

  printf("\nEl factorial de !%d es: %d", numero, factorial);
  cout << endl;

  return 0;
}
