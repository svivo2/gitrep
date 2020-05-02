#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};
class Linkedlist
{
public:
  typedef element_type& reference;
  typedef const element_type& const_reference;
  Linkedlist(); //default constructor for empty list
  ~Linkedlist(); //destructor to free nodes dynamically created to support the linklist
  bool empty() const;
  void clear();
  reference back();
  const_reference back() const;
  reference front();
  const_reference front() const;
  Linkedlist& operator=(const Linkedlist& l);
  void pop_back ( );
  void pop_front ( );
  void push_back ( const element_type& x );
  void push_front ( const element_type& x );
  void sort ( );


  // constructor that initializes the linked list with n nodes,
  // with elem value from 0 to n-1
  explicit Linkedlist(unsigned int n);
  // print the linked list in the forward direction,
  // similar to the show function of lab6
  void check() const;
  // print the linked list in the backward direction,
  // similar to the reverse_show function of lab7
  void rcheck() const;
  // insert a node with value specified by x after the node
  // specified by pos. The first node has position 0.
  // if the number of nodes in the linked list is less than
  // pos, the node is inserted at the end.
  void insert(unsigned int pos, const element_type& x);
  // remove the node specified by pos.

private:
  Node* head;               // The front of the list
  Node* tail;               // The end of the list
  unsigned int numElements; // The number of elements in the list

};
