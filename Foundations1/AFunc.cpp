#include <cstdlib>
#include <iostream>
using namespace std;

void init_array(int array[], int size, int range)
{
   for (int index = 0; index < size; index++)
      array[index] = random() % range;
}

void print_array(int array[], int size)
{
   for (int index = 0; index < size; index++)
      cout << array[index] << " ";
   cout << endl;
}

int find_max(int array[], int size)
{
   int max = array[0];
   for (int index = 0; index < size; index++)
   {
      if (array[index] > max)
         max = array[index];
   }
   return max;
}

int find_min(int array[], int size)
{
   int min = array[0];
   for (int index = 0; index < size; index++)
   {
      if (array[index] < min)
         min = array[index];
   }
   return min;
}

int main()
{
   // Declare array of integers
   const int DATA_SIZE = 20;
   int data[DATA_SIZE] = {0};
   int max = 0;
   int min = 99;

   // Initialize and print array
   init_array(data, DATA_SIZE, 100);
   print_array(data, DATA_SIZE);
   max = find_max(data,DATA_SIZE);
   min = find_min(data, DATA_SIZE);
   cout << "max = " << max << endl;
   cout << "min = " << min << endl;

   return 0 ;
}