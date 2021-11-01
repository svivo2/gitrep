#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // Local variables
   float lat = 0;
   float lon = 0;
   int num = 0;
   string street = "";
   char ch = ' ';
   vector<string>street_vector;
   int count = 0;

   // Open input file
   ifstream din;
   din.open("input1.txt");

   // Loop reading address information
   while (din >> lat >> lon >> num)
   {
      // Skip space after num
      din.get(ch);

      // Read rest of line
      getline(din, street);

      // Add to end of street vector
      street_vector.push_back(street);

      // Print debug info
      cout << count << ","
           << lat << ","
           << lon << ","
           << num << ","
           << street << ",\n";
      count++;
      }

   cout << "vector size = " << street_vector.size() << endl;
   return 0;
}
