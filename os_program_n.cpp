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

  for(int i = 0; i < numProcesses - 1; i++)
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
  string item, newitem;


  // int x = pipe_function(50, atoi(argv[3]), atoi(argv[2]) );
  // cout << x;


  // int readValue;
  // string item, newitem, item, line;
  // int count = 0;


  // //---------
  // //Opens up the file to read for 72 characters
  // char b[73] = "";
  // ifstream readText;
  // ifstream f(argv[1]);

  // // while(!readText.eof()){
  //   f.read(b, sizeof(b) - 1); // Read one less that sizeof(b) to ensure null
  //   cout << b;
  // // }
  // //---------

  // int num_lines = 0;
  // std::string input;
  // char b[73] = "";

  // for (; b < 10 && getline(input); ++num_lines)
  // {
  //     // do-whatever
  // }

    //Opens up the file to read
      ifstream readText;
      readText.open(argv[1]);

     while(!readText.eof()){
    while(getline(readText, item))
      {
      readText >> item;
      for(int i=0; i < item.length(); ++i){
        if(isdigit(item[i]))
          //add value here to variable to be able to change it
          // readValue << item[i];
            // name += item[i];
            newitem += item[i];
            // else{
            //     if (newNumber.length() == 0)cout << item[i];
            // }
        else if(!isdigit(item[i]))
            cout << item[i];
        else if(isspace(item[i]))
            cout << " ";
          // if(!isdigit(item[i]))cout << item[i];
          // cout << readValue;


        }
      }
  cout<<"\n";
  return 0;
  }
}
