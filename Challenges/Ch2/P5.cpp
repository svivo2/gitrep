#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
  //ifstream cin;
  //cin.open("P5.txt");
  int numCases, numShuffles, shuffle = 0;
  int shuffles[100][52];
  string s, temp;
  char c;
  cin >> numCases;
  while(numCases-- > 0)
  {
    string deck[52], newDeck[52] = {"2 of Clubs","3 of Clubs","4 of Clubs",
                      "5 of Clubs",
                      "6 of Clubs","7 of Clubs","8 of Clubs","9 of Clubs",
                      "10 of Clubs","Jack of Clubs","Queen of Clubs",
                      "King of Clubs","Ace of Clubs","2 of Diamonds",
                      "3 of Diamonds","4 of Diamonds","5 of Diamonds",
                      "6 of Diamonds","7 of Diamonds","8 of Diamonds",
                      "9 of Diamonds","10 of Diamonds","Jack of Diamonds",
                      "Queen of Diamonds","King of Diamonds","Ace of Diamonds",
                      "2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts",
                      "6 of Hearts","7 of Hearts","8 of Hearts","9 of Hearts",
                      "10 of Hearts","Jack of Hearts","Queen of Hearts",
                      "King of Hearts","Ace of Hearts","2 of Spades",
                      "3 of Spades","4 of Spades","5 of Spades","6 of Spades",
                      "7 of Spades","8 of Spades","9 of Spades",
                      "10 of Spades","Jack of Spades","Queen of Spades",
                      "King of Spades","Ace of Spades"};


    cin >> numShuffles;
    for(int i = 0; i < numShuffles; i++)
    {
      //cout << "Num Shuffles: " << i << endl;
      for(int j = 0; j < 52; j++)
      {
        cin >> shuffles[i][j];
      //  cout << "Shuffles[" << i << "][" << j
      //       << "]: " << shuffles[i][j] << endl;
      }
    }
    cin.get(c);
    while(getline(cin,s)&&(!s.empty()))
    {
      istringstream tmp(s);
      tmp >> shuffle;
      //cout << "Shuffle: " << shuffle << endl;
      //cout << "Original Deck: \n";
      for(int i  = 0; i < 52; i++)
      {
        deck[i] = newDeck[i];
      //  cout << deck[i] << endl;
      }
      //cout << "New Deck: \n";
      for(int i = 0; i < 52; i++)
      {
        //cout << shuffles[shuffle - 1][i] - 1 << " " << i
        //     << " " << deck[i] << " " << newDeck[i] << endl;
        if((shuffles[shuffle - 1][i] - 1) != i)
        {
          newDeck[i] = deck[(shuffles[shuffle - 1][i] - 1)];
        }
        else
        {
          newDeck[i] = deck[i];
        }
        //cout << newDeck[i] << endl;
      }
    }
    //cout << endl;
    for(int i = 0; i < 52; i++)
      cout << newDeck[i] << endl;

    cout << endl;
  }
}
