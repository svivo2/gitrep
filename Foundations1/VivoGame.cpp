//-------------------------------------------------------------------------------
// Name:  hw5.cpp
// Purpose:  To play a simple Pokemon game using 2D arrays
// Authors:  starter code:  Joshua Burbridge and Susan Gauch
//           completed code:  YOUR NAME(S) HERE
// Date:  April, 2018
//-------------------------------------------------------------------------------
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

//Character map for user moves
const char UP = 'W';
const char LEFT = 'A';
const char DOWN = 'S';
const char RIGHT = 'D';

//Character map for tile types
const char START = 'S';
const char FINISH = 'F';
const char SPACE = ' ';   
const char WARP_LEFT = '<';
const char WARP_RIGHT = '>';
const char WARP_UP = '^';
const char WARP_DOWN = 'v';
const char BOX = 'X';
const char CHOICE = 'C';
const char TRACK = 'o';

//Character map for tile types
const char PLAYER = 'A';

//-----------------------------------------------------------------------------------
// Name:  init
// Purpose:  This function opens a file, reads the dimensions of the map, and loads a map into the 2D array
//           It prints an error message to cerr if the file cannot be opened.
//           Any '.' in the map file are converted to spaces in the array.
// Parameters:  filename, const string, the file holding the map
//              map, 2D array of characters, the map filled in from the file
//              path, 2D array of characters, sets the path to the start location
//              playerRow, int, the player row location (updated by fn)
//              playerCol, int, the player col location (updated by fn)
// Returns: void
//-----------------------------------------------------------------------------------
void init(const string filename, char map[ROWS][COLS], char path[ROWS][COLS], int &playerRow, int &playerCol)
{
    //Open the file
    ifstream din(filename.c_str());
    if (!din)
       cerr << "Could not open " << filename << "\n.";
    else
    {
       //Set the player location
       playerRow = ROWS - 1;   
       playerCol = 0;        
   
       //Iterate over the rows and the columns
       for(int row = 0; row < ROWS; row++)
           for(int col = 0; col < COLS; col++)
           {
               //Read the data into the map
               din >> map[row][col];
               if (map[row][col] == '.')
                  map[row][col] = SPACE;  //convert from the . in the file to SPACE in the array
   
               //Init the path with the START and FINISH locations
               //Fill the rest of the path with spaces
               if (map[row][col] == START || map[row][col] == FINISH)
                   path[row][col] = map[row][col];
               else
                   path[row][col] = SPACE;
           }
   
       //Close the file
       din.close();
   }
}
   
//-----------------------------------------------------------------------------------
// Name:  print
// Purpose:  This function prints the map to the screen
// Parameters:  map, const 2D array of characters, stores the map
//              path, const 2D array of characters, stores the player path
//              playerRow, const int, the player row location
//              playerCol, const int, the player col location
// Returns: void
//-----------------------------------------------------------------------------------
void print(const char map[ROWS][COLS], const char path[ROWS][COLS], const int playerRow, const int playerCol)
{
cout << "Here is the map and path.  The legend is:\n"
     << "   S - start, F - finish\n"
     << "   < - warp left, > - warp right, ^ - warp up, v - warp down\n"
     << "   X - box, C - choice \n"
     << "   A - your location, o - your track\n";

    // print the map top border
    cout << "\nMAP:\t\t\t\t\tPATH:\n-";
    for(int col = 0; col < COLS; col++)
        cout << "----";
    cout << "\t-";

    // print the path top border
    for(int col = 0; col < COLS; col++)
        cout << "----";
    cout << "\n";

    // print the map contents and the path
    // replace any . stored in the array with spaces on screen to look nicer
    for(int row= 0; row < ROWS; row++)
    {
        // print the map
        cout << "|";
        for(int col = 0; col < COLS; col++)
        {
            if (playerRow == row && playerCol == col)
                cout << setw(2) << PLAYER << setw(2) << " |";
            else
                cout << setw(2) << map[row][col] << setw(2) << " |";
        }

        // print the path
        cout << "\t";
        cout << "|";
        for(int col = 0; col < COLS; col++)
        {
            if (playerRow == row && playerCol == col)
                cout << setw(2) << PLAYER << setw(2) << " |";
            else
                cout << setw(2) << path[row][col] << setw(2) << " |";
        }

        // print the map bottom border
        cout << "\n-";
        for(int col = 0; col < COLS; col++)
            cout << "----";

        // print the path bottom border
        cout << "\t-";
        for(int col = 0; col < COLS; col++)
            cout << "----";
        cout << "\n";
    }
    cout << "\n";
}

