#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//Binary search of the dictionary for a specific word (query)
bool check(vector<string> dictionary, int dictionarySize, int left, int right, string query)
{
  bool check = false;
  int middle;
  while(left <= right)
    {
      //Compute the midpoint
      middle = (left + right) / 2;

      //If target is at the midpoint, we've found it
      if (dictionary[middle] == query)
      {
        check = true;
        return check;
      }

      //Check if target is in bottom half of array
      else if (dictionary[middle] > query)
          right = middle - 1;

      //Else, target must be in top half
      else
          left = middle + 1;
    }
  return check;

}

//Swap two characters in a string
void swap(string& word, int i, int j)
{
  char temp = word[j];
  word[j] = word[i];
  word[i] = temp;
}

//Checks if the permutations vector already contains a certain word
//This handles the case in which words like "apple" and "apple" are
//considered separate cases by the permute function, but really these
//are the same word - the two p's are just switched.
bool contains(vector<string> permutations, string query)
{
  bool contains = false;
  while(!permutations.empty())
  {
    if(permutations.back() == query)
      contains = true;
    permutations.pop_back();
  }
  return contains;
}

//Generates all unique permutations of a given string
//and drops them into a vector
//NOTE: For this function to work correctly, the initial function call should be permute(permutations, word, 0);
void permute(vector<string>& permutations, string word, int k)
{
  if(k == word.length() && !contains(permutations, word))
    permutations.push_back(word);
  else
    for(int j = k; j < word.length(); j++)
    {
      swap(word, j, k);
      permute(permutations, word, k+1);
      swap(word, j, k);
    }
}

int main()
{
  vector<string> dictionary;
  string jumbleFile = "jumble.txt";
  string dictionaryFile = "dictionary.txt";
  int dictionarySize;
  vector<string> permutations;
  string word, dWord;
  ifstream bin(dictionaryFile.c_str());
  if (!bin)
    cout << "Could not open file " << jumbleFile << ". \n";
  else
  {
    bin >> dictionarySize;
    while (bin >> dWord)
    {
      dictionary.push_back(dWord);
    }
  }
  bin.close();
  ifstream din(jumbleFile.c_str());
  if (!din)
    cout << "Could not open file " << jumbleFile << ". \n";
  else
  {
    while(din >> word)
    {
      permute(permutations, word, 0);
      while(!permutations.empty())
      {
        if(check(dictionary, dictionarySize, 0, dictionarySize - 1, permutations.back()) == true)
          cout << word << " could be: " << permutations.back() << endl;
        permutations.pop_back();
      }
    }
  }
  din.close();


  return 0;
}
