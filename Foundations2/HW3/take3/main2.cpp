#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "address.h"
using namespace std;

const float LAT_LOW = 36.03;
const float LAT_HIGH = 36.13;
const float LON_LOW = -94.10;
const float LON_HIGH = -94.20;

bool search(const vector<Address> & addressVector, const float & lat, const float & lon, const float & r)
{
  int low = 0;
  int high = addressVector.size() - 1;
  int mid = (low + high)/2;
  bool found = false;
  while(low <= high)
  {
    mid = (low + high)/2;
    cout << "Low: " << low << endl << "Mid: " << mid << endl
         << "High: " << high << endl << "tLat " << lat << endl;
    if (addressVector[mid].getLat() == lat)
    {
      for(int i = mid; addressVector[i].getLat() == lat;i++)
      {
        if (addressVector[i].getLon() == lon)
          addressVector[i].print();
      }
      for(int i = mid - 1; (addressVector[i].getLat() == lat);i--)
      {
        if (addressVector[i].getLon() == lon)
          addressVector[i].print();
      }
      high = -1;
      found = true;
    }
    else if ((addressVector[mid].getLat() > lat))
      high = mid - 1;
    else
      low = mid + 1;

  //addressVector[mid].print();
  }
  return found;
}

int main()
{
  // Open input file
  ifstream din;
  din.open("streets.txt");

  // Open output file
  ofstream dout;
  dout.open("input1.txt");

  // Create random addresses
  string street;
  while (getline(din, street))
  {
    int number = 1 + rand() % 50;
    float lat = LAT_LOW + (LAT_HIGH-LAT_LOW)*(rand()%1000)/1000;
    float lon = LON_LOW + (LON_HIGH-LON_LOW)*(rand()%1000)/1000;

    int count = 1 + rand() % 30;
    for (int i=0; i<count; i++)
    {
      dout << lat << " " << lon << " " <<
           number << " " << street << endl;

      number += 1 + rand() % 10;
      if (count % 2 == 0)
        lat += 0.0001 * (1 + rand() % 10);
      else
        lon += 0.0001 * (1 + rand() % 10);
    }
  }

  // Close files
  din.close();
  dout.close();

  // Sort input1.txt to create input2.txt
  system("sort -n -k2 input1.txt | sort -n -k1 > input2.txt");

  // Local variables
  float lat, tLat = 0;
  float lon, tLon = 0;
  int num = 0;
  char ch = ' ';
  char choice = '\0';
  Address address;
  vector<Address>addressVector;

  //int count = 0;

  // Open input file
  ifstream fin;
  fin.open("input2.txt");

  // Loop reafing address information
  while (fin >> lat >> lon >> num)
  {
     // Skip space after num
     fin.get(ch);

     // Read rest of line
     getline(fin, street);

     address.setLon(lon);
     address.setLat(lat);
     address.setNum(num);
     address.setStreet(street);

     // Add to end of street vector
     addressVector.push_back(address);

     addressVector[addressVector.size() - 1].print();
   }

   while(choice != 'q')
   {
     cout << "Enter \"s\" to search address and \"q\" to quit: ";
     cin >> choice;

     if (choice == 's')
     {
       //cout << "Please enter the latitude number, followed by a space, followed by the longitude number: ";
       //cin >> tLat;
       //cin >> tLon;
       search(addressVector, 36.1079, -94.1533, 0.001);
     }
   }



  return 0;
}
