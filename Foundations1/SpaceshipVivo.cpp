#include <iostream>
#include "Spaceship.h"
using namespace std;

void PrintMenu() {
  
  cout << endl;
  cout << "OPTIONS:" << endl;
  
  cout << "0 - Quit" << endl;
  cout << "1 - Print my Spaceship's info" << endl;
  cout << "2 - Give my Spaceship a new name" << endl;
  cout << "3 - Give my Spaceship a new crew size" << endl;
  cout << "4 - Give my Spaceship a new impulse speed" << endl;
  cout << "5 - Set shields up" << endl;
  cout << "6 - Set shields down" << endl;
  cout << "7 - Prepare for battle" << endl;
  cout << "8 - End the battle" << endl;
  cout << "9 - Get travel time (in days)" << endl;
  
  cout << endl;
}

//---------------------------------------------
// Name:  GetChoice
// Purpose:  Collect a number between 0 and 9 from the user
//           Do error checking to reject invalid values
// Parameters:  None
// Returns: int, a valid value entered by the user
//---------------------------------------------
int GetChoice() 
{
    char choice;  // read the input into a character for safety
    int intChoice;

  do 
    {
    cout << "Choose what to do next: ";
    cin >> choice;
  } while (choice < '0' || choice > '9');

    // convert the character to an integer and return it
    intChoice = choice - '0';
  return (intChoice);
}

//---------------------------------------------
// Name:  travelDays
// Purpose:  Return how many days it will take to travel a given distance
//           formula:  time = distance/speed 
//           where speed is the spaceship's current speed
//           you need to convert the time from seconds to days
//           and divide the speed by 1000000 to get it in million km per sec
//           Assume that a valid value is passed in (do no error checking)
// Parameters: ship - a Spaceship, const
//             distance - the distance to travel in million km, const
// Returns: double, the number of days to complete the trip
//---------------------------------------------
// distance mkm * speed(sec/km) * day/sec
//YOU NEED TO IMPLEMENT THE COPY CONSTRUCTOR FOR THIS TO COMPILE, WHY???
double travelDays (const Spaceship ship, const long distance)
{
    const long secPerDay = 60 * 60 * 24;   // the number of seconds in a day
    long km = distance * 1000000;
    double speed = ship.CurrentSpeed();
    double days = km / (secPerDay * speed);
    return(days);
}

int main() 
{
  string newName;
  int newCrewSize;
  long newSpeed;
  long distance;
  int choice;
  
    // Use the default constructor to create defaultSpaceship
    Spaceship defaultSpaceship;
    cout << "defaultSpaceship\n";
    defaultSpaceship.Print();

    // Use the non-default constructor to create the Excalibur with a crew of 10
    // and an impulse speed of 10000 and shields down
    // Then print it out
    Spaceship mySpaceship(10,"Excalibur", 10000, false);
    cout << "mySpaceship\n";
    mySpaceship.Print();  // CHANGE THIS TO USE NON_DEFAULT CONSTRUCTOR

  // use the copy constructor to create another spaceship that is a copy
    // of the Excalibur (then print it out)
    Spaceship copySpaceship(mySpaceship);
    cout << "copySpaceship\n";
    mySpaceship.Print();
  
  do {
    
    PrintMenu();
    choice = GetChoice();
    
    // TODO: fill out each choice in this switch statement
    // by calling methods in your mySpaceship object
    switch(choice) {
      case 0:
        break;
        
      case 1:
        mySpaceship.Print();
        break;  
      case 2:
      cout << "Please type in new name: ";
      cin >> newName;
      mySpaceship.SetName(newName);
        break;
      case 3:
      cout << "What's the new crew size (between 0 and 1000000)? ";
      cin >> newCrewSize;
      while(newCrewSize <= 0 || newCrewSize >= 1000000)
      {
        cout << "We cannot handle that size crew. What's the new crew size (between 0 and 1000000)? ";
        cin >> newCrewSize;
      }
      mySpaceship.SetCrewSize(newCrewSize);
        break;  
      case 4:
      cout << "What's the new impulse speed (between 0 and 1000000)? ";
      cin >> newSpeed;
      while(newSpeed <= 0 || newSpeed >= 1000000)
      {
        cout << "We cannot handle that speed.  What's the new impulse speed (between 0 and 1000000)? ";
        cin >> newSpeed; 
      }
      mySpaceship.SetImpulseSpeed(newSpeed);
        break;
      case 5:
      mySpaceship.SetShieldsUp(true);
        break;        
      case 6:
      mySpaceship.SetShieldsUp(false);
        break;
      case 7:
      mySpaceship.BattleStart();
        break;
      case 8:
      mySpaceship.BattleEnd();
        break;
      case 9:

                cout << "How far are you going, in million kilometers (0 to 1000000)? ";
                cin >> distance;
                while ((distance < 0) || (distance > 1000000))
                {
                    cout << "We cannot travel that far.  ";
                    cout << "How far are you going, in million kilometers (0 to 1000000)? ";
                    cin >> distance;
                }
                cout << "You will be traveling for "
                    << travelDays(mySpaceship, distance)
                    << " days." << endl
                    << "Speed: " << mySpaceship.CurrentSpeed();

                break;
        
      default:
        break;
        
    }
    
  } while (choice != 0);

  return 0;
}