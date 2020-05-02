#include <fstream>
#include "GalaxyTrader.h"
using namespace::std;

//constructor
GalaxyTrader::GalaxyTrader()
{
  ship_pos = 0;
  wolves = 0;
  steaks = 0;
  rabbits = 0;
  fuel = 5;
  credits = 100;
}

//copy constructor
GalaxyTrader::GalaxyTrader(GalaxyTrader& other)
{
  ship_pos = other.ship_pos;
  wolves = other.wolves;
  steaks = other.steaks;
  rabbits = other.rabbits;
  fuel = other.fuel;
  credits = other.credits;
}

//destructor
GalaxyTrader::~GalaxyTrader()
{
}

//method name: init
//parameters: the name of the file to read from
//purpose: initializes the planet array using the information in the given file
//         should use the init method of the Planet class
//         if the input file contains a planet outside the bounds of the array immediately return false 
//input file format:
//      position of planet
//      name of planet
//      Number of: Wolves Steaks Rabbits then Prices of: Wolves Steaks Rabbits Fuel
//example: 2
//       Mars
//         4 13 15 100 10 20 8
//returns: false if any planets were going to be placed out of bounds, true otherwise
// You may assume that the file format is correct, you do not need to error check anything except
// Planet position
bool GalaxyTrader::init(const string filename)
{
  ifstream din(filename.c_str());
  do
  {
    if (!din)
       cerr << "Could not open " << filename << "\n.";
    else
    {
      int i;
      din >> i;
      if(i < 0 || i > SIZE)
      {
        cout << "Planet not within bounds\n";
      }
      else
      {
        string name;
        int numW, numS, numR, priceW, priceS, priceR, priceF;
        din >> name >> numW >> numS >> numR >> priceW >> priceS >> priceR >> priceF;
        int data[NUM_DATA] = {numW, numS, numR, priceW, priceS, priceR, priceF};
        planets[i].init(name, data);
      }
    }
  }while(!din.eof());
      //Close the file
    din.close();
  return true;
}

//method name: buy
//parameters: none
//purpose: ask the user which good they want to buy and how many they want to buy
//         then this calls the buyFrom method of the planet the ship is on
//         finally if the transaction was sucessful the goods purhased are added to the ship's cargo
//valid inputs: w/s/r for goods, any non negative number for quantity
//returns: true if the transaction was successful, false otherwise
bool GalaxyTrader::buy()
{
  char good;
  int amount;
  bool valid = false;
  cout << "What good do you wish to buy Captain? (w, s, r) ";
  cin >> good; 
  good = toupper(good);
  while (good  != 'W' && good != 'S' && good != 'R')
  {
    cout << "\nThat is not a valid good, please try again (w, s, r) ";
    cin >> good;
    good = toupper(good);
  }
  cout << "\nHow many do you wish to buy Captain? ";
  cin >> amount;
  while (amount < 0)
  {
    cout << "\nYou cannot buy that many, please try again ";
    cin >> amount;
  }
  valid = planets[ship_pos].buyFrom(good, amount, credits);
  if (valid)
  {
    switch(good)
    {
      case 'W':
        wolves += amount;
      break;
      case 'S':
        steaks += amount;
      break;
      case 'R':
        rabbits += amount;
      break;
    }
    return true;
  }
  else 
    return false;
}

//method name: sell
//parameters: none
//purpose: ask the user which good they want to sell and how many they want to buy
//         then this calls the sellTo method of the planet the ship is on
//         finally if the transaction was sucessful the goods purhased are removed from the ship's cargo
//valid inputs: w/s/r for goods, any non negative number up to the number of the good in the ship's cargo for quantity
//returns: true if the transaction was successful, false otherwise
bool GalaxyTrader::sell()
{
  char good;
  int amount;
  bool valid = false;
  cout << "What good do you wish to sell Captain? (w, s, r) ";
  cin >> good; 
  good = toupper(good);
  while (good  != 'W' && good != 'S' && good != 'R')
  {
    cout << "\nThat is not a valid good, please try again (w, s, r) ";
    cin >> good;
    good = toupper(good);
  }
  cout << "\nHow many do you wish to sell Captain? ";
  cin >> amount;
  
  switch(good)
  {
    case 'W':
      while (amount < 0 || amount > wolves)
      {
        cout << "\nYou cannot sell that many, please try again ";
        cin >> amount;
      }
      valid = planets[ship_pos].sellTo(good, amount, credits);
      wolves -= amount;
      return true;
    break;
    case 'S':
      while (amount < 0 || amount > steaks)
      {
        cout << "\nYou cannot sell that many, please try again ";
        cin >> amount;
      }
      valid = planets[ship_pos].sellTo(good, amount, credits);
      steaks -= amount;
      return true;
    break;
    case 'R':
      while (amount < 0 || amount > rabbits)
      {
        cout << "\nYou cannot sell that many, please try again ";
        cin >> amount;
      }
      valid = planets[ship_pos].sellTo(good, amount, credits);
      rabbits -= amount;
      return true;
    break;
    default:
      return false;
    break;
  }
}

