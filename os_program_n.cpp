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


    string nums = "";
    string text = "";


    while(!readText.eof())
    {

      readText >> item;



      for(int i=0; i < item.length(); ++i){
        if (isdigit(item[i]) && !isdigit(item[i+1])){
          nums += item[i];
          int num = atoi(nums.c_str());
          int changednums = pipe_function(item[i], atoi(argv[3]), atoi(argv[2]) );
          string stringnum = to_string(changednums);
          text += stringnum;
        }
        else if (isdigit(item[i])){
          nums += item[i];
        }
        else if (isspace(item[i])){
          text += " ";
        }
        else
          text += item[i];
        }
      }
cout << text << endl;


  return 0;
}
