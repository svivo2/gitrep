#include "address.h"

Address::Address()
{
  mLat = 0;
  mLon = 0;
  mNum = 0;
  mStreet = "";
}

Address::Address(const Address & address)
{
  mLat = address.mLat;
  mLon = address.mLon;
  mNum = address.mNum;
  mStreet  = address.mStreet;
}

Address::Address(const float & lat, const float & lon, const int & num, const string & street)
{
  mLat = lat;
  mLon = lon;
  mNum = num;
  mStreet = street;
}

Address::~Address(){}

//getters
float Address::getLon() const
{
  return mLon;
}

float Address::getLat() const
{
  return mLat;
}

int Address::getNum() const
{
  return mNum;
}

string Address::getStreet() const
{
  return mStreet;
}

void Address::setLat(const float & lat)
{
  mLat = lat;
}

void Address::setLon(const float & lon)
{
  mLon = lon;
}

void Address::setNum(const int & num)
{
  mNum = num;
}

void Address::setStreet(const string & street)
{
  mStreet = street;
}

//print
void Address::print() const
{
  cout << "Lat: " << mLat << endl
       << "Lon: " << mLon << endl
       << "Num: " << mNum << endl
       << "Street: " << mStreet << endl;
}
