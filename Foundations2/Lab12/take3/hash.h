//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
using namespace std;
const int NONE = 0;
const int EMPTY = -1;
const int DELETED = -2;

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
public:
   // Constructors
   HashTable(int size);
   HashTable(const HashTable & ht);
   ~HashTable();

   // Methods
   bool Insert(int key, int value);
   bool Search(int key, int &value);
   bool Delete(int key);
   void Print();

private:
   // Private methods
   int Hash(int key);
   int Hash2(int index);

   // Private data
   int mSize;
   int *Value;
   int *Key;
};
