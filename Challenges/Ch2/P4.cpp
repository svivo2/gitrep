#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream din;
  din.open("P4.txt");
  int numWords = 0;
  din >> numWords;
  string *dictionary = new string[numWords];
  string word;
  for (int i = 0; i < numWords; i++)
  {
    din >> dictionary[i];
    cout << "Length: " << dictionary[i].length() << " ";
    for(int j = 0; j < dictionary[i].length(); j++)
      cout << dictionary[i][j];

    cout << endl;
  }
  din >> word;
  cout << "Word: Length"
}
