//----------------------------------------------
// Purpose: Implement student linked list
// Author:  John Gauch
//----------------------------------------------

#include "student_list.h"

//----------------------------------------------
StudentList::StudentList()
{
   Head = NULL;
}

//----------------------------------------------
StudentList::StudentList(const StudentList & list)
{
   // Create first node
   StudentNode *copy = new StudentNode();
   Head = copy;

   // Walk list to copy nodes
   StudentNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->setNext(new StudentNode());
      copy = copy->getNext();
      copy->setName(ptr->getName());
      copy->setAddress(ptr->getAddress());
      copy->setGPA(ptr->getGPA());
      copy->setNext(NULL);
      ptr = ptr->getNext();
   }

   // Tidy first node
   copy = Head;
   Head = copy->getNext();
   delete copy;
}

//----------------------------------------------
StudentList::~StudentList()
{
}

//----------------------------------------------
void StudentList::insertHead(string name, string address, float gpa)
{
   // Insert new node
   StudentNode *ptr = new StudentNode(name, address, gpa);
   ptr->setNext(Head);
   Head = ptr;
}

//----------------------------------------------
void StudentList::insertTail(string name, string address, float gpa)
{
   // Find tail node
   StudentNode *ptr = Head;
   while ((ptr != NULL) && (ptr->getNext() != NULL))
      ptr = ptr->getNext();

   // Insert new node
   if (ptr != NULL)
      ptr->setNext(new StudentNode(name, address, gpa));
   else
      Head = new StudentNode(name, address, gpa);

}

//----------------------------------------------
StudentNode * StudentList::searchStudent(const string & name)
{
  // Find node
  StudentNode *ptr = Head;
  while ((ptr != NULL) && (ptr->getNext() != NULL) && (ptr->getName() != name))
     ptr = ptr->getNext();

  if (ptr == NULL)
  {
    cout << "\nThere are no records matching this name\n";
    return ptr;
  }
  else
  {
    ptr->print();
    return ptr;
  }
}

//----------------------------------------------
StudentNode* StudentList::searchGPA(const float & gpa)
{
  // Find node
  StudentNode *ptr = Head;
  while ((ptr != NULL) && (ptr->getNext() != NULL) && (ptr->getGPA() < gpa))
     ptr = ptr->getNext();

  if (ptr == NULL)
  {
    cout << "\nThere are no records matching this gpa\n";
    return ptr;
  }
  else
  {
    ptr->print();
    return ptr;
  }
}

//----------------------------------------------
void StudentList::print() const
{
   StudentNode *ptr = Head;
   while (ptr != NULL)
   {
      ptr->print();
      ptr = ptr->getNext();
   }
}
