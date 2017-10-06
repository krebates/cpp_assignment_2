#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

  int process_id;

  printf("hi\n");
  process_id = fork();
  fork();

  if (process_id == -1)
  {
    perror ("error creating");
    exit(0);
  }

  if(process_id == 0)
  {
    printf("child\n");
  }
  else{
    printf("parent\n");
  }
}