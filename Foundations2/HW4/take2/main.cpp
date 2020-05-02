
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Linkedlist.h"

using namespace std;

int main()
{
  Linkedlist l;

  if (l.empty() == true)
    cout << "Empty Function seems to be working.\n";
  else
    cout << "Constructor or Empty function is wrong.\n";

  l.check();

  l.push_back(0);
  l.check();
  l.rcheck();

  cout << "Testing explicit constructor\n";

  Linkedlist l2(5);
  l2.check();
  l2.rcheck();

  cout << "Testing push front 7\n";

  l2.push_front(7);
  l2.check();
  l2.rcheck();

  cout << "Testing push back -1\n";

  l2.push_back(-1);
  l2.check();
  l2.rcheck();

  cout << "Testing insert 5 at position 2\n";

  l2.insert(2,5);
  l2.check();
  l2.rcheck();

  cout << "Testing explicit constructor (0)\n";

  Linkedlist l1(0);
  l1.check();
  l1.rcheck();

  cout << "Testing sort\n";
  l2.sort();
  l2.check();
  l2.rcheck();

  return 0;
}
