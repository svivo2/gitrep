#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream din;
  din.open("P2.txt");
  int cake = 0;
  char c = '\0';
  while(!din.eof())
  {
    int * stack = new int[30];
    int max = 0;
    int maxPos = 0;
    int size = 0;
    //cout << "0: \n";
    for(int i  = 0; din >> cake; i++)
    {
      stack[i] = cake;
      cout << stack[i] << " ";
      din.get(c);
      size++;

      if(stack[i] > max)
      {
        max = stack[i];
        maxPos = i;
      }

      if (c == '\n')
        break;

    }
    cout << endl;
    //cout << "\nS: " << size << ", M0: " << max;
    //cout << ", MP0: " << maxPos << endl;

    for (int s = size - 1; s > 0; s-- )
    {
      if(stack[s] < max)
      {
        max = 0;
        maxPos = s;
        //cout << "MaxPos1: " << maxPos << endl;
        for(int i = 0; i <= s; i++)
        {
          if(stack[i] > max)
          {
            max = stack[i];
            maxPos = i;
          }
        }
        //cout << "\nS: " << s  << ", s[s]: " << stack[s];
        //cout << ", M1: " << max << ", MP2: " << maxPos << endl;
        if(maxPos == 0)
        {
          maxPos = s;
          cout << size - maxPos << " ";
          for(int i = 0; maxPos-- > i; i++)
          {
            int temp = stack[maxPos + 1];
            stack[maxPos + 1] = stack[i];
            stack[i] = temp;
          }
        }
        else if (maxPos != s)
        {
          cout << size - maxPos << " ";
          for(int i = 0; maxPos-- > i; i++)
          {
            int temp = stack[maxPos + 1];
            stack[maxPos + 1] = stack[i];
            stack[i] = temp;
          }
          //cout << "1: \n";
          //for(int i = 0; i < size; i++)
            //cout << stack[i] << " ";

          //cout << endl;
          //cout << "\nMaxPos3(-1): " << maxPos << endl;
          maxPos = s;
          //cout << "MaxPos4: " << maxPos << endl;
          cout << size - maxPos << " ";
          for(int i = 0; maxPos-- > i; i++)
          {
            int temp = stack[maxPos + 1];
            stack[maxPos + 1] = stack[i];
            stack[i] = temp;
          }
          //cout << "2: \n";
          //for(int i = 0; i < size; i++)
            //cout << stack[i] << " ";

          //cout << endl;
          //cout << "\nMaxPos5(-1): " << maxPos << endl;
          //cout << stack[s] << " ";
        }
      }
    }
    cout << "0\n";
    // for(int i = 0; i < size; i++)
    //   cout << stack[i] << " ";
    //
    // cout << endl;
    delete[] stack;
    stack = NULL;
  }
}
