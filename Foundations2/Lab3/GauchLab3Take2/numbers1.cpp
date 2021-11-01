//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include "numbers.h"

//----------------------------------------------
Numbers::Numbers()
{
   // Initialize variables
   Count = 0;
   for (int i = 0; i < SIZE; i++)
      Data[i] = 0;
}

//----------------------------------------------
Numbers::~Numbers()
{
}

//----------------------------------------------
void Numbers::readFile(string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail())
      return;

   // Read integers into Data array
   Count = 0;
   int num;
   din >> num;
   while (!din.eof() && Count < SIZE)
   {
      Data[Count++] = num;
      din >> num;
   }
   din.close();
}

//----------------------------------------------
int Numbers::getCount()
{
   return Count;
}

//----------------------------------------------
int Numbers::getValue(int index)
{
   // Return specified value
   if ((index >= 0) && (index < Count))
      return Data[index];
   else
      return 0;
}

//----------------------------------------------
int Numbers::findMin()
{
   // Search array for min
   int min = Data[0];
   for (int index = 0; index < Count; index++)
      if (min > Data[index])
	 min = Data[index];
   return min;
}

//----------------------------------------------
int Numbers::findMax()
{
   // Search array for max
   int max = Data[0];
   for (int index = 0; index < Count; index++)
      if (max < Data[index])
	 max = Data[index];
   return max;
}

//----------------------------------------------
int Numbers::findMean()
{
   // Calculate mean value of array
   int total = 0;
   for (int index = 0; index < Count; index++)
      total += Data[index];
   if (Count > 0)
      return total / Count;
   else
      return 0;
}

int Numbers::findVariance()
{
  cout << "\nIn findVariance method\n";
  int total = 0;
  int mean, sum = 0;
  for (int index = 0; index < Count; index++)
     total += Data[index];
  if (Count > 0)
     mean = total / Count;
  else
     cout << "\nNo data available to compute variance\n";

  for (int index = 0; index < Count; index++)
    sum += (Data[index] - mean) * (Data[index] - mean);
  if (Count > 0)
    return sum / Count;
  else
    return 0;
}

int Numbers::findStandardDeviation()
{
  cout << "\nIn findStandardDeviation method\n";
  return pow(findVariance(),0.5);
}
