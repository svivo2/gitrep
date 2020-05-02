//Example program
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const float WOLF_PRICE = 55.00; 
const float RABBIT_PRICE = 15.00;
const float STEAK_PRICE = 12.00;
//all of the above are measured in $/yd^3


//---------------------------------------------------------------------------
// Name: GetYorN
// Parameters: Questions, string, input, the YN question to ask
// Returns: char; the character the user entered.  Must be 'y' or 'Y' or 'n' or 'N'
// Purpose: This function returns the user's response to a yes/no question
//---------------------------------------------------------------------------
char GetYorN(const string Question)
{
char choice;

   cout << Question << "  Enter Y or N: ";
   cin >> choice;
   choice = toupper(choice);

   while (choice != 'Y' && choice != 'N')
   {
      cout << "Invalid character. Please enter either (Y) for yes or (N) for no.\n";
      cout << Question << "  Enter Y or N: ";
      cin >> choice;
      choice = toupper(choice);
   }

   return (choice);
}

//---------------------------------------------------------------------------
// Name: GetLoadChoice
// Parameters: reference char choice
// Returns: none (passed in via reference), Must be 'R', 'W', or 'S'
// Purpose: Determine which of the items the user would like to ship
//          
//---------------------------------------------------------------------------
void GetLoadChoice(char &choice)
{   
    cout << "\nWhich of the following would you like to ship?" 
         << "\n  (W)olves" 
         << "\n  (S)teak" 
         << "\n  (R)abbits\n";
    cout  << "Enter W or S or R: ";
    cin >> choice;
    choice = toupper(choice);

    while(choice != 'W' && choice != 'S' && choice != 'R')
    {
        cout << "Sorry, we don't ship that type of item.\n";
        cout << "Which of the following would you like to add?" <<
                "\n (W)olves" <<
                "\n (S)teak" <<
                "\n (R)abbits\n";
        cin >> choice;
        choice = toupper(choice);
    }
}

//---------------------------------------------------------------------------
// Name: AddLoad
// Parameters: const char loadChoice - the type of item to be shipped
// Returns: float cost
// Purpose: Find the (positive integer) quantity of yards to be shipped, then
//          add the appropriate price to the total
//---------------------------------------------------------------------------
float AddLoad(const char loadChoice)
{   
float cost = 0.0;
int quantity = 0;
    
    cout << "Enter the number of cubic yards you would like to ship:  ";
    cin >> quantity;
    while(quantity < 1)
    {
        cout << "Sorry, you must enter a number >= 0.\n";
        cout << "Enter the number of cubic yards you would you like to ship: ";
        cin >> quantity;
    }
    
    if (loadChoice == 'W')
       cost = cost + quantity * WOLF_PRICE;
    else if (loadChoice == 'S')
       cost = cost + quantity * STEAK_PRICE;
    else 
       cost = cost + quantity * RABBIT_PRICE;

    return cost;
}

//---------------------------------------------------------------------------
// Name: PrintMain
// Parameters: none
// Returns: none
// Purpose: Prints the main menu for the shipping scheduler
//---------------------------------------------------------------------------
void PrintMain()
{
    cout << "Welcome to the Aesop shipping LLC load scheduler\n"
         << "You can ship some combinations of rabbits, wolves, and frozen steak.\n"
         << "(Fares are all measured in dollars/cubic yard for convenience)\n"
         << "If you want to ship steak, you have to use a refrigerated train.\n"
         << "If you attempt to ship rabbits and wolves, the order will be cancelled.\n"
         << "If you attempt to ship non-frozen steak, the order will be cancelled.\n\n";
}

//---------------------------------------------------------------------------
// Name: RefrigeratedCar
// Parameters: int &numRCars; add one to the number of refigerated cars used
// Returns: 150 if the user requests a refrigerated car, 0 otherwise.
// Purpose: Ask if the user wants a refrigerated car and return the additional
//          cost if so, 0 otherwise.
//---------------------------------------------------------------------------
int RefrigeratedCar(int &numRCars)
{
char wantRefrigeratedCar;
int cost = 0;

    // If the user answers 'Y', increment the number of refrigerated cars used
    wantRefrigeratedCar = GetYorN("Do you require a refrigerated car?  ");
    if (wantRefrigeratedCar == 'Y')
    { 
       numRCars++;
       cost = 150;  
    }

    return cost;
}

