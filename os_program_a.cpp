#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

  int pipe_file_desc[2];
  int process_id;
  char buffer[20];

  ifstream inFile;
  inFile.open(argv[1]);

  string item;
  int count = 0;

  //Read a file until the end is reached
  while(!inFile.eof()){
    inFile >> item;
    count++;
    cout<<item<<endl;
  }

  cout << count << " items found."<<endl;
inFile.close();



  // if (pipe(pipe_file_desc) == -1)
  // {
  //   perror ("error creating");
  //   exit(0);
  // }

  // process_id = fork();
  // if (process_id == -1)
  //   {perror ("error creating");
  //  // printf("pid in parent=%d and childid=%d\n",getpid(),pid);
  //   exit(0);
  // }

  // if (process_id == 0)
  // {
  //   close(pipe_file_desc[1]);
  //   read(pipe_file_desc[0], buffer, 20);
  //   printf("%s\n", buffer);
  //    // printf("pid in child=%d and parent=%d\n",getpid(),getppid());
  //   close(pipe_file_desc[0]);
  // }
  // else
  // {
  //   close(pipe_file_desc[0]);
  //   write(pipe_file_desc[1], "hi", 20);
  //   close(pipe_file_desc[1]);
  // }
return 0;
}