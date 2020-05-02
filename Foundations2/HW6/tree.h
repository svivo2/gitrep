//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// Data node definition
class Node
{
   public:
   int mNum;
   string mStreet;
   Node *mLeft;
   Node *mRight;
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
   bool Search(int num, string street);
   bool Insert(int num, string street);
   bool Delete(int num, string street);
   void Print();
   int Count();
   int Height();
   bool Empty();

 private:
   // Helper functions
   bool EmptyHelper(Node * Tree);
   bool SearchHelper(int num, string street, Node * &Tree);
   bool InsertHelper(int num, string street, Node * &Tree);
   Node * DeleteHelper(int num, string street, Node * &Tree);
   void PrintHelper(Node * Tree);
   void CountHelper(Node * Tree, int &count);
   int HeightHelper(Node * Tree, int height);
   // Tree pointer
   Node *Root;
};
