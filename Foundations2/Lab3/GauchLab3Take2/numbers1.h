//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

//----------------------------------------------
class Numbers
{
 public:
   // Constructors
   Numbers();
   ~Numbers();

   // Methods
   void readFile(string filename);
   int getCount();
   int getValue(int index);
   int findMin();
   int findMax();
   int findMean();
   int findVariance();
   int findStandardDeviation();

 private:
   static const int SIZE = 100;
   int Count;
   int Data[SIZE];
};
