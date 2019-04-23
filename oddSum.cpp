// Program that adds all odd entries
// in an array.
#include <iostream>
using namespace std;

int oddSum(int [], int);

int main(){
  int sum;
  int testArray[10];
  cout << "\nEnter 10 ints.\n";

  for (int i = 0; i < 10; i++){
    cin >> testArray[i];
  }

  sum = oddSum(testArray, 10);

  cout << sum << endl;


  return 0;
}

int oddSum(int arr[], int size){
  int sum = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] % 2 != 0){
      sum += arr[i];
    }
  }
  return sum;
}
