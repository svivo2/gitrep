#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 5;
const char BOAT = 'M';
const char HIT = 'X';
const char MISS = 'O';
const char DUPLICATE = 'D';
const char EMPTY = ' ';
const char QUIT = 'q';

// Print solutoin by row
void printSolution(char arr[])
{
  cout << "| ";
  for (int c = 0; c < 5; c++)
      cout << arr[c] << " | ";

  cout << "\n+---+---+---+---+---+\n";
}


// Print results by row
void printResults(char arr[])
{
  cout << "| ";
  for (int c = 0; c < 5; c++)
  {
    if (arr[c] != BOAT)
      cout << arr[c];
    else
      cout << " ";
    cout << " | ";
  }
  cout << "\n+---+---+---+---+---+\n";
}


int main()
{
  // Declare 2D array and choice variable
  char board[SIZE][SIZE];
  char choice = '\0';
  int hits = 0;
  int misses = 0;
  int tries = 0;
  int x = -1;
  int y = -1;

  // Initialize Board
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      board[i][j] = EMPTY;
    }
  }  

  // Place Boats
  board[0][1] = BOAT;
  board[1][0] = BOAT;
  board[1][3] = BOAT;
  board[2][2] = BOAT;
  board[4][4] = BOAT;

  // Get User Choice to attack or quit
  while(choice != QUIT)
  {
    cout << "Please enter a to Attack or q to Quit:\n";
    cin >> choice;
    if( choice == 'a')
    {
      //Get Coordinates
      while (x < 0 || x > 4)
      {
        cout <<  "Please enter the X coordinate for your attack within 0 - 4: \n";
        cin >> x;
      }
      while (y < 0 || y > 4)
      {
        cout <<  "Please enter the Y coordinate for your attack within 0 - 4: \n";
        cin >> y;
      }
      tries++;
      // Place hit on board
      if (board[4-y][x] == BOAT)
      {
        board[4-y][x] = HIT;
        hits++;
      }
      else if (board[4-y][x] == HIT || board[4-y][x] == DUPLICATE || board[4-y][x] == MISS)
      {
        board[4-y][x] = DUPLICATE;
        misses++;
      }
      else
      {
        board[4-y][x] = MISS;
        misses++;
      }

      // Reset x and y
      x = -1;
      y = -1; 

      // Display Results
      cout << "Hits: " << hits << "\tMisses: ";
      cout << misses << "\tAttempts: " << tries;
      cout << "\n+---+---+---+---+---+\n";

      for (int r = 0; r < SIZE; r++)
      {
        printResults(board[r]);
      }
    }
    else if( choice == QUIT)
    {
      cout << "\n+---+---+---+---+---+\n";
      for (int r = 0; r < SIZE; r++)
      {
        printSolution(board[r]);
      }

    }

  }

}