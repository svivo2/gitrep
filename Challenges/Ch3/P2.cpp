#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream din;
  din.open("P2.txt");

  int numCases, n, m, numWords, x, y = 0;
  string s = "\0";
  char c = '\0';

  din >> numCases;
  while(numCases-- > 0)
  {
    getline(din,s);
    din >> n >> m;
    cout << n << " " << m << endl;
    char grid[50][50] = {{'\0'},{'\0'}};
    for(int i = 0; i < n; i++)
    {
      din.get(c);
      for(int j = 0; j < m; j++)
      {
        din.get(c);
        grid[i][j] = c;
        cout << grid[i][j];
      }
      cout << endl;
    }
    din >> numWords;
    cout << numWords << endl;
    while(numWords-- > 0)
    {
      din >> s;
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
        {
          if(grid[i][j] == s[0])
          {
            if(s.length() == 1)
              cout << i << " " << j << endl;
            else
            {
              int l = 2;
              if(grid[i - 1][j] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i - k][j] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i - k][j] << " == " << s[l - 1] << endl;
                }
              }
              if(grid[i][j - 1] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i][j - k] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i][j - k] << " == " << s[l - 1] << endl;
                }
              }
              if(grid[i - 1][j - 1] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i - k][j - k] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i - k][j - k] << " == " << s[l - 1] << endl;
                }
              }
              if(grid[i][j + 1] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i][j + k] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i][j + k] << " == " << s[l - 1] << endl;
                }
              }
              if(grid[i + 1][j] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i + k][j] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i + k][j] << " == " << s[l - 1] << endl;
                }
              }
              if(grid[i + 1][j + 1] == s[1])
              {
                for(int k = 1; k < s.length(); k++)
                {
                  if (grid[i + k][j + k] != s[l++])
                    //cout << "Not Here.\n";
                  else
                    //cout << grid[i + k][j - k] << " == " << s[l - 1] << endl;
                }
              }
            }
            cout << i << " " << j << endl;
          }
        }
      }


      cout << endl;
    }
  }
}
