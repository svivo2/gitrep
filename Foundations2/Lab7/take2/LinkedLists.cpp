/*
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;

    if (current == NULL)
        cout << "It is an empty list!" << endl;

    int i = 0;
    while (current != NULL)
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }

    cout << "----------------------------------------------------------------------" << endl;
}

int main()
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }

    // Set the properties of the last Node (including setting 'next' to NULL)
    current->elem = size;
    current->next = NULL;
    show(head);

    // TODO:

    //Deleting head
    Node * temp = head;
    head = head->next;
    delete temp;
    show(head);

    //Deleting end node;
    current = head;
    Node * previous = head;
    while (current->next != NULL)
    {
      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
    current = previous;
    previous = NULL;
    delete previous;
    show(head);
    current = head;

    // Adding 0 - 9 into list at beginning
    int n = 0;
    while (n < 10)
    {
      temp = new Node();
      temp->next = head;
      head = temp;
      head->elem = n++;
      temp = NULL;
      delete temp;
    }
    current = head;

    show(head);

    //Adding 0 - 9 into list at beginning
    Node * next = NULL;
    while (current->elem != 7)
    {
      current = current->next;
      next = current->next;
    }
    n = 0;
    while(n < 10)
    {
      temp = new Node();
      temp->next = current->next;
      current->next->elem = n++;
      current = current->next;

      temp = NULL;
      delete temp;
    }

    show(head);

    // Clean up
    current = head;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
