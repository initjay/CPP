//This program exchanges two numbers using a function
// that accepts pointer variables as arguments.
//James Werrett
#include <iostream>
using namespace std;

void exchange (int *x, int *y);

int main ()
{
  int num1, num2;

  cout << "\nEnter the first number to swap:";
  cin >> num1;
  cout << "\nEnter the second number:";
  cin >> num2;

  cout << "\n\nThe numbers are " << num1
       << " and " << num2;

  exchange(&num1, &num2);

  cout << "\nNow after swapping the numbers are "
       << num1 << " and " << num2 << endl << endl;

  return 0;
}

// pass by reference to accept address arguments
void exchange (int *x, int *y)      
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
