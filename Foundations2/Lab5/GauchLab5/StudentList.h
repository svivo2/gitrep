//-----------------------------------------------------------
//  Purpose:    Header file for the StudentList class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include "StudentNode.h"
#include <time.h>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Define the StudentList class interface
//-----------------------------------------------------------
class StudentList
{
 public:
   // Constructors
   StudentList();
   StudentList(const StudentList & list);
    ~StudentList();

   // Methods
   void insertHead(string name, string address, float gpa);
   void insertTail(string name, string address, float gpa);
   StudentNode * searchName(const string name);
   StudentNode * searchGPA(const float gpa);
   void print() const;

 private:
     StudentNode * Head;
};