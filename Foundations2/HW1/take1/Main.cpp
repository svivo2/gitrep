#include <iostream>
#include <fstream>
using namespace std;
#include "PassengerList.h"

int main()
{
    PassengerList list;
    char choice = '\0';
    string FirstName, LastName;
    string filename =  "Flight.txt";

    ifstream din(filename.c_str());

    cout << "Welcome to Razorback Airlines!\nHow can we help you today?\n 1) Book a flight\n 2) Cancel a Booking\n 3) Confirm a Booking\n 4) Print List\n 5) Quit\n";

    if (!din)
       cerr << "Could not open " << filename << "\n.";
    else
    {
      while(choice != '5')
      {
          din >> choice;
          if (choice == '1')
          {
              din >> FirstName >> LastName;

              list.Book(FirstName, LastName);

          }
          if (choice == '2')
          {
              din >> FirstName >> LastName;

              list.Cancel(FirstName, LastName);
          }
          if (choice == '3')
          {
              din >> FirstName >> LastName;

              list.Confirm(FirstName, LastName);
          }
          if (choice == '4')
          {
            list.Print();
          }
      }
      cout << "Thank you for choosing Razorback Airlines. Goodbye!\n";
      din.close();
  }
}
