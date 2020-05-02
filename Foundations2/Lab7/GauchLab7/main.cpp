//----------------------------------------------
// Purpose: Demonstrate recursive flood fill
// Author:  John Gauch
//----------------------------------------------
#include <iostream>
using namespace std;

const int ROWS = 100;
const int COLS = 100;
char pixel[ROWS][COLS];

//----------------------------------------------
void fill(int r, int c, char value)
{
   // Check first terminating condition
   if ((r < 0) || (r >= ROWS) || (c < 0) || (c >= COLS))
      return;

   // Check second terminating condition
   else if (pixel[r][c] == value)
      return;

   // Handle recursive case
   else
   {
      cout << r << " " << c << endl;
      pixel[r][c] = value;
      fill(r + 1,c, value);
      fill(r,c + 1, value);
      fill(r - 1,c, value);
      fill(r,c - 1, value);

   }
}

//----------------------------------------------
void print()
{
   for (int r = 0; r < ROWS; r++)
   {
      for (int c = 0; c < COLS; c++)
         if (pixel[r][c] != 0)
	    cout << pixel[r][c];
         else
	    cout << '.';
      cout << endl;
   }
}

//----------------------------------------------

//----------------------------------------------
// Purpose: Demonstrate recursive grammars
// Author:  John Gauch
//----------------------------------------------
#include <iostream>
using namespace std;

//----------------------------------------------
string ParseInt(const string Input, const int pos)
{
   if ((pos < 0) || (pos >= Input.length()))
      return "";
   else if ((Input[pos] < '0') || (Input[pos] > '9'))
      return "";
   else
      return (Input[pos] + ParseInt(Input, pos+1));
}

//----------------------------------------------
string ParseFloat(const string Input, const int pos)
{
  string result = ParseInt(Input, pos);
  if ((Input[pos + result.length()]) != '.')
    return result;
  else
    return (result + '.' + ParseInt(Input, pos + result.length() + 1));
}

//----------------------------------------------
int main()
{
   string input = "123.456hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 0 << endl;
   cout << "ParseInt = " << ParseInt(input, 0) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 0) << endl;

   input = "123 456hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 0 << endl;
   cout << "ParseInt = " << ParseInt(input, 0) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 0) << endl;

   input = "hello123.456hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 2 << endl;
   cout << "ParseInt = " << ParseInt(input, 2) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 2) << endl;

   input = "hello123.456hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 5 << endl;
   cout << "ParseInt = " << ParseInt(input, 5) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 5) << endl;

   input = "123.456.789hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 4 << endl;
   cout << "ParseInt = " << ParseInt(input, 4) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 4) << endl;

   input = "1o12.456hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 2 << endl;
   cout << "ParseInt = " << ParseInt(input, 2) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 2) << endl;

   input = "123.456.789hello";
   cout << "Input = " << input << endl;
   cout << "Position = " << 0 << endl;
   cout << "ParseInt = " << ParseInt(input, 0) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 0) << endl;
}

/*int main()
{
   fill(50, 50, '#');
   print();
   return 0;
}*/
