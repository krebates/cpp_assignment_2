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
    numProcesses = atoi(argv[1]) - 1;
    char buffer[20];
    int writeValue = 50;
    int readValue;

    for(i = 0; i < numProcesses; i++) {
        pid = fork();
        if(pid < 0) {
            printf("Error");
            exit(1);
        // } else if (pid == 0) {
        //     close(pipe_file_desc[1]);
        //     read(pipe_file_desc[0], buffer, 20);
        //     testValue += 2;
        //     // cout << testValue << endl;
        //     close (pipe_file_desc[0]);
        //     // printf("Child (%d): %d\n", i + 1, getpid());
        //     exit(0);
        // } else  {
        //     wait(NULL);
        //     close (pipe_file_desc[0]);
        //     write (pipe_file_desc[1], &testValue, 20);
        //     cout << testValue << endl;
        //     close (pipe_file_desc[1]);
        }
    if (pid > 0) {  /* parent process */
    // int writeValue=10;
    // int readValue=0;
    close(pipe_file_desc[READ]);      //close read end, write and then close write end
    write(pipe_file_desc[WRITE],&writeValue,sizeof(writeValue));    //write to pipe one
    printf("Parent: writes value : %d\n", writeValue);
    close(pipe_file_desc[WRITE]);
    close(pipe_file_desc_2[WRITE]);        //close write end, read, and then close read end
    read(pipe_file_desc_2[READ],&readValue,sizeof(readValue));
    printf("Parent: reads value : %d\n", readValue);
    close(pipe_file_desc_2[READ]);
  }
  else { /* child process */
    // int writeValue=20;
    // int readValue=0;
    close(pipe_file_desc[WRITE]);   //close write end, read, and then close read end
    read(pipe_file_desc[READ],&readValue,sizeof(readValue));
    printf("child: read value : %d\n", readValue);
    writeValue+=valueToAdd;
    close(pipe_file_desc[READ]);
    close(pipe_file_desc_2[READ]);       //close read end, write and then close write end
    write(pipe_file_desc_2[WRITE],&writeValue,sizeof(writeValue));
    printf("child: writeValue value : %d\n", writeValue);
    close(pipe_file_desc_2[WRITE]);

  }

    }

}