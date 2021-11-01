#include <iostream>
using namespace std;

class PassengerNode
{
  public:
    // Constructors
    PassengerNode();
    PassengerNode(string fName, string lName);
    PassengerNode(const PassengerNode & node);
    ~PassengerNode();

    // Get methods
    string getFirstName() const;
    string getLastName() const;
    PassengerNode * getNext() const;

    // Set Methods
    void setFirstName(string fName);
    void setLastName(string lName);
    void setNext(PassengerNode * next);

    // Other Methods
    void print() const;

  private:
    string FirstName;
    string LastName;
    PassengerNode * Next;
};