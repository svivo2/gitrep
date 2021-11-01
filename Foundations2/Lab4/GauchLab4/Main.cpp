//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "StudentNode.h"

//----------------------------------------------
int main()
{
   StudentNode *ptr1 = new StudentNode("John", "Johnson, AR", 2.5);
   StudentNode *ptr2 = new StudentNode("Fred", "Fayetteville, AR", 3.5);
   StudentNode *ptr3 = new StudentNode("Sam", "Springdale, AR", 2.9);
   StudentNode *ptr4 = new StudentNode("Dave", "Bentonville, AR", 4.0);
   StudentNode *ptr5 = new StudentNode("Bob", "Rogers, AR", 3.7);

   ptr5->setNext(ptr4);
   ptr4->setNext(ptr3);
   ptr3->setNext(ptr2);
   ptr2->setNext(ptr1);
   ptr5->print();
}