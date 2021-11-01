#include <fstream>
#include <iostream>
#include <vector>
#include "address.h"
using namespace std;

void search(const vector<Address> & addressVector, const int & num, const string & street,const int & low, const int & high)
{
  // Calculate midpoint index
  int mid = (low + high) / 2;
  //cout << "Low: "<< low << endl
  //    << "Mid: " << mid << endl
  //    << "High: " << high << endl
  //    << "Num: " << addressVector[mid].getNum() << endl
  //    << "Street: " << addressVector[mid].getStreet() << endl;

  // Check termination condition
  if (low > high)
    cout << "Address was not found\n";

  // Check if value is found
  else if ((addressVector[mid].getStreet() == street) && (addressVector[mid].getNum() == num))
    addressVector[mid].print();

  // Search up
  else if (addressVector[mid].getStreet() > street)
    return search(addressVector, num, street, low, mid -1);

  //search down
  else if (addressVector[mid].getStreet() < street)
    return search(addressVector, num, street, mid + 1, high);

  //Search up
  else if (addressVector[mid].getNum() > num)
    return search(addressVector, num, street, low, mid - 1);

  // Search down
  else
    return search(addressVector, num, street, mid + 1, high);
}

int main()
{
   // Local variables
   float lat = 0;
   float lon = 0;
   int num, tNum = 0;
   string street, tStreet = "";
   char ch = ' ';
   char choice = '\0';
   Address address;
   vector<Address>addressVector;
   //int count = 0;

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

      address.setLon(lon);
      address.setLat(lat);
      address.setNum(num);
      address.setStreet(street);

      // Add to end of street vector
      addressVector.push_back(address);

    }

    while(choice != 'q')
    {
      cout << "Enter \"s\" to search address and \"q\" to quit: ";
      cin >> choice;

      if (choice == 's')
      {
        cout << "Please enter the house number, followed by a space, followed by the street name: ";
        cin >> tNum;
        cin.get(ch);
        getline(cin, tStreet);
        search(addressVector, tNum, tStreet, 0, addressVector.size()-1);
      }
    }



   return 0;
}
