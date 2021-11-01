#include <iostream>
using namespace std;
#include "PassengerList.h"

PassengerList::PassengerList()
{
    Head = NULL;
}

PassengerList::PassengerList(const PassengerList & list)
{
    //Create a dummy node in our new list
    PassengerNode * copy = new PassengerNode();
    Head = copy;

    //Make a pointer to the beginning of the list we want to copy
    PassengerNode * ptr = list.Head;

    //While that pointer is valid
    while(ptr != NULL)
    {
        //Make a new blank node in our list
        copy->setNext(new PassengerNode());
        copy = copy->getNext();

        //Copy the current node from the copy list
        copy->setFirstName(ptr->getFirstName());
        copy->setLastName(ptr->getLastName());
        copy->setNext(NULL);

        //Advance the pointer in the copy list
        ptr = ptr->getNext();
    }

    //Delete that dummy node we created at the beginning
    copy = Head;
    Head = copy->getNext();
    delete copy;
}

PassengerList::~PassengerList()
{
    //Keep deleting the head until there's nothing left
    while(Head != NULL)
    {
        PassengerNode * ptr = Head;
        Head = Head->getNext();
        delete ptr;
    }
}

bool PassengerList::Confirm(const string fName, const string lName)
{
    //Create a pointer to the head
    PassengerNode * ptr = Head;

    //While the pointer is valid and we haven't found the node we're looking for, advance the pointer
    while((ptr != NULL) && (ptr->getFirstName() != fName) && (ptr->getLastName() != lName))
        ptr = ptr->getNext();

    //If we found the node, this expression will be true. Otherwise, false.
    if (ptr != NULL)
      cout << "Your reservation for " << fName << " " << lName << " has been confirmed.\n";
    else
      cout << "Passenger " << fName << " " << lName << " was not found.\n";
    return ptr != NULL;
}

bool PassengerList::Book(const string fName, const string lName)
{
  PassengerNode * current = Head;
  PassengerNode * previous = Head;
  while((current != NULL) && (current->getLastName() <= lName))
  {
    previous = current;
    current = current->getNext();
  }
  if (previous == NULL )
  {
    Head = new PassengerNode(fName, lName);
    Head->setNext(NULL);
    cout << "Booked " << fName << " " << lName << ".\n";

    previous = NULL;
    current = NULL;
    delete previous;
    delete current;

    return true;
  }
  else if (previous->getLastName() != lName)
  {
    previous->setNext(new PassengerNode(fName, lName));
    previous->getNext()->setNext(current);
    cout << "Booked " << fName << " " << lName << ".\n";


    previous = NULL;
    current = NULL;
    delete previous;
    delete current;

    return true;
  }
  else
  {
    cout << "Declined reservation for " << fName << " " << lName << ".\n";
    return false;
  }

}

bool PassengerList::Cancel(const string fName, const string lName)
{
    PassengerNode * current = Head;
    PassengerNode * previous = Head;

    //Advance current and previous until we find the node or we search the whole list
    while(current != NULL && current->getFirstName() != fName && current->getLastName() != lName)
    {
        previous = current;
        current = current->getNext();
    }

    //If current is null, we searched the whole list and found nothing (or the list was empty)
    if(current == NULL)
    {
        cout << "Could not cancel booking for " << fName << " " << lName << ".\n";
        return false;
    }
    else
        cout << "Cancelled booking for " << fName << " " << lName << ".\n";

    //If we're deleting the head, update the head. Else, reroute prev->next
    if(current == Head)
        Head = Head->getNext();
    else
        previous->setNext(current->getNext());

    //It is now safe to delete the node
    delete current;

    return true;
}


bool PassengerList::isEmpty()
{
    //Check if the head is null
    return Head == nullptr;
}



void PassengerList::Print()
{
    for (PassengerNode * ptr = Head; ptr != NULL; ptr = ptr->getNext())
        ptr->print();

    cout << " x\n";
}
