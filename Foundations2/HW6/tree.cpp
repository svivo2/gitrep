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
bool BinaryTree::SearchHelper(int num, string street, Node * &Tree)
{
  // Data value not found
  if (Tree == NULL)
    return false;

  // Data value found
  else if ((Tree->mNum == num) && (Tree->mStreet == street))
  {
    cout << "Found: " << Tree->mNum << " " << Tree->mStreet << endl;
    return true;
  }

  // Recursively search for data value
  else if (Tree->mStreet > street)
    return (SearchHelper(num, street, Tree->mLeft));
  else if (Tree->mStreet < street)
    return (SearchHelper(num, street, Tree->mRight));
  else if (Tree->mNum > num)
    return (SearchHelper(num, street, Tree->mLeft));
  else if (Tree->mNum < num)
    return (SearchHelper(num, street, Tree->mRight));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int num, string street)
{
   // Call tree searching function
   return (SearchHelper(num, street, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int num, string street, Node * &Tree)
{
  // Insert data into the tree
  if (Tree == NULL)
  {
    Tree = new Node;
    Tree->mNum = num;
    Tree->mStreet = street;
    Tree->mLeft = NULL;
    Tree->mRight = NULL;
    cout << "Inserted: " << num << " " << street << endl;
    return true;
  }

  // Data value already inserted
  else if ((Tree->mNum == num) && (Tree->mStreet == street))
    return false;

  // Recursively search for insertion position
  else if (Tree->mStreet > street)
    return (InsertHelper(num, street, Tree->mLeft));
  else if (Tree->mStreet < street)
    return (InsertHelper(num, street, Tree->mRight));
  else if (Tree->mNum > num)
     return (InsertHelper(num, street, Tree->mLeft));
  else if (Tree->mNum < num)
     return (InsertHelper(num, street, Tree->mRight));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int num, string street)
{
   // Call tree insertion function
   return (InsertHelper(num, street, Root));
}
//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
Node * BinaryTree::DeleteHelper(int num, string street, Node * &Tree)
{
  cout << "DeleteHelper:\n";
  //Node was not found, so return false
  if(Tree == NULL)
      return Tree;

  else if (Tree->mStreet > street)
    return (DeleteHelper(num, street, Tree->mLeft));
  else if (Tree->mStreet < street)
    return (DeleteHelper(num, street, Tree->mRight));
  else if (Tree->mNum > num)
     return (DeleteHelper(num, street, Tree->mLeft));
  else if (Tree->mNum < num)
     return (DeleteHelper(num, street, Tree->mRight));

  //Node was found
  else
  {
    if(Tree->mLeft == NULL && Tree->mRight == NULL)
    {
      delete Tree;
      Tree = NULL;
    }

    else if(Tree->mLeft == NULL)
    {
      Node* toDelete = Tree;
      Tree = Tree->mRight;
      delete toDelete;
    }

    else if(Tree->mRight == NULL)
    {
      Node* toDelete = Tree;
      Tree = Tree->mLeft;
      delete toDelete;
    }

    else
    {
      Node* toDelete = Tree->mLeft;
      while(toDelete->mRight != NULL)
        toDelete = toDelete->mRight;

      Tree->mNum = toDelete->mNum;
      Tree->mStreet = toDelete->mStreet;
      Tree->mLeft = DeleteHelper(toDelete->mNum, toDelete->mStreet, Tree->mRight);
    }
  }
  return Tree;
}
//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(int num, string street)
{
  cout << "Delete\n";
  return (DeleteHelper(num, street, Root) == NULL);
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
     cout << " - ";
      // Print left subtree
      PrintHelper(Tree->mLeft);

      // Print node value
      cout << Tree->mNum << " " << Tree->mStreet << "\n";

      // Print right subtree
      PrintHelper(Tree->mRight);
      cout << " - ";
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
    CountHelper(Tree->mLeft,count);
    CountHelper(Tree->mRight,count);
  }
}
int BinaryTree::Count()
{
  int count = 0;
  CountHelper(Root, count);
  return count;
}
bool BinaryTree::EmptyHelper(Node * Tree)
{
  return (Tree == NULL);
}
bool BinaryTree::Empty()
{
  return EmptyHelper(Root);
}
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
/*int main()
{
  int size = 10;
  int val = 0;
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
  while (!tree.Empty() || !tree2.Empty() || !tree3.Empty())
  {
    val = rand() % (size+1);

    cout << "Deleted " << val << " ";
    cout << tree.Delete(val) << " " << tree2.Delete(val)
         << " " << tree3.Delete(val) << endl;

    cout << "tree1: "; tree.Print(); cout << endl;
    cout << "tree2: "; tree2.Print(); cout << endl;
    cout << "tree3: "; tree3.Print(); cout << endl;
  }
}*/
