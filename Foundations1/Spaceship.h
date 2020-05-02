//-----------------------------------------------------
// Filename: Spaceship.h
// Purpose:  The header file for the Spaceship class
//-----------------------------------------------------

using namespace std;

class Spaceship {
  
  public:
    // Constructors
    Spaceship();
    Spaceship(const int crew, const string n, const long impulse, const bool shields);
    Spaceship(const Spaceship &otherShip);

    // Destructor
    ~Spaceship();

    // Setters (aka Mutators)
    bool SetCrewSize(const int c);
    void SetName(const string n);
    bool SetImpulseSpeed(const long i);
    void SetShieldsUp(const bool shields);

    // Getters (aka Accessors)
    int GetCrewSize() const;
    string GetName() const;
    long GetImpulseSpeed() const;
    bool GetShieldsUp() const;
    
    // Other
    void Print() const;
    void BattleStart();
    void BattleEnd();
    long CurrentSpeed() const;

  private: 
    const static long WARP_SPEED = 300000;  // speed of light in km/sec
    int crewSize;
    string name;
    long impulseSpeed;   // cruising speed in km/sec
    bool shieldsUp;
};