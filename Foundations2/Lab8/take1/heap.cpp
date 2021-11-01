//------------------------------------------------------------
// Purpose: Implementation of integer Heap class.
// Author:  John Gauch
//------------------------------------------------------------
#include "heap.h"

//------------------------------------------------------------
// Constructor function.
//------------------------------------------------------------
Heap::Heap()
{
   Count = 0;
   for (int index = 0; index <= MAX_HEAP_SIZE; index++)
      heap[index] = -1;
}

//------------------------------------------------------------
// Destructor function.
//------------------------------------------------------------
Heap::~Heap()
{
}

//------------------------------------------------------------
// Insert an element into the heap.
//------------------------------------------------------------
bool Heap::Insert(int num)
{
   // Check for full heap
   if (IsFull())
      return false;

   // Shuffle data up the heap
   Count++;
   int child = Count;
   int parent = child / 2;
   while ((child > 1) && (heap[parent] < num))
   {
      heap[child] = heap[parent];
      child = parent;
      parent = child / 2;
   }

   // Insert new entry in heap
   heap[child] = num;
   return true;
}

//------------------------------------------------------------
// Remove an element from the heap.
//------------------------------------------------------------
bool Heap::Remove(int &num)
{
   // Check for empty heap
   if (IsEmpty())
      return false;

   // Save top of heap
   num = heap[1];

   // Swap last value into root position
   heap[1] = heap[Count];
   heap[Count] = -1;
   Count--;

   // Shuffle data down the heap
   int parent = 1;
   int largest = 0;
   while (parent != largest)
   {
      // Check left node
      largest = parent;
      int left = parent * 2;
      if ((left <= Count) && (heap[left] > heap[largest]))
	 largest = left;

      // Check right node
      int right = left + 1;
      if ((right <= Count) && (heap[right] > heap[largest]))
	 largest = right;

      // Swap data values if needed
      if (parent != largest)
      {
	 int temp = heap[parent];
	 heap[parent] = heap[largest];
	 heap[largest] = temp;
	 parent = largest;
	 largest = 0;
      }
   }
   return true;
}

//------------------------------------------------------------
// Print the contents of the heap.
//------------------------------------------------------------
void Heap::Print()
{
   for (int index = 1; index <= Count; index++)
      cout << -1 * heap[index] << " ";
   cout << endl;
}

//------------------------------------------------------------
// Check if the heap is empty
//------------------------------------------------------------
bool Heap::IsEmpty()
{
   return Count == 0;
}

//------------------------------------------------------------
// Check if the heap is full
//------------------------------------------------------------
bool Heap::IsFull()
{
   return (Count == MAX_HEAP_SIZE);
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
   Heap heap;
   int n = 0;
   int num = 0;
   cout << "Enter an integer between 0 - 25: ";
   cin >> n;

   for(int i = 0; i < n; i++)
   {
     int val = -1 * (rand() % n);
     heap.Insert(val);
     heap.Print();
   }

   while(!heap.IsEmpty())
   {
     heap.Remove(num);
     cout << "Number removed: " << -1 * num << endl;
     heap.Print();
   }
}
