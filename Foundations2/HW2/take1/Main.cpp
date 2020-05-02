#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  string filename = "guests.txt";
  ifstream din(filename.c_str());

  int boneWait;
  int noFunWait;
  bool enqueue;

  for(int t = 1; t < 35; t++)
  {
    boneWait = 10 - (t % 10);
    noFunWait = 7 - (t % 7);


    cout << "boneWait: " << boneWait << endl;
    cout << "noFunWait: " << noFunWait << endl;

  }
}
