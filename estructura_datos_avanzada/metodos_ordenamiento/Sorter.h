#ifndef _SORTER_H_
#define _SORTER_H_

#define SORT_BURBUJASORT 1
#define SORT_QUICKSORT 2
#define SORT_SHELLSORT 3
#define SORT_INSERCIONSORT 4
#define SORT_RADIXSORT 5

template <class T>
class Sorter{
  private:
    int arrLength,
      method;
    T* arrElems;
  public:
    Sorter();
    Sorter(T*, int, int);
    void setArrayOfElements(T*, int);
    void setMethod(int);
    int getMethod();
    int getArrayLength();
    T* getSortedArrayBy(int);
    void burbujaSort();
    void quickSort(int, int);
    void shellSort();
    void insercionSort();
    void radixSort(); //LSD (Least Significant Digit)
};

template <class T>
Sorter<T>::Sorter(){
  method = SORT_BURBUJASORT;
  arrElems = NULL;
}

template <class T>
Sorter<T>::Sorter(T *arrElems, int length, int Method = 1){
  arrLength = length;
  method = Method;
  this->arrElems = arrElems;
}

template <class T>
void Sorter<T>::setArrayOfElements(T *arrElems, int length){
  arrLength = length;
  this->arrElems = arrElems;
}


template <class T>
void Sorter<T>::setMethod(int Method){
  method = Method;
}

template <class T>
int Sorter<T>::getMethod(){
  return method;
}

template <class T>
T* Sorter<T>::getSortedArrayBy(int Method = SORT_BURBUJASORT){
  method = Method;
  switch(Method){
    case SORT_BURBUJASORT:
        burbujaSort();
      break;
    case SORT_QUICKSORT:
        quickSort(0, arrLength - 1);
      break;
    case SORT_SHELLSORT:
        shellSort();
      break;
    default:  burbujaSort();
  }
  return arrElems;
}

template <class T>
int Sorter<T>::getArrayLength(){
  return arrLength;
}

template <class T>
void Sorter<T>::burbujaSort(){
  T temp;
  for(int i = 1; i < arrLength; i++)
    for(int j = 0; j < (arrLength - 1 ); j++)
      if(arrElems[j] > arrElems[j + 1]){
        temp = arrElems[j];
        arrElems[j] = arrElems[j + 1];
        arrElems[j + 1] = temp;
      }
}

template <class T>
void Sorter<T>::quickSort(int low, int high){
  T temp;
  int pivot, i , j;
  if(low < high){
    pivot = low;
    i = low;
    j = high;
    while(i < j){
      while(arrElems[i] <= arrElems[pivot] && i <= high)
        i++;
      while(arrElems[j] > arrElems[pivot] && j >= low)
        j--;
      if(i < j){
        temp = arrElems[i];
        arrElems[i] = arrElems[j];
        arrElems[j] = temp;
      }
    }
    temp = arrElems[j];
    arrElems[j] = arrElems[pivot];
    arrElems[pivot] = temp;
    quickSort(low, j - 1);
    quickSort(j + 1, high);
  }
}

template <class T>
void Sorter<T>::shellSort(){
  int i, j, step, sz = arrLength;
  T temp;
  step = sz / 2 ;
  while(step) {
    for (i = step; i < sz; i++) {
      temp = arrElems[i];
      j = i;
      while (j >= step && arrElems[j - step] > temp) {
        arrElems[j] = arrElems[j - step];
        j = j - step;
      }
      arrElems[j] = temp;
    }
    step = step / 2.2;
  }
}

template <class T>
void Sorter<T>::insercionSort(){
  int i, j;
  T temp;
  for(i = 1; i < arrLength; i++){
    temp = arrElems[i];
    j = i - 1;
    while( arrElems[j] > temp && j >= 0 ){
      arrElems[j + 1] = arrElems[j];
      j--;
    }
    arrElems[j + 1] = temp;
  }
}

template <class T>
void Sorter<T>::radixSort(){
  int MAX = 10, i, bucket[MAX], maxVal = 0, digitPosition =1,
    arraySize = arrLength;
  for(i = 0; i < arraySize; i++) {
    if(arrElems[i] > maxVal) maxVal = arrElems[i];
  }

  int pass = 1;  // used to show the progress
  /* maxVal: this variable decide the while-loop count
  if maxVal is 3 digits, then we loop through 3 times */
  while(maxVal/digitPosition > 0) {
    /* reset counter */
    int digitCount[10] = {0};

    /* count pos-th digits (keys) */
    for(i = 0; i < arraySize; i++)
      digitCount[arrElems[i]/digitPosition%10]++;

      /* accumulated count */
      for(i = 1; i < 10; i++)
        digitCount[i] += digitCount[i-1];

        /* To keep the order, start from back side */
        for(i = arraySize - 1; i >= 0; i--)
          bucket[--digitCount[arrElems[i]/digitPosition%10]] = arrElems[i];

          /* rearrange the original array using elements in the bucket */
          for(i = 0; i < arraySize; i++)
            arrElems[i] = bucket[i];

            /* at this point, a array is sorted by digitPosition-th digit */

            /* move up the digit position */
            digitPosition *= 10;
          }
}

#endif
