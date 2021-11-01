//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include <iostream>
using namespace std;

class StudentNode
{
 public:
   // Constructors
   StudentNode();
   StudentNode(string name, string address, float gpa);
   StudentNode(const StudentNode & student);
   ~StudentNode();

   // Methods
   string getName() const;
   string getAddress() const;
   float getGPA() const;
   StudentNode* getNext() const;
   void setNext(StudentNode * node);
   void setName(string name);
   void setAddress(string address);
   void setGPA(float gpa);
   void print() const;

 private:
   string Name;
   string Address;
   float GPA;
   StudentNode *Next;
};
