/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */

#include "myString.h"

// default constructor
Mystring::Mystring()
{
  ptr_buffer  = new char[1];
  *ptr_buffer = '\0';
  buf_size    = 1;
  len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s)
{
  len        = strlen(s);
  buf_size   = len + 1;
  ptr_buffer = new char[buf_size];
  strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig)
{
  len        = orig.length();
  buf_size   = len + 1;
  ptr_buffer = new char[buf_size];
  strcpy(ptr_buffer, orig.c_str());
}

// one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig)
{
  *this = orig.c_str();
  return *this;
}

Mystring& Mystring::operator=(const char * str)
{
  this->len = strlen(str);
  this->buf_size = this->len + 1;
  this->ptr_buffer = new char[this->buf_size];
  strcpy(this->ptr_buffer, str);
  return *this;
}

char Mystring::operator[](size_type pos) const
{
  return this->ptr_buffer[pos];
}
char& Mystring::operator[](size_type pos)
{
  return this->ptr_buffer[pos];
}

// some simple methods implemented for you
Mystring::size_type Mystring::size() const
{
  return len;
}

Mystring::size_type Mystring::length() const
{
  return len;
}

Mystring::size_type Mystring::capacity() const
{
  return buf_size;
}

Mystring::size_type Mystring::max_size() const
{
  return (int)pow(2,30) -4 ;
}

Mystring& Mystring::operator+=(const Mystring& orig)
{
  *this += orig.c_str();
  return *this;
}

Mystring& Mystring::operator+=(const char * str)
{
  this->len += strlen(str);
  this->buf_size = this->len + 1;
  Mystring temp = *this;
  this->ptr_buffer = new char[this->buf_size];
  strcpy(this->ptr_buffer, temp.c_str());
  strcat(this->ptr_buffer, str);
  return *this;
}

void Mystring::clear()
{
  strcpy(this->ptr_buffer, "\0");
}

void Mystring::push_back(char c)
{

}

Mystring& Mystring::append(const Mystring& str)
{
  *this += str.c_str();
  return *this;
}
Mystring& Mystring::append(const char * str)
{
  *this += str;
  return *this;
}

Mystring& Mystring::insert(size_type pos, const Mystring& str)
{
  this[pos] = str.c_str();
}
Mystring& Mystring::insert(size_type pos, const char * str)
{
  this[pos] = str;
  return *this;
}

Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str)
{

}
Mystring& Mystring::replace(size_type start, size_type span, const char * str)
{

}

// Destructor
Mystring::~Mystring()
{
  delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str)
{
  out << str.c_str();
  return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const
{
  return ptr_buffer;
}

//=== Overloading global operators for Mystring

// Overload operator == for Mystring
bool operator==(const Mystring& a,const Mystring& b)
{
  return ( *a.c_str() == *b.c_str());
}
bool operator==(const char * a, const Mystring& b)
{
  return (*a == *b.c_str());
}
bool operator==(const Mystring& a,const char *b)
{
  return (*a.c_str() == *b);
}

// Overload operator != for Mystring
bool operator!=(const Mystring& a, const Mystring& b)
{
  return !(a == b);
}
bool operator!=(const char * a, const Mystring& b)
{
  return !(a == b);
}
bool operator!=(const Mystring& a, const char * b)
{
  return !(a == b);
}
