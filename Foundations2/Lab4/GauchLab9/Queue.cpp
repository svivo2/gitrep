//-----------------------------------------------------------
//  Purpose:    Implementation of Queue class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "Queue.h"

//-----------------------------------------------------------
Queue::Queue()
{
   End = -1;
   for (int i = 0; i < QUEUE_SIZE; i++)
      Data[i] = -1;
}

//-----------------------------------------------------------
Queue::~Queue()
{
}

//-----------------------------------------------------------
bool Queue::IsFull()
{
   return (End >= QUEUE_SIZE-1);
}

//-----------------------------------------------------------
bool Queue::IsEmpty()
{
   return (End < 0);
}

//-----------------------------------------------------------
void Queue::Insert(int item)
{
   // check if full
   if (IsFull())
      cout << "queue overflow\n";

   else
      // insert data
      Data[++End] = item;
}

//-----------------------------------------------------------
void Queue::Remove(int &item)
{
   // check if empty
   if (IsEmpty())
      cout << "queue underflow\n";

   else
   {
      // remove data
      item = Data[0];

      // shift data
      for (int i = 0; i < End; i++)
         Data[i] = Data[i + 1];
      Data[End--] = -1;
   }
}

//-----------------------------------------------------------
int Queue::Remove()
{
   int item;
   Remove(item);
   return item;
}

int Queue::GetLength()
{
   return (End+1);
}

//-----------------------------------------------------------
void Queue::Print()
{
   cout << End + 1 << " : ";
   for (int i = 0; i <= End; i++)
      cout << setw(2) << Data[i] << " ";
   cout << endl;
}

//-----------------------------------------------------------
//  Purpose:    This program demonstrates how multiple queues
//              can be used to simulate customer arrivals.
//  Author:     John Gauch
//-----------------------------------------------------------
//-----------------------------------------------------------
// Main program uses the Queue class to simulate customers.
//-----------------------------------------------------------
int main()
{
   int NumLines = 2;
   int NumCustomers = 15;
   int CurrentTime = 0;
   int ShortLine=0;
   int NumItems=0;
   Queue *Vendor = new Queue[NumLines];

   // Add customers to different queues
   for (int Customer = 0; Customer < NumCustomers; Customer++)
   {
      // Generate customer data
      CurrentTime += 5 + random() % 20;
      int NumItems = 1 + random() % 5;

      // Search for shortest queue
      int ShortLine = 0;
      int ShortLength = Vendor[0].GetLength();
      for (int Line = 1; Line < NumLines; Line++)
      {
        int Length = Vendor[Line].GetLength();
        if (Length < ShortLength)
        {
           ShortLine = Line;
           ShortLength = Length;
        }
      }
      for (int Line = 0; Line < NumLines; Line++)
   {
      Vendor[ShortLine].Insert(NumItems);
      cout << "Line " << Line << " ";
      Vendor[Line].Print();
   }
   cout << endl;
   }

   // Print all customer lines
   for (int Line = 0; Line < NumLines; Line++)
   {
      Vendor[ShortLine].Insert(NumItems);
      cout << "Line " << Line << " ";
      Vendor[Line].Print();
   }
   cout << endl;
}
