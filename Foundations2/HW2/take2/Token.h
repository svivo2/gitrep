#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <vector>
using namespace std;

//Declare the enums we will use
enum TokenType {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};

class Token
{
public:
  //Constructors
  Token();
  Token(string s);
  void set(string s);
  int value() const;
  void display() const;
  TokenType getType() const;
  string getToken() const;
  int getPriority() const;
private:

  //Data members
  TokenType mTokenType;
  string mToken;
  int mPriority;
};

#endif
