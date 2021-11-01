#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  ofstream outfile;
  outfile.open("words.txt");
  if (outfile.fail())
  {
    cout << "Error: could not open output file\n";
    exit (EXIT_FAILURE);
  }
   // Loop printing phrase
   string phrase = "A quick brown fox jumps over the lazy dog.";
   for (int i = 0; i < 10; i++)
      outfile << phrase << endl;
   outfile.close();
    // Open "words.txt" file here
   ifstream infile;
   infile.open("words.txt");
    string word;
    while (infile >> word)
      cout << word << " ";
    cout << endl;
    // Close "words.txt" file here
    infile.close();
   return 0;
}