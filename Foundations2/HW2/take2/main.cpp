#include <iostream>
#include "Token.h"
#include "Expression.h"
using namespace std;

int main()
{
  Token t;
  t.display();

  Token t2("t3");
  t2.display();

  t.set("t2");
  t.display();

  t.set("2");
  t.display();
  int val = t.value();
  cout << val << endl;

  t.set("144");
  t.display();

  cout << t.getType() << endl;

  t2.set("3t");
  t2.display();

  cout << "\nExpression Test: \n\n" ;

  Expression e;
  e.display();

  e.set("1 + 2");
  e.display();

}