//-----------------------------------------------------------------------------------
// Name:  gameOver
// Purpose:  This function checks to see if the game is over, i.e., the player
//           has reached the FINISH tile.
// Parameters:  ???
// Returns:  true if the player has reached the FINISH tile; false otherwise
//-----------------------------------------------------------------------------------
bool gameOver(const char map[ROWS][COLS], const char path[ROWS][COLS], const int &playerRow, const int &playerCol)
{
  bool gameOver = false;
  if(map[playerRow][playerCol] == FINISH)
    gameOver = true;
  return(gameOver);
}

//-----------------------------------------------------------------------------------
// Name:  getMove
// Purpose:  This function gets the next move direction from the user.
//           It keeps asking until a valid direction is entered
// Parameters:  ????
// Returns:  move, char, the valid character entered
//-----------------------------------------------------------------------------------
char getMove(const string Command)
{
  char choice;

  cout << Command << "\t";
  cin >> choice;
  choice = toupper(choice);

  while (choice != 'W' && choice != 'S' && choice != 'D' && choice != 'A')
  {
    cout << "You must enter w, a, s, or d Try again:\t";
    cin >> choice;
    choice = toupper(choice);
  }
  return(choice);
}

//-----------------------------------------------------------------------------------
// Name:  legal
// Purpose:  This function checks whether or not the user can  make the move requested
//           by the user.  Illegal moves are those that would move the user off the map
//           or land the user in a box.
// Parameters: ???
// Returns:  true if the user can make the move, false otherwise
//-----------------------------------------------------------------------------------
bool legal(const char choice, const char map[ROWS][COLS], const char path[ROWS][COLS], const int &playerRow, const int &playerCol)
{
  bool legal = true;
  switch (choice)
  {
    case UP :
      if ((playerRow - 1) < 0 || map[playerRow - 1][playerCol] == BOX )
        legal = false;
      break;
    case LEFT :
      if ((playerCol - 1) < 0 || map[playerRow][playerCol - 1] == BOX )
        legal = false;
      break;
    case DOWN:
      if ((playerRow + 1) > 7 || map[playerRow + 1][playerCol] == BOX )
        legal = false;
      break;
    case RIGHT:
      if ((playerCol + 1) > 7 || map[playerRow][playerCol + 1] == BOX )
        legal = false;
      break;
    default:
      legal = false;
      break;

  }
  return(legal);
}

