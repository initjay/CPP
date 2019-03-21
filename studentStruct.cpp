// James Werrett
// Program that creates an array of students
#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
  string name;
  int studentID;
  int birthYear;
  float gpa;
};

const int NUM_STUDENTS = 10;

int menu();

int main()
{
  // variables to hold user choice, and for loop control
  int choice, i;
  // pointer to array of student structures
  Student *st = new Student[NUM_STUDENTS];

  do
  {
    // assigns choice from menu func into choice variable
    choice =  menu();
    switch (choice)
    {
      case 1: cout << "\nEnter the information for each Student.";
              for(i = 0; i < NUM_STUDENTS; i++)
                {
                  cout << "\nStudent " << i + 1 << " Name: ";
                  cin >> st[i].name;
                }

              for(i = 0; i < NUM_STUDENTS; i++)
                {
                  cout << "\nStudent " << i + 1 << " ID: ";
                  cin >> st[i].studentID;
                }

              for(i = 0; i < NUM_STUDENTS; i++)
                {
                  cout << "\nStudent " << i + 1 << " Birth Year: ";
                  cin >> st[i].birthYear;
                }

              for(i = 0; i < NUM_STUDENTS; i++)
                {
                  cout << "\nStudent " << i + 1 << " GPA: ";
                  cin >> st[i].gpa;
                }
                break;
        
        // To Display Info in formatted way
      case 2: cout << left << setw(10) << "Name"   
                   << setw(15)  << "Student ID"
                   << setw(15)  << "Birth Year"
                   << setw(10)  << "GPA"
                   << endl;
              cout << "----------"
                   << "----------"
                   << "----------"
                   << "-------------"
                   << endl;
              for(i = 0; i < NUM_STUDENTS; i++)
              {
              cout << left << setw(9) << st[i].name << " "
                   << setw(14) << st[i].studentID << " "
                   << setw(13) << st[i].birthYear << " "
                   << setw(10) <<  fixed << setprecision(2) << st[i].gpa << endl;
              }
              break;
        
        // returns to main then ends program if quit option chosen
      case 3: cout << "\nGoodbye." << endl;
              delete [] st;
              st = 0;
              return 0; 
      default: cout << "\nPlease enter a choice between 1-3." << endl;
    }
  } while (choice != 3); 

  // if quit is chosen after 1st loop, then will still delete dynamically allocated memory
  delete [] st;
  st = 0;

  return 0;
}

// Function to display UI menu
int menu()
{
  int choice;

    cout << "\nPlease select a choice: \n"
         << " 1. Input Student Info.\n"
         << " 2. Display Student Information.\n"
         << " 3. Quit.\n\n";
    cin >> choice;

  return choice;
}
