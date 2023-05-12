//---------------------------------------------------
// Purpose:     Implementation of the Person class
//---------------------------------------------------

#include "Person.h"

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Person::Person()
{
    FirstName = " ";
    LastName = " ";
    BirthYear = 0;
    DeathYear = 0;
    Contribution = " ";
}

//---------------------------------------------------
// Copy Constructor function
//---------------------------------------------------
Person::Person(Person &person)
{
    FirstName = person.FirstName;
    LastName = person.LastName;
    BirthYear = person.BirthYear;
    DeathYear = person.DeathYear;
    Contribution = person.Contribution;
}

//---------------------------------------------------
// Custom Constructor function
//---------------------------------------------------
Person::Person(string &fname, string &lname, int &byear, int &dyear, string &contr)
{
    FirstName = fname;
    LastName = lname;
    BirthYear = byear;
    DeathYear = dyear;
    Contribution = contr;
}


//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Person::~Person()
{
    
}

//---------------------------------------------------
// Setters
//---------------------------------------------------
void Person::SetFirstName(string first_name)
{
    FirstName = first_name;
}

void Person::SetLastName(string last_name)
{
    LastName = last_name;
}

void Person::SetBirthYear(int birth_year)
{
    BirthYear = birth_year;
}

void Person::SetDeathYear(int death_year)
{
    DeathYear = death_year;
}

void Person::SetContribution(string contri)
{
    Contribution = contri;
}
     
//---------------------------------------------------
// Getters
//---------------------------------------------------
string Person::GetFirstName()
{
   return FirstName;
}     

string Person::GetLastName()
{
   return LastName;
} 

int Person::GetBirthYear()
{
   return BirthYear;
} 

int Person::GetDeathYear()
{
   return DeathYear;
}

string Person::GetContribution()
{
   return Contribution;
}


//---------------------------------------------------
// Print person
//---------------------------------------------------
void Person::print()
{
   cout << "First Name: " << FirstName << endl
        << "Last Name: " << LastName << endl
        << "Birth year: " << BirthYear << endl
        << "Death year: " << DeathYear << endl 
        << "Contribution: " << Contribution << endl; 
}