//-----------------------------------------------------------------------------------
// Name:  makeMove
// Purpose:  This makes the move selected by the user.
//           It assumes that the move has already been checked and is legal.
//           It updates the player' location and adds that location to the PATH.
//           It then examines the tile the user just moved to to see if it causes any
//           side effects.  
//           If the new tile is a space tile, keep going.
//             (i.e., warping to another location);  if so, it then
//           updates the player location again
// Parameters: ???
// Returns:  void
//-----------------------------------------------------------------------------------
void makeMove(const char choice, char map[ROWS][COLS], char path[ROWS][COLS], int &playerRow, int &playerCol)
{
  switch (choice)
  {
    case UP :
      do
        {
          playerRow = playerRow - 1;
          path[playerRow][playerCol] = TRACK;
        }while(map[playerRow][playerCol] == SPACE);
      break;
    case DOWN :
      do
        {
          playerRow = playerRow + 1;
          path[playerRow][playerCol] = TRACK;
        }while(map[playerRow][playerCol] == SPACE);
      break;
    case LEFT :
      do
        {
          playerCol = playerCol - 1;
          path[playerRow][playerCol] = TRACK;
        }while(map[playerRow][playerCol] == SPACE);
      break;
    case RIGHT :
      do
        {
          playerCol = playerCol + 1;
          path[playerRow][playerCol] = TRACK;
        }while(map[playerRow][playerCol] == SPACE);
      break;
    default :
      cout << "did not move \n";
      break;
  }

  while(map[playerRow][playerCol] != CHOICE)
  {
    switch (map[playerRow][playerCol])
    {
      case WARP_UP: 
        while(map[playerRow][playerCol] == WARP_UP || map[playerRow][playerCol] == SPACE)
        {
          playerRow = playerRow - 1;
          path[playerRow][playerCol] = TRACK;
        }
        break;
      case WARP_DOWN: 
        while(map[playerRow][playerCol] == WARP_DOWN || map[playerRow][playerCol] == SPACE)
        {
          playerRow = playerRow + 1;
          path[playerRow][playerCol] = TRACK;
        }
        break;
      case WARP_LEFT: 
        while(map[playerRow][playerCol] == WARP_LEFT || map[playerRow][playerCol] == SPACE)
        {
          playerCol = playerCol - 1;
          path[playerRow][playerCol] = TRACK;
        }
        break;
      case WARP_RIGHT: 
        while(map[playerRow][playerCol] == WARP_RIGHT || map[playerRow][playerCol] == SPACE)
        {
          playerCol = playerCol + 1;
          path[playerRow][playerCol] = TRACK;
        }
        break;

    }
  }

  path[playerRow][playerCol] = PLAYER;
  map[playerRow][playerCol] = PLAYER;

}

//-----------------------------------------------------------------------------------
// Name:  load  PAIRS ONLY
// Purpose:  This loads a saved game from file(s).
//           It writes an error message to cerr if the file cannot be opened.
//           It opens the file and sets playerRow and playerCol.
//           It also fills in the map and the path matrices from the file.
//           Any '.' in the map or path files are converted to spaces in the array.
// Parameters:  ???
// Returns:  void
//-----------------------------------------------------------------------------------
// ??? load(???)

//-----------------------------------------------------------------------------------
// Name:  save  PAIRS ONLY
// Purpose:  This saves a game to a file.
//           It opens the file and writes playerRow and playerCol.
//           It prints an error message to cerr if the file cannot be opened.
//           It also writes the map and the path matrices to the file.
//           Any spaces in the map or path arrays are converted to '.' in the file so they are visible.
// Parameters:  ???
// Returns:  void
//-----------------------------------------------------------------------------------
// ??? save(???)


int main()
{
    //Declare two 2D char arrays for the map and path
    //Each array should have ROWS rows and COLS cols
  char map[ROWS][COLS];
  char path[ROWS][COLS];
  char choice;
  bool legalMove;
  bool won = false;

    //Declare two ints to keep track of the player location, their row and col in the map
  
  int playerRow;
  int playerCol;

    //Ask the user whether or not they want a new game or to load a game (PAIRS)
  
    //Initialize the map and path and player location for a new game from file "map.txt"
    //or set them based on a save file
  init ("Map.txt", map, path, playerRow, playerCol);
    //While we have not won the game by reaching the top right corner
  while (won == false || map[playerRow][playerCol] == CHOICE)
  {

        //Print map and path
    print (map, path, playerRow, playerCol);
        //Get a valid type of move from the player
    choice = getMove("Enter a move (w, a, s, d):");
        //If the user wants to quit, save the game and set done to true

        //Check the move to see if it is legal
    legalMove = legal(choice, map, path, playerRow, playerCol);
    cout << legalMove << endl;
    if (legalMove == false)
    {
      cout << "Error: You cannot move that way.\n";

        //If the move is legal, make it
    }
    else if (legalMove == true)
    {
      makeMove(choice, map, path, playerRow, playerCol);
    }

           //Check to see if the user has won after the move
    won = gameOver(map, path, playerRow, playerCol);
  }

    //If the player won the game, print a congratulatory message
  if(won == true)
    cout << "Congratulations! You have won!\n";
    return 0;
}