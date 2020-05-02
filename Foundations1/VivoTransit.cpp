//Example program
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Rocket cost consts
const int aCostPerKm = 250.00; //Cost of the trip per km for a class A rocket
const int aCostPerKg = 1000; //Cost to get one pound of matter into orbit for a class A rocket
const int bCostPerKm = 325.00;//Cost of the trip per km for a class B rocket
const int bCostPerKg = 1250; //Cost to get one pound of matter into orbit for a class B rocket

//Astrononical distance consts
const int distToMoon = 384400; //Dist to moon (minimum trip length) in km
const int distToAstBelt = 350000000; //Dist to asteroid belt (maximum trip length) in km

//---------------------------------------------------------------------------
// Name: GetBoundedInput
// Parameters: Question, string, the YN question to ask. LowerBound/Upperbound, the bounds within
// which the user input must fall.
// Returns: input; the number the user entered.  range is (Lowerbound, Upperbound)
// Purpose: This function returns the user's bounded response to a question
//---------------------------------------------------------------------------

double GetBoundedInput(const string Question, const double Lowerbound, const double Upperbound)
{
    double input;

    cout << Question;
    cin >> input;

    while (input < Lowerbound || input > Upperbound)
    {
        cout << "\nInput out of range. Please try again. ";
        cin >> input;
    }

    return input;
}

//---------------------------------------------------------------------------
// Name: CalculateCost
// Parameters: const int totalWeight, const long totalDist, const char rocketClass, ref double cost
// Returns: none
// Purpose: Calculate the total cost of the trip given the user's input
// and the given global parameters and assign it to cost
//---------------------------------------------------------------------------

void CalculateCost(const int totalWeight, const long totalDist, const char rocketClass, double &cost)
{
    if (rocketClass == 'A')
    {
        cost = (totalWeight * aCostPerKg) + (totalDist * aCostPerKm); 
    }
    else
    {
        cost = (totalWeight * bCostPerKg) + (totalDist * bCostPerKm);
    }
}

//---------------------------------------------------------------------------
// Name: CalculateClass
// Parameters: long totalDist
// Returns: char class. A for lighter rockets and B for stringent needs
// Purpose: Calculate the class of the rocket based on its distance and needs.
// Class B rockets are required for >100 passengers or trips longer than 1M km.
// Call GetBoundedInput to get the number of users(max 250) and return 'A' or 'B' 
//---------------------------------------------------------------------------

char CalculateClass(const long totalDist)
{
    char rocket;
    int users;

    users = GetBoundedInput("\nEnter the number of passenger seats you require (250 max): ", 0, 250);

    if (users > 100 || totalDist > 1000000)
    {
        rocket = 'B';
    }
    else
    {
        rocket = 'A';
    }

    return rocket;
}

//---------------------------------------------------------------------------
// Name: BookAnotherRide
// Parameters: ref char cont
// Returns: none
// Purpose: This function asks the user if they want to continue, checks to 
// ensure that the user enters a 'Y' or a 'N', and returns the answer
//---------------------------------------------------------------------------

void BookAnotherRide(char &cont)
{
    cout << "Do you want to book another ride? Enter Y or N: ";
    cin >> cont;
    cont = toupper(cont);

    while (cont != 'Y' && cont != 'N')
    {
        cout << "\nInvalid character. Please enter either (Y) for yes or (N) for no.";
        cout << "\nDo you want to book another ride? Enter Y or N: ";
        cin >> cont;
        cont = toupper(cont);
    }
}

int main()
{
int totalWeight = 0;
long totalDist = 0;    
double totalCost = 0;
char rocketClass = '\0';
char goAgain = 'N';    

    // these two lines print numbers with ',' after 3 digits
    locale mylocale("");       
    cout.imbue(mylocale);

    do
    {
        cout << "Welcome to the Inner Solar System Space Transit System.\nYou can book trips for passengers and cargo " <<
                "from the moon to the inner asteroid belt. Let's get started!\n";

        totalWeight = GetBoundedInput("\nWhat is the total weight of the passsengers and cargo? (Max 5000 kgs; no comma):  ", 0, 5000);

        totalDist = 2 * GetBoundedInput("\nWhat is the distance in km to your destination? (384,400 km to 350,000,000km; no commas):  ", distToMoon, distToAstBelt);

        rocketClass = CalculateClass(totalDist); 

        CalculateCost(totalWeight, totalDist, rocketClass, totalCost);            

        cout << "\nThe cost for your trip on your class " << rocketClass << " rocket will cost $" 
             << (long)totalCost/1000000 << " million." << endl << endl;

        BookAnotherRide(goAgain);
    }while(goAgain != 'N');

    return 0;
}