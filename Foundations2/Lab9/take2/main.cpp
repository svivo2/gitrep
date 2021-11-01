#include <iostream>

using namespace std;

int factorial(int n)
{
  if (n <= 1)
    return 1;
  else
    return n * factorial(n-1);
}
int fibonacci(int n)
{
  if (n == 1)
    return 1;
  if (n == 0)
    return 0;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}
void sort (int * seq, int size)
{
  if (size == 1)
  {
    cout << seq[0] << endl;
    return;
  }
  int temp = 0;
  for (int i = 0; i < size; i++ )
    {
      if (seq[i] < seq[0])
        {
          temp = seq[0];
          seq[0] = seq[i];
          seq[i] = temp;
        }
    }

  cout << seq[0] << ",";
  return sort(seq + 1, size - 1);
}
void display(int * seq, int size)
{
  if (size == 1)
  {
    cout << seq[0] << endl;
    return;
  }

  cout << seq[0] << ",";
  return display(seq + 1, size - 1);
}

int main()
{
  int size =  25;
  int val = rand() % 50;
  int * seq = new int[size];

  for(int i = 0; i < size; i++)
    seq[i] = rand() % 100;

  cout << "Display: ";
  display(seq, size);
  cout << "Sort: ";
  sort(seq,size);
  cout << "Display: ";
  display(seq,size);

  cout << "Fibonacci(" << val << "):" << fibonacci(val) << endl;
  cout << "Factorial(" << val << "):" << factorial(val) << endl;

}
