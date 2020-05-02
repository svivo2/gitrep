//------------------------------------------------------------
// Purpose: Header file for the Heap class.
// Author:  John Gauch
//------------------------------------------------------------
#include <iostream>
using namespace std;

//------------------------------------------------------------
// The Heap class definition for a heap of integers
//------------------------------------------------------------
#define MAX_HEAP_SIZE 50
class Heap
{
 public:
   // Constructor functions
   Heap();
   Heap(int MaxSize);
   ~Heap();

   // General heap operation
   bool Insert(int num);
   bool Remove(int &num);
   bool IsEmpty();
   bool IsFull();
   void Print();

 private:
   int Count;
   int * heap;
};
