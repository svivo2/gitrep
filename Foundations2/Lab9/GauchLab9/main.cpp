//-----------------------------------------------------------
//  Purpose:    This program demonstrates how multiple queues
//              can be used to simulate customer arrivals.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "queue.h"

//-----------------------------------------------------------
// Main program uses the Queue class to simulate customers.
//-----------------------------------------------------------
int main()
{
   int i = 0;
   int NumLines = 5;
   int NumCustomers = 25;
   int CurrentTime = 0;
   int NumItems = 0;
   Queue *Vendor = new Queue[NumLines];

   // Add customers to different queues
   for (int Customer = 0; Customer < NumCustomers; Customer++)
   {
      // Generate customer data
      CurrentTime += 5 + random() % 20;
      NumItems = 1 + random() % 5;

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

      // Add customer to shortest line
      Vendor[ShortLine].Insert(NumItems);

      // Remove costumers
      if ((random() % 100) < 20)
      {
        Vendor[i++ % NumLines].Remove(NumItems);
      }
      // Print all customer lines
      for (int Line = 0; Line < NumLines; Line++)
      {
         cout << "Line: " << Line << " ";
         Vendor[Line].Print();
      }
      cout << "-----------------------------------------\n";

   }
   //Finish removing costumers
   while(!Vendor[NumLines-1].IsEmpty())
   {
     if ((random() % 100) < 20)
     {
       Vendor[i++ % NumLines].Remove(NumItems);
     }
     for (int Line = 0; Line < NumLines; Line++)
     {
        cout << "Line: " << Line << " ";
        Vendor[Line].Print();
     }
     cout << "-----------------------------------------\n";
   }
   cout << endl;
}
