#include<iostream>

using namespace std;

int main()
{
  for (int i = 0; i < 5; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << rand() % 70 << ", ";
    }
    cout << rand() % 20 << "\n";
  }
}
