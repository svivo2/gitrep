//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include "Numbers.cpp"

int main()
{
   string filename;
   cout << "Enter filename:";
   cin >> filename;

   // Process int numbers
   Numbers <short> num;
   num.readFile(filename);
   cout << "min = " << num.findMin() << endl;
   cout << "max = " << num.findMax() << endl;
   cout << "mean = " << num.findMean() << endl;

   // Process float numbers
   Numbers <long> num2;
   num2.readFile(filename);
   cout << "min = " << num2.findMin() << endl;
   cout << "max = " << num2.findMax() << endl;
   cout << "mean = " << num2.findMean() << endl;
}