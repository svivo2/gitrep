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
  string Value;
  int Freq;
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
    bool Search(string Value);
    bool Insert(string Value);
    bool Delete(string Value);
    void Print();
    void NumWords();
    void TotalNumWords();
    void TimesWord(string Value);

  private:
    // Helper functions
    void DestructHelper(Node * Tree);
    bool SearchHelper(string Value, Node * Tree);
    bool InsertHelper(string Value, Node * &Tree);
    Node * DeleteHelper(string Value, Node * &Tree);
    void PrintHelper(Node * Tree);
    int NumWordsHelper(Node * Tree);
    int TotalNumWordsHelper(Node * Tree);
    int TimesWordHelper(string Value, Node * Tree);

  // Tree pointer
  Node *Root;
};
