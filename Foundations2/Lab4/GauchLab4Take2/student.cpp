//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "student.h"

//----------------------------------------------
StudentNode::StudentNode()
{
   Name = "";
   Address = "";
   GPA = 0;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(string name, string address, float gpa)
{
   Name = name;
   Address = address;
   GPA = gpa;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(const StudentNode & student)
{
   Name = student.Name;
   Address = student.Address;
   GPA = student.GPA;
   Next = student.Next;
}

//----------------------------------------------
StudentNode::~StudentNode()
{
}

//----------------------------------------------
string StudentNode::getName() const
{
   return Name;
}

//----------------------------------------------
string StudentNode::getAddress() const
{
   return Address;
}

//----------------------------------------------
float StudentNode::getGPA() const
{
   return GPA;
}

StudentNode * StudentNode::getNext() const
{
  return Next;
}

void StudentNode::setNext(StudentNode* node)
{
  Next = node;
}


//----------------------------------------------
void StudentNode::setName(string name)
{
   Name = name;
}

//----------------------------------------------
void StudentNode::setAddress(string address)
{
   Address = address;
}

//----------------------------------------------
void StudentNode::setGPA(float gpa)
{
   GPA = gpa;
}

//----------------------------------------------
void StudentNode::print() const
{
  cout << "\nName: " << Name << "\n"
      << "Address: " << Address << "\n" << "GPA: " << GPA << "\n";

  if (Next != NULL)
    Next->print();
}
