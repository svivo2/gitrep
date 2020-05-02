//----------------------------------------------
// Purpose: Test student linked list
// Author:  John Gauch
//----------------------------------------------

#include "student_list.h"
#include <time.h>

//----------------------------------------------
int main()
{

  // Test the student list class
  StudentList list;
  list.insertHead("John", "Johnson, AR", 3.2);
  list.insertHead("Jack", "Jacksonville, AR", 3.4);
  list.insertHead("Sam", "Springdale, AR", 3.0);
  list.insertHead("Ben", "Bentonville, AR", 2.8);
  list.insertHead("Jill", "Jillandale, AR", 2.6);

  list.searchStudent("Ben");
  list.searchGPA(3.2);

}
