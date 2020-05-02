#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
  head = NULL;
  tail = NULL;

  numElements = 0;
}

Linkedlist::~Linkedlist()
{
  while (head != NULL)
  {
    Node * current = head;
    head = head->next;
    delete current;
  }
}

bool Linkedlist::empty() const
{
  if(head == NULL && tail == NULL)
    return true;
  else
    return false;
}

void Linkedlist::clear()
{
  Node * current = head;
  while (current->next != NULL)
  {
      Node* next = current->next;
      delete current;
      current = next;
      numElements--;
  }
  current = NULL;
}

void Linkedlist::push_back(const element_type& x)
{
  if(this->empty())
  {
    tail = new Node();
    tail->elem = x;
    tail->prev = NULL;
    tail->next = NULL;
    head = tail;
  }
  else
  {
    Node* node = new Node();
    node->elem = x;
    node->prev = tail;
    node->next = NULL;

    // Fold it into the list
    tail->next = node;

    // Move the tail
    tail = node;
  }
  numElements++;
}

void Linkedlist::push_front(const element_type& x)
{
  if(this->empty())
  {
    head = new Node();
    head->elem = x;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
  }
  else
  {
    Node* node = new Node();
    node->elem = x;
    node->next = head;
    node->prev = NULL;

    // Fold it into the list
    head->prev = node;

    // Move the tail
    head = node;
  }
  numElements++;
}


Linkedlist::Linkedlist(unsigned int n)
{
  if (n == 0)
  {
    head = NULL;
    tail = NULL;
  }
  if (n > 0)
  {
    // Create the first node
    head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    numElements++;
  }
  if (n > 1)
  {
    // Create a doubly linked list from the nodes
    for (int i = 1; i <= n - 1; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;

        // Fold it into the list
        tail->next = node;

        // Move the tail
        tail = node;

        node = NULL;
        delete node;
        numElements++;
    }
  }

}

void Linkedlist::check() const
{
  Node* current = head;

  if (current == NULL)
      cout << "It is an empty list!" << endl;

  int i = 0;
  while (current != NULL)
  {
      cout << "Node "          << setw(3) << i             << "   "
           << "Elem: "         << setw(3) << current->elem << "   "
           << "Address: "      << setw(8) << current       << "   "
           << "Next Address: " << setw(8) << current->next << "   "
           << "Prev Address: " << setw(8) << current->prev << "   "
           << endl;
      current = current->next;
      i++;
  }

  cout << "------------------------------------------------------------------------------------------" << endl;
}

void Linkedlist::rcheck() const
{
  Node* current = tail;

  if (current == NULL)
      cout << "It is an empty list!" << endl;

  int i = numElements - 1;
  while (current != NULL)
  {
      cout << "Node "          << setw(3) << i             << "   "
           << "Elem: "         << setw(3) << current->elem << "   "
           << "Address: "      << setw(8) << current       << "   "
           << "Next Address: " << setw(8) << current->next << "   "
           << "Prev Address: " << setw(8) << current->prev << "   "
           << endl;
      current = current->prev;
      i--;
  }

  cout << "------------------------------------------------------------------------------------------" << endl;
}

void Linkedlist::insert(unsigned int pos, const element_type& x)
{
  Node * current = head;
  while (pos-- != 0)
    current = current->next;

  Node * node = new Node();
  node->elem = x;
  current->next->prev = node;
  node->prev = current;
  node->next = current->next;
  current->next = node;
  numElements++;

  node = NULL;
  current = NULL;
  delete node;
  delete current;
}

void Linkedlist::sort ()
{
  Node* previous = tail->prev;
  while (tail->elem <= head->elem)
  {
    previous = tail->prev;
    head->prev = tail;
    tail->next = head;
    tail->prev = NULL;
    previous->next = NULL;
    head = tail;
    tail = previous;
    previous = NULL;
  }
}

//reference Linkedlist::back()
//{
//  return tail->prev->elem;
//}
