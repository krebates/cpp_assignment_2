#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

   //shows how arguments work
   // cout << "argc = " << argc << endl;
   // for(int i = 0; i < argc; i++)
   //    cout << "argv[" << i << "] = " << argv[i] << endl;
   // return 0;


  int pipe_file_desc[2];
  int process_id;
  char buffer[20];

  if (pipe(pipe_file_desc) == -1)
  {
    perror ("error creating");
    exit(0);
  }

  process_id = fork();

  ifstream inFile;
  inFile.open("test2.txt");

  if (process_id == 0) //child process
  {
    close(pipe_file_desc[1]);
    read(pipe_file_desc[0], buffer, 20);
    printf("%s\n", buffer);
     // printf("pid in child=%d and parent=%d\n",getpid(),getppid());
    close(pipe_file_desc[0]);
  }
  else
  {
    close(pipe_file_desc[0]);
    write(pipe_file_desc[1], "hi", 20);
    close(pipe_file_desc[1]);
  }

}