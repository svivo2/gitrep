
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main()
{
  pid_t pid;
  cout << pid << endl;
  printf("Hi \n");
  pid = fork();
  cout << "After first fork(): " << pid << endl;
  pid = fork();
  cout << "After second fork(): " << pid << endl;
  if (pid == 0)
  {
    printf("if \n");
    cout << pid << endl;
    wait(NULL);
  }
  else
  {
    printf("else \n");
    cout << pid << endl;
  }
  wait(NULL);
  return 0;
}
