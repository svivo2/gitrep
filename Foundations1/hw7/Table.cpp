//---------------------------------------------------
// Purpose:     Implementation of the Table class
//---------------------------------------------------

#include "Table.h"

Person person;
//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Table::Table()
{
  Person table[SIZE];
  count = 0;
}
//---------------------------------------------------
// Copy Constructor function
//---------------------------------------------------
Table::Table(Table &otherTable)
{
  Person table[SIZE];
  count = otherTable.count;
  for(int i = 0; i < count; i++)
  {
    table[i] = otherTable.table[i];
  }
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Table::~Table(){}

//---------------------------------------------------
// Read person information from people.txt
//---------------------------------------------------
void Table::ReadTable()
{
  // Open input file
  ifstream din;
  din.open("people.txt");
  if (din.fail())
    cout << "Could not open people.txt\n";
      
    
  // Read count of table
  string str;
  getline(din, str);
  count = stoi(str);
  
  string fname, lname, contr;
  int byear, dyear;
  Person newPerson;
  // Loop reading table info
  for (int i = 0; i < count && !din.eof(); i++)
  {
    din >> fname;
    din >> lname;
    din >> byear;
    din >> dyear;
    getline(din,contr);

    newPerson.SetFirstName(fname);
    newPerson.SetLastName(lname);
    newPerson.SetBirthYear(byear);
    newPerson.SetDeathYear(dyear);
    newPerson.SetContribution(contr);

    // add new person
    table[i] = newPerson;

  }
   // Close input file
   
      din.close();
}

//---------------------------------------------------
// Print people information from table.txt
//---------------------------------------------------
void Table::PrintTable()
{
    
   // Loop print table info
   for (int i = 0; i < count; i++)
   {
      table[i].print();
      cout << "------------------------------" << endl;
   }
}

//---------------------------------------------------
// search by first name 
//---------------------------------------------------
void Table::SearchFirstName(const string first_name)
{
  //perform search for first name
  bool found = false;
  for (int i = 0; i < count; i++)
  {
    if(table[i].GetFirstName() == first_name)
    {
      found = true;
      table[i].print();
    }
  }
  if(found == false)
    cout << "There is no match for given name\n";
}

//---------------------------------------------------
// search by last name 
//---------------------------------------------------
void Table::SearchLastName(const string last_name)
{
  //perform search for last name
  bool found = false;

  for (int i = 0; i < count; i++)
  {
    if(table[i].GetLastName() == last_name)
    {
      found = true;
      table[i].print();
    }
  }
  if(found == false)
    cout << "There is no match for given name\n";

}

//---------------------------------------------------
// search by year range 
//---------------------------------------------------
void Table::SearchYear(const int low, const int high)
{
  bool found = false;

  for (int i = 0; i < count; i++)
  {
    if(table[i].GetBirthYear() >= low && table[i].GetBirthYear() <= high)
    {
      found = true;
      table[i].print();
    }

    return;
  }
  if(found == false)
    cout << "There is no match for given name\n";

}



  
