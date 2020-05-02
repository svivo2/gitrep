//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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
    DestructHelper(Root);
}

void BinaryTree::DestructHelper(Node* Tree)
{
    if(Tree != NULL)
    {
        DestructHelper(Tree->Left);
        DestructHelper(Tree->Right);
        delete Tree;
    }
}
//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string Value, Node * Tree)
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
bool BinaryTree::Search(string Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string Value, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Value = Value;
      Tree->Freq = 1;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->Value == Value)
   {
     Tree->Freq++;
     return true;
   }

   // Recursively search for insertion position
   else if (Tree->Value > Value)
      return (InsertHelper(Value, Tree->Left));
   else if (Tree->Value < Value)
      return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string Value)
{
   // Call tree insertion function
   return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << " " << Tree->Value << " ";

      // Print right subtree
      PrintHelper(Tree->Right);
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
int BinaryTree::TotalNumWordsHelper(Node * Tree)
{
  int right, left;
  if(Tree == NULL)
    return 0;
  else if ((Tree->Right == NULL) && (Tree->Left == NULL))
    return Tree->Freq;
  else
  {
    left = TotalNumWordsHelper(Tree->Left);
    right = TotalNumWordsHelper(Tree->Right);
    return left + right;
  }
}

void BinaryTree::TotalNumWords()
{
  cout << "There are " << TotalNumWordsHelper(Root) << " words in this tree.\n";
}

int BinaryTree::NumWordsHelper(Node * Tree)
{
  int right, left;
  if(Tree == NULL)
    return 0;
  else if(Tree->Right == NULL && Tree->Left == NULL)
    return 1;
  else
  {
    left = NumWordsHelper(Tree->Left);
    right = NumWordsHelper(Tree->Right);
    return left + right;
  }

}

void BinaryTree::NumWords()
{
  cout << "There are " << NumWordsHelper(Root) << " distinct words in this tree.\n";
}

bool BinaryTree::Delete(string Value)
{
    return DeleteHelper(Value, Root);
}

Node * BinaryTree::DeleteHelper(string Value, Node * &Tree)
{
  //Node was not found, so return false
  if(Tree == NULL)
      return NULL;

  //Search left
  else if(Tree->Value > Value)
      Tree->Left = DeleteHelper(Value, Tree->Left);

  //Search right
  else if(Tree->Value < Value)
      Tree->Right = DeleteHelper(Value, Tree->Right);

  //Node was found
  else
  {
    if(Tree->Freq > 1)
      Tree->Freq--;

    else if(Tree->Left == NULL && Tree->Right == NULL)
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
  }

  return Tree;
}
int BinaryTree::TimesWordHelper(string Value, Node * Tree)
{
  // Data value not found
  if (Tree == NULL)
     return 0;

  // Data value found
  else if (Tree->Value == Value)
     return Tree->Freq;

  // Recursively search for data value
  else if (Tree->Value > Value)
     return (SearchHelper(Value, Tree->Left));
  else if (Tree->Value < Value)
     return (SearchHelper(Value, Tree->Right));
}
void BinaryTree::TimesWord(string Value)
{
  cout << Value << " is stored " << TimesWordHelper(Value,Root) << " times.\n";
}


//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
  BinaryTree tree;
  char choice = '\0';
  string word;
  string wordsFile;
  cout << "Which of the following choices would you like?\n"
    << "1) Insert a word\n"
    << "2) Insert words from a file\n"
    << "3) Delete a word\n"
    << "4) Print out the number of distinct words in the tree\n"
    << "5) Print out the total number of words in the tree\n"
    << "6) Print out the number of times a particular word is stored in the tree\n"
    << "7) Print out the depth of the node storing a particular word in the tree\n"
    << "8) Print out the height of the tree\n"
    << "9) Quit\n";

  while(choice != '9')
  {
    cin >> choice;
    if (choice == '1')
    {
      cout << "\nWhat word would you like to insert? ";
      cin >> word;
      tree.Insert(word);
    }
    if (choice == '2')
    {
      cout << "\nWhat is the name of the file? ";
      cin >> wordsFile;
      ifstream fin(wordsFile.c_str());
      while(fin >> word)
        tree.Insert(word);
      fin.close();
    }
    if (choice == '3')
    {
      cout << "\nWhat word would you like to delete? ";
      cin >> word;
      tree.Delete(word);
    }
    if (choice == '4')
      tree.NumWords();
    if (choice == '5')
      tree.TotalNumWords();
    if (choice == '6')
    {
      cout << "What word are you looking for? ";
      cin >> word;
      tree.TimesWord(word);
    }

  }
}
