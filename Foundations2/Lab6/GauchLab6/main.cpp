#include <iostream>
using namespace std;

int Factorial(int Num)
{
  cout << "Entering Factorial, Num = " << Num << endl;
  // Terminating condition
  if (Num <= 1)
    return(1);

  // Recursive case
  else
  {
    int Return =  Num * Factorial(Num-1);
    cout << "Leaving Factorial, Return = " << Return << endl;
    return Return;
  }
}

int Fibonacci(int Num)
{
  cout << "Entering Fibonacci, Num = " << Num << endl;
  // Terminating condition
  if (Num <= 2)
    return(1);

  // Recursive case
  else
  {
    int Return = ( Fibonacci(Num-1) + Fibonacci(Num-2) );
    cout << "Leaving Fibonacci, Return = " << Return << endl;
    return Return;
  }
}

float Power(float X, int p)
{
  float half = 0;
  // Terminating conditions
  if (p == 0)
    return 1;
  if (p == 1)
    return X;

  // Recursive cases
  if(p < 0)
  {
    return 1/Power(X,-1 * p);
  }
  if((p % 2) == 0)
  {
    half = Power(X,p/2);
    return half * half;
  }
  else
  {
    half = Power(X,p/2);
    return half * half * X;
  }
}

int main()
{
  int num, exponent = 0;
  float power = 0;

  cout << "Please enter a number: ";
  cin >> num;
  cout << "\nPlease enter a exponent: ";
  cin >> exponent;
  power = Power(num,exponent);
  cout << endl << num << " to the Power of " << exponent << " = " << power << endl;
}
