//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

// Data node definition
class Node
{
   public:
   int Value;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the binary tree class interface.
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(int Value);
   bool Insert(int Value);
   bool Delete(int Value);
   void Print();
   int Count();
   int Height();

 private:
   // Helper functions
   bool SearchHelper(int Value, Node * Tree);
   bool InsertHelper(int Value, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(int Value, Node * &Tree);
   void PrintHelper(Node * Tree);
   void CountHelper(Node * Tree, int &count);
   int HeightHelper(Node * Tree, int height);
   // Tree pointer
   Node *Root;
};
