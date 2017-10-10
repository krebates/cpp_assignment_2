#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#define READ  0
#define WRITE 1

using namespace std;

int main ( int argc, char *argv[] )
{
    int i, pid, numProcesses;
    int testValue = 3;
    int pipe_file_desc[2];
    int pipe_file_desc_2[2];
    int valueToAdd = atoi(argv[2]);
    numProcesses = atoi(argv[1]) ;
    char buffer[20];
    int writeValue = 50;
    int readValue;

    for(i = 0; i < numProcesses; i++) {
        pid = fork();
        if(pid < 0) {
            printf("Error");
            exit(1);
        }
    if (pid > 0) {  /* parent process */
    close(pipe_file_desc_2[WRITE]);        //close write end, read, and then close read end
    read(pipe_file_desc_2[READ],&readValue,sizeof(readValue));
    close(pipe_file_desc_2[READ]);
  }
  else { /* child process */
    close(pipe_file_desc_2[READ]);       //close read end, write and then close write end
    writeValue+=valueToAdd;
    write(pipe_file_desc_2[WRITE],&writeValue,sizeof(writeValue));
    printf("child: writeValue value : %d\n", writeValue);
    close(pipe_file_desc_2[WRITE]);

  }

    }

}