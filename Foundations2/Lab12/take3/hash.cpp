//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   mSize = size;
   Value = new int[mSize];
   Key = new int[mSize];

   for (int index=0; index < mSize; index++)
   {
      Value[index] = NONE;
      Key[index] = EMPTY;
   }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   mSize = ht.mSize;
   Value = new int[mSize];
   Key = new int[mSize];

   for (int index=0; index < mSize; index++)
   {
      Value[index] = ht.Value[index];
      Key[index] = ht.Key[index];
   }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   delete []Value;
   delete []Key;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(int key, int value)
{
  int count = 0;
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY) && (mSize > count))
   {
      index = Hash2(index);
      count++;
   }
   // Insert value into hash table
   Value[index] = value;
   Key[index] = key;
   return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(int key, int &value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Return value from hash table
   if (Key[index] == key)
      value = Value[index];
   return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(int key)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Delete value from hash table
   if (Key[index] == key)
   {
      Value[index] = NONE;
      Key[index] = DELETED;
      return true;
   }
   return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(int key)
{
   return key % mSize;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
  cout << "\n** Collision **\n";
  return (index+1) % mSize;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
   cout << "Index\t" << "Value\t" << "Key\n";
   for (int index=0; index < mSize; index++)
      cout << index << "\t"
           << Value[index] << "\t"
           << Key[index] << "\n";
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
   // Initialize random number generator
   srandom(time(NULL));

  int key, value = 0;
  int SIZE = 0;
  int COUNT = 0;
  int MAX = 0;

  cout << "Please enter SIZE, COUNT, and MAX, each followed by a space\n";
  cin >> SIZE >> COUNT >> MAX;

  HashTable h(SIZE);

  for(int i = 0; i < COUNT; i++)
  {
    key = random() % MAX;
    value = random() % MAX;
    h.Insert(key, value);
  }
  h.Print();
}
