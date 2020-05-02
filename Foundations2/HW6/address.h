#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Address
{
public:
  Address();
  Address(const Address & address);
  Address(const float & lat, const float & lon, const int & num, const string & street);
  ~Address();

  //getters
  float getLat() const;
  float getLon() const;
  int getNum() const;
  string getStreet() const;

  //setter
  void setLat(const float & lat);
  void setLon(const float & lon);
  void setNum(const int & num);
  void setStreet(const string & street);

  //print
  void print() const;

private:
  float mLat;
  float mLon;
  int mNum;
  string mStreet;
};
