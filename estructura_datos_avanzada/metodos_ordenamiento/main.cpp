#include <stdio.h>
#include <iostream>
#include "Sorter.h"

using namespace std;

#define TTL_1 "\n.::Metodos de Ordenamiento::.\n"
#define MSSG_1 "\nOpcion no definida.\n"
#define SPLITTER " "

enum{ESALIR = 1, EBURBUJA, EQUICKSORT, ESHELLSHORT, EINSERCION, ERADIX};
typedef double type; /*Define the countable variable type your string will be; (int, double, float, char...)*/
void printArray(type*, int);
template <typename var>
void method(var&, int);
int menu(const char*);
type* ask(int&);

int main(int argc, char* argv[]){
  int size, opc;
  Sorter<type> sorter;
  type *arr = NULL;
  do{
    opc = menu(TTL_1);
    switch(opc){
      case ESALIR: return 1;
      case EBURBUJA:
          arr = ask(size);
          sorter.setArrayOfElements(arr, size);
          method(sorter, SORT_BURBUJASORT);
        break;
      case EQUICKSORT:
          arr = ask(size);
          sorter.setArrayOfElements(arr, size);
          method(sorter, SORT_QUICKSORT);
        break;
      case ESHELLSHORT:
          arr = ask(size);
          sorter.setArrayOfElements(arr, size);
          method(sorter, SORT_SHELLSORT);
        break;
      case EINSERCION:
          arr = ask(size);
          sorter.setArrayOfElements(arr, size);
          method(sorter, SORT_INSERCIONSORT);
        break;
      case ERADIX:
          arr = ask(size);
          sorter.setArrayOfElements(arr, size);
          method(sorter, SORT_RADIXSORT);
        break;
      default: cout << MSSG_1;
    }
  }while(opc >= 0);

  return 0;
}

int menu(const char *title){
  int op = 0;
  cout << title;
  cout << "1. Salir" << endl;
  cout << "2. Burbuja" << endl;
  cout << "3. QuickSort" << endl;
  cout << "4. ShellSort" << endl;
  cout << "5. Inserrcion" << endl;
  cout << "6. Radix[LSD]" << endl;
  cout << "Seleccione una opcion: ";
  scanf("%d", &op);
  fflush(stdin);
  return op;
}

type* ask(int &size){
  cout << "\nIntroduzca el tamanho de la cadena<int>: ";
  cin >> size;
  type *a = new type[size];
  cout << "\nIntroduzca una cadena de elementos<type>: ";
  for(int i = 0; i < size; i++)
    cin >> a[i];
  return a;
}

template <typename var>
void method(var &sort, int SortMethod){
  int size = sort.getArrayLength();
  type *arr = sort.getSortedArrayBy(SortMethod); /*Default is burble sort*/
  printArray(arr, size);
}

void printArray(type *arr, int size){
  cout << endl;
  for(int i = 0; i < size; i++)
    cout << arr[i] << SPLITTER;
  cout << endl;
}
