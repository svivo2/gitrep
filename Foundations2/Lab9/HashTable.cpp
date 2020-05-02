//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "HashTable.h"

int SIZE = 40;
int MAX = 1000;
int collisions = 0;
int COUNT;
int insertCount = 0;
//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = SIZE;
   Value = new int[Size];
   Key = new int[Size];

   for (int index=0; index < Size; index++)
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
   Size = ht.Size;
   Value = new int[Size];
   Key = new int[Size];

   for (int index=0; index < Size; index++)
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
   // Find desired key
  int index = Hash(key);
  while ((Key[index] != key) && (Key[index] != EMPTY))
    index = Hash2(index);

  // Insert value into hash table
  if (insertCount < SIZE)
  {
    Value[index] = value;
    Key[index] = key;
    insertCount++;
  }
  return (insertCount < SIZE);

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
   return key % Size;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
  cout << "Collisions = " << ++collisions << endl;
  return (index+1) % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
   cout << "Index\t" << "Value\t" << "Key\n";
   for (int index=0; index < Size; index++)
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
  char choice = '\0';
  while (choice != '9')
  {
    cout << "\nPlease enter choice 1. Continue, 9. Exit. ";
    cin >> choice;

    collisions = 0;

    HashTable ht(SIZE);

    cout << "\nPlease enter COUNT value: ";
    cin >> COUNT;

    for (int i = 0; i < COUNT; i++)
      ht.Insert(random() % MAX, random() % MAX);
  ht.Print();

  }
}
