// Program that creates array of pointers
#include <iostream>
#include <string>
using namespace std;

struct Person{
  string name;
  int age;
};

int main(){
  Person* persPtr[3];

  for(int i = 0; i < 3; i++){
    persPtr[i] = new Person;

    persPtr[i]->name = "Vegeta";
    persPtr[i]->age = 8999;
  }

  for(int i = 0; i < 3; i++){
    cout << persPtr[i]->name << endl
         << persPtr[i]->age << endl;
  }

  //Person** ptr2 = &persPtr; // pointer to a pointer

  //Person*** ptr3 = &ptr2; // pointer to a pointer to a pointer



  return 0;
}
