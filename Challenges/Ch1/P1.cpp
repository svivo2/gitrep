#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int num1, num2, c, max, temp, count = 0;

  while((cin >> num1 >> num2)&&(num1 > 0)&&( num2 > 0))
  {
    max = 0;
    cout << num1 << " " << num2 << " " ;
    if(num2 < num1)
    {
      temp = num1;
      num1 = num2;
      num2 = temp;
    }
    for (int j = num1; j <= num2; j++)
    {
      int i = j;
      for (c = 1; i != 1; c++)
      {
        if ((i % 2) != 0)
          i = (i * 3) + 1;
        else
          i = i / 2;
      }
      if (c > max)
      {
        max = c;
      }
    }
    //cout << count++ << " ";
    cout << max++ << endl;
  }
}
