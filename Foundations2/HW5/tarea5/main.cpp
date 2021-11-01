#include "Token.h"
#include "Expression.h"
using namespace std;



bool evaluate(Expression &e)
{
  cout << e.evaluate() << endl;

  return e.getValid();
}

bool prefix(Expression &e)
{
  cout << e.getPrefix() << endl;

  return e.getValid();
}

bool postfix(Expression &e)
{
  cout << e.getPostfix() << endl;

  return e.getValid();
}

bool paren(Expression &e)
{
  cout << e.getParen() << endl;

  return e.getValid();
}

bool cont(Expression &e)
{
  Expression x;
  e.append(x);
  cout << e.getOriginal() << endl;

  return e.getValid();
}

bool startOver(Expression &e)
{
  string s;
  e.set(s);
  cout << e.getOriginal() << endl;

  return e.getValid();
}

int main()
{
  string input;
  Expression e;
  char action = '\0';

  cout << "=== Expression evaluation program starts ===\n";

  while(action != 'q')
  {
      cout << "\ninput: ";
      cin >> input;


      cout << "\naction: ";
      cin >> action;

      if (action == '=')
      {

        cout << "Sorry not yet available.\n";

        if (evaluate(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";

      }
      if (action == '>')
      {
        cout << "Sorry not yet available.\n";
        if (prefix(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";
      }
      if (action == '<')
      {
        cout << "Sorry not yet available.\n";
        if (postfix(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";
      }
      if (action == 'f')
      {
        cout << "Sorry not yet available.\n";
        if (paren(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";
      }
      if (action == 'c')
      {
        cout << "Sorry not yet available.\n";
        if (cont(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";
      }
      if (action == 's')
      {
        cout << "Sorry not yet available.\n";
        if (startOver(e))
          cout << "Valid Expression\n";
        else
          cout << "Invalid Expession\n";
      }
      else
      {
        cout << "Wrong input for the action! Please type one of =, <, >, f(F), q(Q), c(C), s(S)\n\n Action: ";
        cin >> action;
      }


    }


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
  val = t.value();
  cout << val << endl;

  cout << t.getType() << endl;

  t2.set("3t");
  t2.display();

  Token t1("+");
  t1.display();

  t1.set("12a");
  t1.display();

  cout << "\nExpression Test: \n\n" ;

  Expression e1;
  e1.display();

  e1.set("1 + 2");
  e1.display();

  e1.set("1+2");
  e1.display();

  Expression e2("a+b-c*d/e");
  e2.display();

}
