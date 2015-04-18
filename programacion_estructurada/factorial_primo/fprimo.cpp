/* Alumno: Alvarado Álvarez Erick
   Matricula: 133393
   I.D.S.
*/

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

/*Messages*/
#define MSSG_1 "Factorizacion en primo de p = "
/*end-messages*/

/*Functions*/
bool init(); /*Iniciamos las funciones correspondientes a Factorial Primo.
Retorna true si termina con éxito.*/
bool isPrimo(long);
long getFactorPrimo(long);/*Se verifica que mientras el núm. primo más pequeño no sea
menos o igual al número a factorizar, que entonces prosiga con la factorización.*/
void factorizacionPrimo(long);
/*end-functions*/

int main(int argc, char* argv[]){
  /*factorial primo*/
  init();

  return 0;
}

bool init(){
  long p;
  do{//Solicitar número hasta encontrar FinDeLinea
    cout << MSSG_1;
    scanf("%ld", &p);
    factorizacionPrimo(p);
    cout << endl;
    fflush(stdin);
  }while(p != EOF);
  return true;
}

void factorizacionPrimo(long n){
  n = getFactorPrimo(n);
  if (n > 1)
    printf("%ld\n",n); //Se imprime el factor encontrado.
}

long getFactorPrimo(long c){
  cout << endl;
  for(int i = 2; c > 1; i++){
    if((c % i == 0) && isPrimo(i)){
      cout << i << " | " << c << endl;
      c /= i--;
    }
  }
  return c;
}

bool isPrimo(long n){
  int counter = 0;
  for(int i = 2; i < n; i++){
    if(n % i == 0){
      counter++;
      break;
    }
  }
  return (counter == 0);
}

bool isPar(int num){
  return (num % 2 == 0);
}
