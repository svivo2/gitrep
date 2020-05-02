#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string a, b = "\0";

  while(getline(cin,a) && getline(cin,b) && !a.empty() && !b.empty())
  {
    for(int i = 0; i < a.length(); i++)
    {
      char c = '\0';
      for(int j = 0; j < b.length(); j++)
      {
        if(a[i] == b[j])
        {
          c = b[j];
          b[j] = '\0';
          break;
        }
      }
      cout << c;
    }
    cout << endl;
  }
}
