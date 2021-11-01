#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Token.h"
#include <iostream>
using namespace std;

//Declare the enums we will use
enum ExpType {assignment, arithmetic, illegal};

class Expression
{
public:
  //Constructors
  Expression();
  Expression(const string& s);
  void set(const string& s);
  void display() const;
  string getOriginal() const;
  Token * getTokenized() const;

private:

  //Data Members
  string mOriginal;
  Token * mTokenized;
  string mPostfix;
  bool mValid;
  ExpType mExpType;

};

#endif
