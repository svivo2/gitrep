//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(int Value, Node * Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found
   else if (Tree->Value == Value)
      return true;

   // Recursively search for data value
   else if (Tree->Value > Value)
      return (SearchHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (SearchHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int Value, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Value = Value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->Value == Value)
      return false;

   // Recursively search for insertion position
   else if (Tree->Value > Value)
      return (InsertHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int Value)
{
   // Call tree insertion function
   return (InsertHelper(Value, Root));
}
//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::Delete(int Value, Node * &Tree)
{
  // Data value not found
  if (Tree == NULL)
     return false;

  // Data value found
  else if (Tree->Value == Value)
  {
    if(Tree->Left == NULL && Tree->Right == NULL)
    {
      delete Tree;
      Tree = NULL;
    }

    else if(Tree->Left == NULL)
    {
      Node* toDelete = Tree;
      Tree = Tree->Right;
      delete toDelete;
    }

    else if(Tree->Right == NULL)
    {
      Node* toDelete = Tree;
      Tree = Tree->Left;
      delete toDelete;
    }

    else
    {
      Node* toDelete = Tree->Left;
      while(toDelete->Right != NULL)
        toDelete = toDelete->Right;

      Tree->Value = toDelete->Value;
      Tree->Left = DeleteHelper(toDelete->Value, Tree->Left);
    }
    return true;
  }

  // Recursively search for data value
  else if (Tree->Value > Value)
     return (SearchHelper(Value, Tree->Left));
  else if (Tree->Value < Value)
     return (SearchHelper(Value, Tree->Right));
}
//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(int Value)
{
  return DeleteHelper(Value,Root);
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
     cout << " ( ";
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << " " << Tree->Value << " ";

      // Print right subtree
      PrintHelper(Tree->Right);
      cout << " ) ";
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

void BinaryTree::CountHelper(Node * Tree, int &count)
{
  if(Tree != NULL)
  {
    count++;
    CountHelper(Tree->Left,count);
    CountHelper(Tree->Right,count);
  }
}
int BinaryTree::Count()
{
  int count = 0;
  CountHelper(Root, count);
  return count;
}
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
  int size = 10;
  BinaryTree tree, tree2, tree3;
  for(int i = 0; i < size; i++)
  {
    if(tree.Insert(rand() % size))
      cout << "insertion successful\n";
    else
      cout << "insertion unsuccessful\n";

    if(tree2.Insert(i))
      cout << "insertion successful\n";
    else
      cout << "insertion unsuccessful\n";

    if(tree3.Insert(10 - i))
      cout << "insertion successful\n";
    else
      cout << "insertion unsuccessful\n";
  }
  cout << "Tree: " << tree.Count() << endl;
  cout << "Tree2: " << tree2.Count() << endl;
  cout << "Tree3: " << tree3.Count() << endl;
  cout << "Tree: " << tree.Height() << endl;
  cout << "Tree2: " << tree2.Height() << endl;
  cout << "Tree3: " << tree3.Height() << endl;
  while (tree.Delete() || tree2.Delete() || tree3.Delete())
  {
    tree.Print();
    tree2.Print();
    tree3.Print();
  }
}
