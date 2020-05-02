#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int count, n, m, f = 0;
  char c = '\0';

  do{
    cin >> n >> m;

    char field[1000][1000] = {{'\0'},{'\0'}};
    for (int i = 0; i < n; i++)
    {
      cin.get(c);
      for (int j = 0; j < m; j++)
      {
        cin.get(c);
        field[i][j] = c;
      }
    }
    if((n + m) != 0)
      cout << "\nField #" << ++f << ":\n";
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if (field[i][j] == '*')
          cout << field[i][j];
        else
        {
          count = 0;
          for(int k = i - 1; k <= (i + 1); k++)
          {
            for(int l = j - 1; l <= (j + 1); l++)
            {
              if((k >= 0)&&(k < n)&&(l >= 0)&&(l < m))
              {
                if (field[k][l] == '*')
                  count++;
              }
            }
          }
          cout << count;
        }
      }
      cout << endl;
    }
  }while ((n + m) != 0);
}
