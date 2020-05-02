#include "Token.h"
#include <iostream>
using namespace std;

Token::Token()
{
  mTokenType = INVALID;
  mToken = "\0";
  mPriority = -1;
}

Token::Token(string s)
{
  set(s);
}

void Token::set(string s)
{
  mToken = s;
  mPriority = -1;

  if (((s >= "A")&& (s <= "Z")) || ((s >= "a") && (s <= "z")))
    mTokenType = ID;
  else if ((s >= "0") && (s <= "9"))
    mTokenType = INT;
  else if ((s == "+") || (s == "-") || (s == "*") || (s == "/") || (s == "%"))
    mTokenType = OP;
  else if (s == "=")
    mTokenType = EQ;
  else if (s == "(")
    mTokenType = OpenBrace;
  else if (s == ")")
    mTokenType = CloseBrace;
  else
    mTokenType = INVALID;
}

int Token::value() const
{
  if (mTokenType == INT)
    return stoi(mToken);
  else if (mTokenType == ID)
    return -1;
  else
    return -2;
}

void Token::display() const
{
  cout << "\nToken : " << mToken << endl;
  cout << "TokenType : " << mTokenType << endl;
  cout << "Priority : " << mPriority << endl << endl;
}

TokenType Token::getType() const
{
  return mTokenType;
}

string Token::getToken() const
{
  return mToken;
}

int Token::getPriority() const
{
  return mPriority;
}
