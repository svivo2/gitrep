#include <iostream>
using namespace std;
#include "PassengerNode.h"

PassengerNode::PassengerNode()
{
  FirstName = "";
  LastName = "";
  Next = NULL;
}

PassengerNode::PassengerNode(string fName, string lName)
{
  FirstName = fName;
  LastName = lName;
  Next = NULL;
}

PassengerNode::PassengerNode(const PassengerNode & node)
{
  FirstName = node.FirstName;
  LastName = node.LastName;
  Next = node.Next;
}

PassengerNode::~PassengerNode()
{
}

string PassengerNode::getFirstName() const
{
  return FirstName;
}

string PassengerNode::getLastName() const
{
  return LastName;
}

PassengerNode * PassengerNode::getNext() const
{
  return Next;
}

void PassengerNode::setFirstName(string fName)
{
  FirstName = fName;
}

void PassengerNode::setLastName(string lName)
{
  LastName = lName;
}

void PassengerNode::setNext(PassengerNode * next)
{
  Next = next;
}

void PassengerNode::print() const
{
  cout << FirstName << " " << LastName << " -> ";
}
