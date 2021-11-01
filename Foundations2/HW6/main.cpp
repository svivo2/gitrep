#include "tree.h"

int main()
{
   // Local variables
   int num, tNum, count = 0;
   float lat, lon = 0;
   string street, tStreet = "";
   char ch = ' ';
   char choice = '\0';
   BinaryTree addressTree;
   int size = 10000;

   // Open input file
   ifstream din;
   din.open("input1.txt");

   // Loop reading address information
   while ((din >> lat >> lon >> num) && (count++ < size))
   {
      // Skip space after num
      din.get(ch);

      // Read rest of line
      getline(din, street);

      // Add to BinaryTree
      addressTree.Insert(num, street);

    }

    addressTree.Print();

    while(choice != 'q')
    {
      cout << "Enter \"s\" to search address and \"q\" to quit: ";
      cin >> choice;

      if (choice == 's')
      {
        cout << "Please enter the house number, followed by a space, followed by the street name: ";
        cin >> tNum;
        cin.get(ch);
        getline(cin, tStreet);
        addressTree.Search(tNum, tStreet);
      }
    }
}
