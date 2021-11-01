//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include "numbers.h"

//----------------------------------------------
int main()
{
   Numbers num;
   string filename;

   cout << "Enter filename: ";
   cin >> filename;
   num.readFile(filename);

   cout << "data = ";
   for (int index = 0; index < num.getCount(); index++)
      cout << num.getValue(index) << " ";
   cout << endl;

   int min = num.findMin();
   cout << "min = " << min << endl;

   int max = num.findMax();
   cout << "max = " << max << endl;

   DataType mean = num.findMean();
   cout << "mean = " << mean << endl;

   DataType variance = num.findVariance();
   cout << "variance = " << variance << endl;

   DataType standardDeviation = num.findStandardDeviation();
   cout << "standard deviation = " << standardDeviation << endl;
}
