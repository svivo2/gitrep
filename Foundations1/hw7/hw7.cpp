#include "Table.h"

//---------------------------------------------------
// Main program to for Person
//---------------------------------------------------
int main()
{
   Person person;
   Table table;
   
   // Read person information from file
   table.ReadTable();
   
   //user input variable
   int choice = -1;
   //table.PrintTable();

   //menu loop
   while (choice != 4)
   {
        // Print menu
        cout << "\nEnter either 1, 2, 3, or 4 for the options below:\n"
             << "(1) search using their first name,\n" 
             << "(2) search using their last name, or\n"
             << "(3) search using a range of birth years, or\n" 
             << "(4) quit the program.\n";
       
        // Read user input
        cin >> choice;
        cout << endl;
    
        //search first name
        if (choice == 1)
        {
            string first_name = " ";
            cout << "Please enter a first name:\n";
            cin >> first_name;
            table.SearchFirstName(first_name);
        }
    
        //search last name
        if (choice == 2)
        {
            string last_name = " ";
            cout << "Please enter a last name:\n";
            cin >> last_name;
            table.SearchLastName(last_name);
        } 
    
        //search date range
        if (choice == 3)
        {
            int low, high;
            cout << "TO search by birth year, enter a low range";
            cin >> low;
            cout << "enter a high range";
            cin >> high;
            
            table.SearchYear(low, high);
        }
    
    }
   
   return 0;
}