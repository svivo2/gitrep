//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include "numbers.cpp"

//----------------------------------------------
int main()
{
   string filename;

   cout << "Enter filename: ";
   cin >> filename;

   // Process int numbers
   cout << "\nProcesing int numbers\n";
   Numbers <int> num;
   num.readFile(filename);
   cout << "min = " << num.findMin() << endl;
   cout << "max = " << num.findMax() << endl;
   cout << "mean = " << num.findMean() << endl;
   cout << "variance = " << num.findVariance() << endl;
   cout << "standard deviation = " << num.findStandardDeviation() << endl;

   // Process float numbers
   cout << "\nProcesing float numbers\n";
   Numbers <float> num2;
   num2.readFile(filename);
   cout << "min = " << num2.findMin() << endl;
   cout << "max = " << num2.findMax() << endl;
   cout << "mean = " << num2.findMean() << endl;
   cout << "variance = " << num2.findVariance() << endl;
   cout << "standard deviation = " << num2.findStandardDeviation() << endl;

   // Process double numbers
   cout << "\nProcesing double numbers\n";
   Numbers <double> num3;
   num3.readFile(filename);
   cout << "min = " << num3.findMin() << endl;
   cout << "max = " << num3.findMax() << endl;
   cout << "mean = " << num3.findMean() << endl;
   cout << "variance = " << num3.findVariance() << endl;
   cout << "standard deviation = " << num3.findStandardDeviation() << endl;

   // Process long numbers
   cout << "\nProcesing long numbers\n";
   Numbers <long> num4;
   num4.readFile(filename);
   cout << "min = " << num4.findMin() << endl;
   cout << "max = " << num4.findMax() << endl;
   cout << "mean = " << num4.findMean() << endl;
   cout << "variance = " << num4.findVariance() << endl;
   cout << "standard deviation = " << num4.findStandardDeviation() << endl;

   // Process short numbers
   cout << "\nProcesing short numbers\n";
   Numbers <short> num5;
   num5.readFile(filename);
   cout << "min = " << num5.findMin() << endl;
   cout << "max = " << num5.findMax() << endl;
   cout << "mean = " << num5.findMean() << endl;
   cout << "variance = " << num5.findVariance() << endl;
   cout << "standard deviation = " << num5.findStandardDeviation() << endl;

   // Process char numbers
   cout << "\nProcesing char numbers\n";
   Numbers <char> num6;
   num6.readFile(filename);
   cout << "min = " << num6.findMin() << endl;
   cout << "max = " << num6.findMax() << endl;
   cout << "mean = " << num6.findMean() << endl;
   cout << "variance = " << num6.findVariance() << endl;
   cout << "standard deviation = " << num6.findStandardDeviation() << endl;

}