//---------------------------------------------------------------------------
// Name: IsValidOrder
// Parameters: const char firstLoad, const char secondLoad, const int NumRCars 
// Returns: true if the order is valid, false otherwise
// Purpose: check the loads to ensure that rabbits and wolves aren't
//          being shipped together, and ensure that the user ordered a 
//          refrigerated car if they are shipping steak. If any violation
//          occured, tell the user which and return false. Otherwise, return true.
//---------------------------------------------------------------------------
bool IsValidOrder(const char firstLoad, const char secondLoad, const int numRCars)
{
bool isValid = true;

    // If there is anything wrong, change isValid to false
    if(firstLoad == 'W' && secondLoad == 'R')
    {
        cout << "Cannot ship both wolves and rabbits together\n";
        isValid = false;
    }
    if(firstLoad == 'R' && secondLoad == 'W')
    {
        cout << "Cannot ship both wolves and rabbits together\n";
        isValid = false;
    }
    if((firstLoad == 'S' || secondLoad == 'S') && (numRCars == 0))
    {
        cout << "Steaks require a refrigerated car.\n";
        isValid = false;
    }
 
 return isValid;
}

//---------------------------------------------------------------------------
// Name: PrintBill
// Parameters: const float totalCost - the cost of all the shipments 
//             const int numRCars - the number of refigerator cars
// Returns: void  
// Purpose: Prints the bill
//---------------------------------------------------------------------------
void PrintBill(const float totalCost, const float numRCars)
{
    cout << "Your total bill is $" 
         << fixed << setprecision(2) << totalCost << ".  "
         << "The price includes " << setprecision(0) << numRCars << " refrigerator cars.\n";
}

//---------------------------------------------------------------------------
// Name: YouAreFinished
// Parameters: none
// Returns: bool:  true if finished, false if not finishted
// Purpose: Prints the main menu for the shipping scheduler
//---------------------------------------------------------------------------
bool YouAreFinished()
{
char choice;

    choice  = GetYorN("\nDo you want to schedule another shipment?  ");
    
    // if the user entered 'N', then you are finished
    return (choice == 'N');
}

int main()
{
    //shipment variables
    char firstLoad = '\0';    // type of the first load in a shipment
    char secondLoad = '\0';   // type of the second load in a shipment
    int shipmentRefrigCars = 0;  // number of refrigerator cars for this shipment
    float shipmentRefrigCost = 0.0;      // cost of the refrigerator cars for this shipment
    float shipmentCost = 0.0;    // cost of this shipment

    //total order variables
    int numRefrigCars = 0;       // number of refrigerator cars total
    float totalCost = 0.0;       // total cost of all shipments
    bool done = false;           // whether or not the user is done shipping stuff

    //Loop until the user is done

    while (done == false)
    {
        
        //initialize the shipmentRefrigCars, shipmentRefrigCost and shipmentCost variables

        shipmentRefrigCars = 0;
        shipmentRefrigCost = 0.0;
        shipmentCost = 0.0;

        //Print the main menu   
        
        PrintMain();

        //Ask if the user needs a refrigerated car and store the number and cost of the 
        //refrigerator car (if any) in the appropriate shipment variables
        
        shipmentRefrigCost = RefrigeratedCar(shipmentRefrigCars);
        cout << shipmentRefrigCost << endl;
        cout << shipmentRefrigCars << endl;

        //Find out what the user wants to in the first load
        
        GetLoadChoice(firstLoad);

        //Set the load cost to the cost of the first load

        shipmentCost = AddLoad(firstLoad);

        //Get the user's second choice of load

        GetLoadChoice(secondLoad);

        //Add the user's second load cost to the shipment cost
        
        shipmentCost = shipmentCost + AddLoad(secondLoad); 

        //If the order is valid,

        if (IsValidOrder(firstLoad, secondLoad, shipmentRefrigCars) == true)
        {
            totalCost = totalCost + shipmentCost + shipmentRefrigCost;
            numRefrigCars = numRefrigCars + shipmentRefrigCars;
        } 
        else
        {
            cout << "Order has been cancelled\n";
        }

        //   add the shipment cost and the refrigerator car cost to the total cost
        //   add the number of shipment refrigerator cars to the total number of refrigerator cars
        //else
        //   inform the user that their shipment has been cancelled

        //Ask the user whether or not they want to continue (Y or N)
        
        done = YouAreFinished();

    }

    //output the total cost and the number of refrigerator cars used

    PrintBill(totalCost, numRefrigCars);

    return 0;
}