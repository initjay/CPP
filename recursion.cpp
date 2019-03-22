// James Werrett
// Example of Recursion
#include <iostream>
using namespace std;

int arraySum(int [], int);

int main ()
{
  // let user decide on size of array
  int total, size;
  cout << "How big do you want the array?" << endl;
  cin >> size;

  int array[size];

  // let user input values for each array entry
  cout << "Enter integers to the array: " << endl;
  for (int i = 0; i < size; i++)
    cin >> array[i];

  // function call to sum array
  total = arraySum(array, size);
  cout << endl << total << endl;
  return 0;
}

// recursive function to sum array values
int arraySum(int arr[], int size)
{
  if (size <= 0)
    return 0;
  return (arraySum(arr, size - 1) + arr[size - 1]);   /* continues to 'popout' last value of 
                                                         array until size of 0 reached */
}
