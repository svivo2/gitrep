#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int testCases, numDays, numParties, hartal, count, countDays = 0;
  cin >> testCases;
  while (testCases-- > 0)
  {
    cin >> numDays;
    cin >> numParties;
    int *days = new int[numDays];
    count = 0;
    countDays = 0;
    for(int i = 0; i < numParties; i++)
    {
      cin >> hartal;
      for(int j = hartal; j <= numDays; j = j + hartal)
      {
        if(((j % 7) != 6) && ((j % 7) != 0))
        {
          if(days[j] != -1)
          {
            count++;
            days[j] = -1;
          }
        }
      }
    }
    cout << count << endl;
  }
}
