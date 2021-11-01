//-----------------------------------------------------
// Filename: Spaceship.cpp
// Purpose:  The implementation of the Spaceship class
//-----------------------------------------------------

#include <iostream>
#include "Spaceship.h"
using namespace std;

//----------- Constructors and Destructors ----------

// Default constructor
Spaceship::Spaceship() 
{
    crewSize = 0;
    name = "NoName";
    impulseSpeed = 0;
    shieldsUp = false;
}

// Non-default constructor
Spaceship::Spaceship(const int crew, const string n, const long impulse, const bool shields)
{
    crewSize = crew;
    name = n;
    impulseSpeed = impulse;
    shieldsUp = shields;
}

// Copy constructor
Spaceship::Spaceship(const Spaceship &otherShip)
{
    crewSize = otherShip.crewSize;
    name = otherShip.name;
    impulseSpeed = otherShip.impulseSpeed;
    shieldsUp = otherShip.shieldsUp;
}

// Destructor (already completed for you)
Spaceship::~Spaceship() { }

//----------- Setters -------------------------------

// SetCrewSize
bool Spaceship::SetCrewSize(const int c)
{
    cout << "SetCrewSize\n";
    crewSize = c;
}

// SetName
void Spaceship::SetName(const string n)
{
    cout << "SetName\n";
    name = n;
}

// SetImpulseSpeed
bool Spaceship::SetImpulseSpeed(const long i)
{
    cout << "SetImpulseSpeed\n";
    impulseSpeed = i;
}

// SetShieldsUp
void Spaceship::SetShieldsUp(const bool shields)
{
    cout << "SetShieldsUp\n";
    shieldsUp = shields;
}

//----------- Getters -------------------------------

// GetCrewSize
int Spaceship::GetCrewSize() const
{
    cout << "GetCrewSize\n";
    return(crewSize);
}


// GetName
string Spaceship::GetName() const
{
    cout << "GetName\n";
    return(name);
}

// GetImpulseSpeed
long Spaceship::GetImpulseSpeed() const
{
    cout << "GetImpulseSpeed\n";
    return(impulseSpeed);
}

// GetShieldsUp
bool Spaceship::GetShieldsUp() const
{
    cout << "GetShieldsUp\n";
    return(shieldsUp);
}

//----------- Other ---------------------------------

// Print
void Spaceship::Print() const 
{   
    locale mylocale("");
    cout.imbue(mylocale);
    cout << "Name: " << name << endl; 
    cout << "Crew Size: " << crewSize << " crew members." << endl;
    cout << "Impulse Speed: " << impulseSpeed << " km/sec." << endl;
    cout << "Shields Up: ";
    if (shieldsUp) 
        cout << "TRUE" << endl;
    else 
        cout << "FALSE" << endl;
}


// BattleStart
void Spaceship::BattleStart()
{
    SetShieldsUp(true);
}


// BattleEnd
void Spaceship::BattleEnd()
{
    SetShieldsUp(false);
}

// CurrentSpeed
long Spaceship::CurrentSpeed() const
{
    if(GetShieldsUp() == true) return(GetImpulseSpeed());
    else return(WARP_SPEED);
}
