include <iostream>
include <stdio.h>

using namespace std;

int isprimoa(long);
int isprimob(long);
int isprimoc(long);

int main(int argc, char* argv[]){

  return 0;
}


int isprimoa(long n){
  int counter = 0;
  for(int i = 2; i < n; i++){
    if(n % i == 0){
      counter++;
      break;
    }
  }

  return counter;
}
int isprimob(long n){

  int counter = 0;
  for(int i = 2; i < (n/2); i++){
    if(n % i == 0){
      counter++;
      break;
    }
  }

  return counter;
}
int isprimoc(long n){

  int counter = 0;
  for(int i = 2; i < (sqrt(n)+1); i++){
    if((sqrt(n)+1) % i == 0){
      counter++;
      break;
    }
  }

  return counter;
}
