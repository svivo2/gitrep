#include "Expression.h"
#include "Token.h"
#include <iostream>
using namespace std;

Expression::Expression()
{
  mOriginal = "\0";
  mPostfix = "\0";
  mValid = false;
  mExpType = illegal;
}

Expression::Expression(const string& s)
{
  this->set(s);
}

void Expression::set(const string& s)
{
  mOriginal = s;
  mTokenized = tokenize(s);
  string mPrefix = prefix(s);
}

void Expression::display() const
{
  cout << "\nOriginal: " << mOriginal << endl;
  cout << "Tokenized: ";
  if (mTokenized.empty())
    cout << "mTokenized is empty";
  else
  {
    for (int i = 0; mTokenized[i].getToken()!= "\0"; i++)
      cout << mTokenized[i].getToken() << " | ";
  }
  cout << "\nPostfix: " << mPostfix << endl;
  cout << "Valid: " << mValid << endl;
  cout << "Type: " << mExpType << endl << endl;
}

void Expression::append(const Expression& e)
{
  cout << "In append\n";
}

vector <Token> Expression::tokenize(const string& s)
{
  cout << "In tokenize()\n";
  string tok;
  cout << tok << endl;
  string copy = s;
  vector <Token> token;
  for (int i = 0; i < copy.size(); i++)
  {
    if ((copy[i] == '+') || (copy[i] == '-') || (copy[i] == '*') || (copy[i] == '/') || (copy[i] == '%') || (copy[i] == '='))
    {
      copy.insert(i+1," ");
      copy.insert(i++," ");
    }
  }
  cout << "copy: " << copy << endl;

  char * t = new char[copy.size()];
  strcpy(t, copy.c_str());
  t = strtok(t, " ");
  cout << t << endl;

  while(t != NULL )
  {
    Token *coin = new Token;
    tok = *t;
    coin->set(tok);
    coin->display();
    token.push_back(tok);
    t = strtok(NULL, " ");
  }

  return token;

}

string Expression::getOriginal() const
{
  return mOriginal;
}

vector <Token> Expression::getTokenized() const
{
  return mTokenized;
}

string Expression::getPrefix() const
{

  return mPrefix;
}

string Expression::getPostfix() const
{
  return mPostfix;
}

string Expression::getParen() const
{
  return mParen;
}

bool Expression::getValid() const
{
  return mValid;
}

ExpType Expression::getExpType() const
{

 return mExpType;
}

bool Expression::evaluate()
{
  return mValid;
}
