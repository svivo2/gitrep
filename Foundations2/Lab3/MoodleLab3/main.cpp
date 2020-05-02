#include <cstring>
#include <iostream>
#include "mystrlen.h"
#include "mystrcat.h"
using namespace std;

int main()
{
  char line[] = "ls -l -a | wc -c >> myfile";
  size_t len = strlen(line);
  cout << "The length of 'line' is " << len << ".\n";

  char * strArray[10];

  for (int i = 0; i < 10; i++)
    strArray[i] = "\0";

  int pieces = 0;

  char * ptr = strtok(line, " ");

  while (ptr != NULL)
  {
    strArray[pieces] = ptr;
    ptr = strtok(NULL, " ");
    pieces++;
  }

  for (int j = 0; j < pieces; j++)
    cout << "strArray[" << j << "] " << strArray[j] << endl;

  size_t size = 0;

  for (int k = 0 ; k < pieces; k++)
    size = size + strlen(strArray[k]);

  cout << "The sum of lenghts is " << size << ".\n";

  size_t numBlanks = pieces - 1;

  cout << "The number of blanks is " << numBlanks << ".\n";

  char * result = new char[size + 1];

  result[0] = '\0';

  for (int l = 0; l < pieces; l++)
    strcat(result, strArray[l]);

  cout << "The concatenation of all strings in strArray is "
      << result << ".\n";

  delete[] result;
}
