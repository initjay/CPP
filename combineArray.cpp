// combine
#include <iostream>
using namespace std;

void combine(int [], int&, int [], int);

int main(){
  int Array1[10] = {1, 2, 3, 4, 5, 6};
  int Array2[4] = {20, 21, 22, 23};
  int Array1size = 6;
  int Array2size = 4;

  combine(Array1, Array1size, Array2, Array2size);

  return 0;
}

void combine(int arr1[], int& size1, int arr2[], int size2) {
  int halfIndex;
  halfIndex = (size1 - 1) / 2;
  //int arr1size = size1 + size2;

  for(int i = 0; i < size2; i++){
    arr1[halfIndex + size2] = arr1[halfIndex];
    halfIndex++;
  }

  halfIndex = (size1 - 1) / 2;

  for(int i = 0; i <size2; i++){
    arr1[halfIndex + 1] = arr2[i];
    halfIndex++;
  }

  for(int i = 0; i < 10; i++) {
    cout << arr1[i];
  }

}
