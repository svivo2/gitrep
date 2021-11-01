#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Token.h"
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
  void append(const Expression& e);
  string getOriginal() const;
  vector <Token> getTokenized() const;
  string getPrefix() const;
  string getPostfix() const;
  string getParen() const;
  bool getValid() const;
  ExpType getExpType() const;
  bool evaluate();
  vector <Token> tokenize(const string& s);



private:

  //Data Members
  string mOriginal;
  vector <Token> mTokenized;
  string mPrefix;
  string mPostfix;
  string mParen;
  bool mValid;
  ExpType mExpType;

};

#endif
