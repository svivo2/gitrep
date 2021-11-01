//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
typedef int DataType;

//----------------------------------------------
class Numbers
{
 public:
   // Constructors
   Numbers();
   ~Numbers();

   // Methods
   void readFile(string filename);
   DataType getCount();
   DataType getValue(int index);
   DataType findMin();
   DataType findMax();
   DataType findMean();
   DataType findVariance();
   DataType findStandardDeviation();

 private:
   static const int SIZE = 100;
   int Count;
   int Data[SIZE];
};
