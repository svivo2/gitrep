#include "Student.h"

Student::Student()
{
  cout << "In constructor\n";
}

Student::Student(const Student & student)
{
  cout << "In copy constructor\n";
}

Student::~Student()
{
  cout << "In destructor\n";
}
