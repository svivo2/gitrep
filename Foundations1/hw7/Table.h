//---------------------------------------------------
// Purpose:     Header file for the Table class
//---------------------------------------------------
#include "Person.h"

const int SIZE = 1000;

class Table
{
public:
  // Constructor and destructor
  Table ();
  Table(Table &otherTable);
  ~Table ();

  // Methods
  void ReadTable ();
  void PrintTable ();
  void SearchFirstName(const string first_name);
  void SearchLastName(const string last_name);
  void SearchYear(const int low, const int high);

private:
    Person table[SIZE];
    int count;
};
