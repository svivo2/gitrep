//---------------------------------------------------
// Purpose:     Header file for the Person class
//---------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Class definition
class Person
{
    
    public:
       // Constructor and destructor
       Person();
       Person(Person &person);
       Person(string &fname, string &lname, int &byear, int &dyear, string &contr);

       ~Person();
       void print();
       
       // Set Methods
       void SetFirstName(string first_name);
       void SetLastName(string last_name);
       void SetBirthYear(int birth_year);
       void SetDeathYear(int death_year);
       void SetContribution(string contri);
       
       // Get Methods
       string GetFirstName();
       string GetLastName();
       int GetBirthYear();
       int GetDeathYear();
       string GetContribution();
       
    private:
       string FirstName;
       string LastName;
       int BirthYear;
       int DeathYear;
       string Contribution;

};