#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  int reg[10] = {0};
  char ram[1000][3] = {{'\0'},{'\0'},{'\0'}};
  int numCases = 0;
  char c = '\0';
  string task = "";
  ifstream din;
  din.open("P6.txt");
  din >> numCases;
  din.get(c);

  while(numCases-- > 0)
  {
    cout << "Case: " << numCases << endl;
    int tasks = 0;
    while(getline(din,task) && task != "\0")
    {
      ram[tasks][0] = task[0];
      ram[tasks][1] = task[1];
      ram[tasks++][2] = task[2];
      //cout << ram[tasks - 1][0] << ram[tasks - 1][1] << ram[tasks - 1][2] << endl;
    }
    int count = 0;
    for(int i = 0; i < tasks; i++)
    {
      switch (ram[i][0])
      {
        case '1':
          break;
        case '2':
          reg[ram[i][1] - '0'] = (ram[i][2] - '0');
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " <<reg[ram[i][1] - '0'] << endl;
          break;
        case '3':
          reg[ram[i][1] - '0'] = reg[ram[i][1] - '0'] + (ram[i][2] - '0');
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " <<reg[ram[i][1] - '0'] << endl;
          break;
        case '4':
          reg[ram[i][1] - '0'] = reg[ram[i][1] - '0'] * (ram[i][2] - '0');
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " <<reg[ram[i][1] - '0'] << endl;
          break;
        case '5':
          reg[ram[i][1] - '0'] = reg[ram[i][2] - '0'];
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " <<reg[ram[i][1] - '0'] << endl;
          break;
        case '6':
          reg[ram[i][1] - '0'] = reg[ram[i][1] - '0'] + reg[ram[i][2] - '0'];
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " <<reg[ram[i][1] - '0'] << endl;
          break;
        case '7':
          reg[ram[i][1] - '0'] = reg[ram[i][1] - '0'] * reg[ram[i][2] - '0'];
          cout << "Task: " << ram[i][0] << ram[i][1] << ram[i][2] << endl;
          cout << "Result: " << reg[ram[i][1] - '0'] << endl;
          break;
        case '8':
          reg[ram[i][1] - '0'] = ((100((ram[reg[ram[i][2] - '0']][0]) - '0'))
                                 + (10((ram[reg[ram[i][2] - '0']][1]) - '0'))
                                 + (ram[reg[ram[i][2] - '0']][2] - '0'));
          cout << reg[ram[i][1] - '0'] << endl;
          break;
        case '9':
          ram[reg[ram[i][2] - '0']][0] = reg[ram[i][1] - '0']/100;
          cout << ram[reg[ram[i][2] - '0']] << endl;
          break;
        case '0':
          if((ram[i][2] - '0') == 0)
            break;
          else
            i = reg[ram[i][1] - '0'];
          break;
        default:
          break;
      }
      count++;
    }
    cout << "Count: " << count << endl;
  }
}
