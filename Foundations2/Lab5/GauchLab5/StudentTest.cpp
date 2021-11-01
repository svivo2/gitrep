//----------------------------------------------
// Purpose: Test student linked list
// Author:  John Gauch
//----------------------------------------------
#include <time.h>
#include "StudentList.h"

//----------------------------------------------
int main()
{
  // Test the student list class
  StudentList list;

  // Get start time
  clock_t time1=clock();

  list.insertHead("John", "Johnson, AR", 3.2);
  list.insertHead("Will", "Fayetteville, AR", 3.0);
  list.insertHead("Dave", "Springdale, AR", 3.4);
  list.insertHead("Adam", "Rogers, AR", 3.6);
  list.insertHead("Bob", "Bentonville, AR", 3.8);

  StudentNode * Name = list.searchName("Bob");
  StudentNode * GPA = list.searchGPA(3.4);

  // Get end time
  clock_t time2=clock();
  double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
  list.print();
  cout << "Run time: " << run_time << " seconds\n";
  Name->print();
  GPA->print();
}