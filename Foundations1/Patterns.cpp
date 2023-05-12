#include <cstdlib>
#include <iostream>
using namespace std;

void printLine(int length)
{
  for(int j = length; j > 0; j--)
  {
    cout << "* ";
  }
}

void printSides(int length)
{
  for(int i = length; i > 0; i--)
  {
    if(i == length || i == 1)
      cout << "* ";
    else
      cout << "  ";
  }
}

int main()
{
  // Declare variables
  int x = 0;
  int y = 0;

  // Get size from user
  while( x == 0)
  {
    cout << "Please enter a number between 5 and 20: \n";
    cin >> x;
    
    if(x < 5 || x > 20)
    {
      x = 0;
    }
  }

  y = x;

  // Solid Square
  for(int i = y; i > 0; i--)
  {
    printLine(x);
    cout << endl;
  }

  cout << endl;

  // Square
  for(int i = y; i > 0; i--)
  {
    if(i == y || i == 1)
      printLine(x);
    else
      printSides(x);
    cout << endl;
  }

  cout << endl;

  // Triangle
  for(int i = y; i > 0; i--)
  {
    for(int j = x; j > 0; j--)
    {
      if(j >= i)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  cout << endl;

  // X
  for(int i = y; i > 0; i--)
  {  
    for(int j = x; j > 0; j--)
    {
      if(i == j)
        cout << "* ";
      else if(j == (y - i + 1))
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  cout << endl;

  // Y
  for(int i = y; i > 0; i--)
  {
    if(i == y || i == 1)
      printLine(x);
    else{
      for(int j = x; j > 0; j--)
      {
        if(i == j)
          cout << "* ";
        else
          cout << "  ";
      }
    }
    cout << endl;
  }



}