#include <iostream>
using namespace std;
#include "PassengerNode.h"

class PassengerList
{
    public:
        PassengerList();
        PassengerList(const PassengerList& list);
        ~PassengerList();

        bool Confirm(const string fName, const string lName);
        bool Book(const string fName, const string lName);
        bool Cancel(const string fName, const string lName);

        bool isEmpty();
        void Print();

    private:
        PassengerNode * Head;
};