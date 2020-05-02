#include "Expression.h"
#include "Token.h"
#include <iostream>
using namespace std;

Expression::Expression()
{
  mOriginal = "\0";
  mTokenized = new Token("\0");
  mPostfix = "\0";
  mValid = false;
  mExpType = illegal;
}

Expression::Expression(const string& s)
{
  //ADD CODE
}

void Expression::set(const string& s)
{
  mOriginal = s;

}

void Expression::display() const
{
  cout << "\nOriginal: " << mOriginal << endl;
  cout << "Tokenized: " << mTokenized->getToken() << endl;
  cout << "Postfix: " << mPostfix << endl;
  cout << "Valid: " << mValid << endl;
  cout << "Type: " << mExpType << endl << endl;
}

string Expression::getOriginal() const
{
  return mOriginal;
}

Token * Expression::getTokenized() const
{
  return mTokenized;
}
