#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#define READ  0
#define WRITE 1

using namespace std;

int pipe_function(int valueGiven, int numProcesses, int valueToAdd){
  int pid;
  int pipe_file_desc_2[2];

  for(int i = 0; i < numProcesses; i++)
  {
    if (pipe(pipe_file_desc_2) == -1)
    {
      perror("error creating pipe");
      exit(0);
    }

    pid = fork();

    if(pid < 0) {
      printf("Error");
      exit(0);
    }

    if (pid > 0) { /* parent process */
      wait(0);
      close(pipe_file_desc_2[WRITE]);
      read(pipe_file_desc_2[READ],&valueGiven,sizeof(valueGiven));
      close(pipe_file_desc_2[READ]);
      exit(0);
    }

    else { /* child process */
        close(pipe_file_desc_2[READ]);
        valueGiven+=valueToAdd;
        write(pipe_file_desc_2[WRITE],&valueGiven,sizeof(valueGiven));
        close(pipe_file_desc_2[WRITE]);
    }
  }
  return valueGiven;
}



int main ( int argc, char *argv[] )
{

 // int a = atoi(argv[3]);
 // int b = atoi(argv[2]);
 // int x = pipe_function(50, 6, 5 );
  int x = pipe_function(50, atoi(argv[3]), atoi(argv[2]) );
  cout << x;
  // cout << argv[3];
  //variables
  // int testValue = 3;
  // int pipe_file_desc[2];

  // int valueToAdd = atoi(argv[3]);
  // int a = atoi(argv[2]);
  // int numProcesses = atoi(argv[2]);


  // int readValue;
  // string item, newWord, word, line;
  // int count = 0;

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

  // int pipe_function(int valueGiven, int numProcesses, int valueToAdd){

}
