/* Alumno: Alvarado Álvarez Erick
   Matricula: 133393
   I.D.S.
   v2.0 C Language
   V1.0 C++ Language
*/

#include <stdio.h>
//#include <iostream>
#include <math.h>

// using namespace std;

/*Messages*/
#define MSSG_1 "Factorizacion en primo de p = "
#define true 1 /*Comment this if you're using c++*/
#define false 0 /*Comment this if you're using c++*/
/*end-messages*/

/*Functions*/
void init(); /*Iniciamos las funciones correspondientes a Factorial Primo.
Retorna true si termina con éxito.*/
/*bool*/int isPrimo(long); //Verifica que el número sea primo(true).
long getFactorPrimo(long); /*Consigue los números primos respecto al valor
otorgado por el usuario*/
void factorizacionPrimo(long);
/*end-functions*/

int main(int argc, char* argv[]){
  /*factorial primo*/
  init();

  return 0;
}

void init(){
  long p;
  do{//Solicitar número hasta encontrar FinDeLinea
    printf("%s", MSSG_1); //cout << MSSG_1;
    scanf("%ld", &p);
    factorizacionPrimo(p);
    printf("\n");// cout << endl;
    fflush(stdin); //Limpia buffer de entrada, evitando imprima tras forzar cierre.
  }while(p != EOF);
}

void factorizacionPrimo(long n){
  n = getFactorPrimo(n);
  if (n > 1)
    printf("%ld\n",n); //Se imprime el factor encontrado.
}

long getFactorPrimo(long c){
  printf("\n");// cout << endl;
  int i;
  for(/*int*/ i = 2; c > 1; i++){
    if((c % i == 0) && /*isPrimo(i)*/ (isPrimo(i) == true)){
      printf("%d | %ld\n", i, c);// cout << i << " | " << c << endl;
      c /= i--;
    }
  }
  return c;
}

/*bool*/int isPrimo(long n){
  int i, counter = 0;
  for(/*int*/ i = 2; i < n; i++){
    if(n % i == 0){
      counter++;
      break;
    }
  }
  return (counter == 0);
}

/*bool*/int isPar(int num){
  return (num % 2 == 0);
}
