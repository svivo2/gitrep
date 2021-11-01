#include <iostream>
using namespace std;

int main()
{
  int numCases, numCan = 0;
  string canName, vote = "";
  char c = '\0';

  cout << "Enter Number of Cases: ";
  cin >> numCases;

  while (numCases-- > 0)
  {
    cout << "Enter Number of Candidates: ";
    cin >> numCan;
    cin.get(c);

    string *can = new string[numCan];
    int *votes = new int[numCan];
    for(int i = 0; i < numCan; i++)
    {
      cout << "Enter Candidate #" << i + 1 << " Name: ";
      getline(cin,canName);
      can[i] = canName;
      cout << "Candidate " << i + 1 << " : " << can[i] << endl;
    }
    while (c != '0')
    {
      cin.get(c);
      switch (c)
      case '1':
        votes[0]++;
        break;

    }




  }

}
