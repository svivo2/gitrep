//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "student.h"

//----------------------------------------------
int main()
{

  string name;
  string address;
  float gpa;
  StudentNode *head = NULL;
  for (int i=0; i<5; i++)
  {
     cout << "\nEnter name: ";
     cin >> name;
     cout << "\nEnter address: ";
     cin >> address;
     cout << "\nEnter GPA: ";
     cin >> gpa;

     StudentNode * tmp  = new StudentNode(name, address, gpa);
     tmp->setNext(head);
     head = tmp;

     tmp = NULL;
     delete tmp;

  }
  head->print();

  /*StudentNode *ptr1 = new StudentNode("John", "Johnson, AR", 2.5);
  StudentNode *ptr2 = new StudentNode("Fred", "Fayetteville, AR", 3.5);
  StudentNode *ptr3 = new StudentNode("Sam", "Springdale, AR", 2.9);
  StudentNode *ptr4 = new StudentNode("Jack", "Jacksonville, AR", 3.4);
  StudentNode *ptr5 = new StudentNode("Jill", "Jillandale, AR", 3.2);

  ptr1->setNext(ptr2);
  ptr2->setNext(ptr3);
  ptr1->print();

  ptr2->setNext(ptr1);
  ptr1->setNext(ptr3);
  ptr2->print();

  ptr3->setNext(ptr4);
  ptr4->setNext(ptr5);
  ptr2->print();

  float *ptr = new float;
  *ptr = 3.14159;
  cout << *ptr << endl;

  StudentNode *john = new StudentNode();
  john->setName("John");
  john->setAddress("Johnson, AR");
  john->setGPA(3.2);
  john->print();

  StudentNode *fred = new StudentNode();
  fred->setName("Fred");
  fred->setAddress("Fredville, AR");
  fred->setGPA(3.4);
  fred->print();

  // Test default constructor
  StudentNode john;
  cout << "\nprinting john object\n";
  john.print();

  // Test set methods
  john.setName("John");
  john.setAddress("Johnson, AR");
  john.setGPA(3.2);
  cout << "\nprinting john object\n";
  john.print();

  // Test constructor with parameters
  StudentNode fred("Fred", "Fayetteville, AR", 4.0);
  cout << "\nprinting fred object\n";
  fred.print();

  // Test copy constructor
  StudentNode bob(fred);
  cout << "\nprinting bob object\n";
  fred.print();

  // Testing array of objects
  StudentNode list[10];
  for (int i = 0; i < 3; i++)
  {
    cout << "\nprinting object " << i << "\n";
    list[i].setName("name tba");
    list[i].setAddress("address tba");
    list[i].setGPA(i + 1);
    list[i].print();
  }*/
}
