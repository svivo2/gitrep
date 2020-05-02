//-----------------------------------------------------------
//  Purpose:    Header file for the Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
using namespace std;

// Stack data node definition
class StackNode
{
   public:
   int Number;
   StackNode *Next;
};

class Stack
{
   public:
      // constructor functions
      Stack();
      ~Stack();

      // general stack operations
      void Push(int Number);
      void Pop(int &Number);
      void Top(int &Number);
      bool IsFull();
      bool IsEmpty();
      void Print();

   private:
      StackNode *Head;
      int Length;
};
