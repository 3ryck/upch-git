#include<stdio.h>
#include<iostream>
#include<iomanip>

/*@author 3ryck<erick.alvarado.ez@outlook.com>*/

using namespace std;


//cin.exceptions(std::ios_base::failbit);
//}catch(std::ios_base::failure const& ex){
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987...
int isValidInput(int &val){
  int tof = 1;
  cin >> val;
  try{
    if(!cin)
      throw -1;
    else if(val < 0)
      throw 1;
    }catch(int ex){
      if(ex > 0)
        cout << "Only unsigned values. " << ex << endl;
      else
        cout << "Only numeric values. " << ex << endl;
      tof = 0;
    }
    return tof;
}

int fibo(){
  int limit_value, a = 0, b = 1, c;
  cout << "Ingrese limite: ";
  if(!(isValidInput(limit_value)))
    return 0;
  else if(limit_value == 0){
    cout << endl << "0" << endl;
    return 1;
  }

  printf("%i, %i, ", a, b);
  for(int i = 3; i <= limit_value; i++){
    c = a + b;
    printf("%i, ", c);
    a = b;
    b = c;
  }

}

int main(int argv, char* argc[]){

  fibo();

  return 0;
}
