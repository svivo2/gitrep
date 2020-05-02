#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
   int T = 0;
   // Declare array of integers
   const int DATA_SIZE = 20;
   int data[DATA_SIZE] = {0};

      // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   // Initialize array
   for (int index = 0; index < DATA_SIZE; index++)
      data[index] = random() % 100;

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   // Reverse array
   for (int index = 0; index < DATA_SIZE/2; index++)
   {
      T = data[index];
      data[index] = data[DATA_SIZE-1-index];
      data[DATA_SIZE-1-index] = T;

   }

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   return 0 ;
}
