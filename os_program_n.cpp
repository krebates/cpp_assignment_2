#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#define READ  0
#define WRITE 1

using namespace std;

int main ( int argc, char *argv[] )
{
  //variables
  int i, pid;
  int testValue = 3;
  int pipe_file_desc[2];
  int pipe_file_desc_2[2];
  int valueToAdd = atoi(argv[3]);
  int a = atoi(argv[2]);
  int numProcesses = atoi(argv[2]);
  char buffer[20];
  int writeValue = 50;
  int readValue;
  string item, newWord, word, line;
  int count = 0;

  // //Opens up the file to read
  // char b[73] = "";
  // ifstream readText;
  // ifstream f(argv[1]);

  // // while(!readText.eof()){
  //   f.read(b, sizeof(b) - 1); // Read one less that sizeof(b) to ensure null
  //   cout << b;
  // // }

  // int num_lines = 0;
  // std::string input;
  // char b[73] = "";

  // for (; b < 10 && getline(input); ++num_lines)
  // {
  //     // do-whatever
  // }

  for(i = 0; i < numProcesses; i++) {
    pid = fork();
    if(pid < 0) {
      printf("Error");
      exit(0);
    }
    if (pid > 0) { /* parent process */
      wait(0);
      close(pipe_file_desc_2[WRITE]);
      read(pipe_file_desc_2[READ],&readValue,sizeof(readValue));
      close(pipe_file_desc_2[READ]);
      exit(0);
    }
    else { /* child process */
        close(pipe_file_desc_2[READ]);
        writeValue+=valueToAdd;
        write(pipe_file_desc_2[WRITE],&writeValue,sizeof(writeValue));
        close(pipe_file_desc_2[WRITE]);
    }
  }
 cout << writeValue << endl;
}
