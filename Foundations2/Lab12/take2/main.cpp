/*
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

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
    Node * left;        // Pointer to the next node in the chain
    Node * right;        // Pointer to the previous node in the chain
};

// Print details about the given list, one Node per line
void inorder(Node* t)
{
  if(t != NULL)
  {
      inorder(t->left);
      cout << "Node "          << setw(3) << t            << "   "
           << "Elem: "         << setw(3) << t->elem << "   "
           << "Address: "      << setw(8) << t       << "   "
           << "Left Address: " << setw(8) << t->left << "   "
           << "Right Address: " << setw(8) << t->right << "   "
           << endl;
      inorder(t->right);
  }


    cout << "------------------------------------------------------------------------------------------" << endl;
}


Node* search(Node* t, int key, Node & parent)
{
  if(t == NULL)
    return t;
  else if(t->elem == key)
    return t;
  else if(t->elem > key)
    return search(t->left, key, *t);
  else
    return search(t->right, key, *t);
}

// Print details about the given list in reverse order, one Node per line
void insert(Node* t, int key)
{

  if(t == NULL)
  {
    Node* node = new Node();
    node->elem = key;
    node->left = NULL;
    node->right = NULL;
    return;

  }

  else if(t->elem >= key)
    insert(t->left, key);

  else
    insert(t->right, key);

}

int main()
{
    const int size = 15;

    // Create the first node
    Node* root = new Node();


    for (int i = 1; i <= size; i++)
    {
        insert(root,i);
    }
    inorder(root);


    root = NULL;
    delete root;

    return 0;
}
