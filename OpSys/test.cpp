#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()

{

  pid_t pid;

  int count = 0;

  pid = fork();

  if (pid == 0){

    printf("count = %d\n", count);

    wait(NULL);

  }

  else{

    count++;

    wait(NULL);

  }

  printf("count = %d\n", count);

  wait(NULL);

}