//method name: refuel
//parameters: none
//purpose: buys as much fuel as possible from the planet the ship is on, at most enough to fill the reserves to MAX_FUEL
//returns: true if any fuel was purchased, false otherwise
bool GalaxyTrader::refuel()
{
  int fuelPrice = planets[ship_pos].getFuel();
  int goodFuel = credits/fuelPrice;
  if (goodFuel <= 0)
    return false;
  else
    for(fuel; fuel < MAX_FUEL && goodFuel > 0; fuel++)
    {
      goodFuel --;
      credits -= fuelPrice;
    }
  return true;
}

//method name: move
//parameters: none
//purpose: immediately returns false if the user has no fuel
//         otherwise it asks the user what direction they want to move
//         then the ship's position is updated to reflect the move and fuel is decreased by one
//note: if the ship exceeds the limits of the array it should "reapear" on the other side
//valid inputs: l for left, r for right
//returns: true if the ship's position changed, false otherwise
bool GalaxyTrader::move()
{
  char choice;
  if(fuel <= 0)
    return false;
  cout << "What direction do you want to go captain? (l,r): ";
  cin >> choice;
  choice = toupper(choice);
  while (choice != 'R' && choice != 'L')
  {
    cout << "\nNot a valid direction, please try again. ";
    cin >> choice;
    choice = toupper(choice);
  }
  if (choice == 'R')
  {
   if (ship_pos == 9)
      ship_pos = 0;
    else
      ship_pos ++;
  }
  if (choice == 'L')
  {
    if (ship_pos == 0)
      ship_pos = 9;
    else
      ship_pos --;
  }
  fuel --;
  return true;
}

//method name: print_status
//parameters: none
//purpose: print the coordinates of the ship
//         the credits availble
//         currentfuel/MAX_FUEL
//         and everything in the ships cargo (should say it is empty if it contains nothing)
//returns: none
void GalaxyTrader::print_status() const
{
  cout << "Ship status: \n";
  cout << "\tCurrent space cordinates: " << ship_pos << endl;
  cout << "\tCredits availble: " << credits << endl;
  cout << "\tFuel reserves: " << fuel << "/5\n";
  cout << "Cargo status: \n";
  if (wolves > 0)
    cout << "\t" << wolves << " units of wolves\n";
  if (steaks > 0)
    cout << "\t" << steaks << " units of steaks\n";
  if (rabbits > 0)
    cout << "\t" << rabbits << " units of rabbits\n";
  else if ((wolves + steaks + rabbits) <= 0)
    cout << "\tEmpty\n";
}

//method name: print_planet
//parameters: none
//purpose: checks to see if the Planet the ship is on is empty
//         if it is print a message saying so
//         otherwise call the print method of the planet the ship is on
//returns: none
void GalaxyTrader::print_planet() const
{
  if (planets[ship_pos].isEmpty() == true)
  {
    cout << "Planet is inhospitable\n";
    
  }
  else
  {
    planets[ship_pos].print();
  }
}

//method name: scan
//parameters: none
//returns: false if the Planet the ship is at is empty, true if it is not
bool GalaxyTrader::scan() const
{
  if (planets[ship_pos].isEmpty() == true)
    return false;
  else
    return true;
}

//method name: areaScan
//parameters: none
//purpose: asks the user how wide a scan they would like to perform
//         then areaScan prints out a grid of 1 tall and 2*radius+1 wide
//         each spot on the grid contains either an [ ] or a [?]
//         [ ] represents a location with no planet
//         [?] represents a location with a planet (? should be replaced with the first character of the name of the planet)
//         the center of the grid represents where the ship currently is and should have a small arrow indicating where the ship currently i
//valid inputs: a number between 1 and SIZE
//returns: none
void GalaxyTrader::areaScan() const
{
}