#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char num[9];
  int i = 0;
  cout << "Input Size and Integer: \n";
  cin >> s;

  cin.get(c);

  for (int i = 0; c != NULL; i++)
  {
    cin.get(c);
    switch (c)
    {
      case '1':
        {
          for(int i = 0; i < (2s + 3); i++)
          {
            for (int j = 0; j < (s + 2); j++)
            {
              if ((i == 0)||(i == (2s + 2))||(i == ((2s + 3)/2)))
                cout << " ";
            }
            cout << endl;
          }
        }
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      default:


    }
  }



}
