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

  for(int i = 0; i < (numProcesses - 1); i++)
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
      waitpid(0, NULL, 0);
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
  int position;



    //Opens up the file to read
      ifstream readText;
      readText.open(argv[1]);



    string text = "";

    while(!readText.eof())
    {
      string nums = "";
        readText >> item;
        for(int i=0; i < item.length(); ++i)
        {
          if (isdigit(item[i]) && !isdigit(item[i+1])){
            nums += item[i];
            int num = atoi(nums.c_str());
            int changednums = pipe_function(num, atoi(argv[2]), atoi(argv[3]) );
            string stringnum = to_string(changednums);
            text += stringnum;
           nums = "";
          }
          else if (isdigit(item[i])){
            nums += item[i];

          }
          else
            text += item[i];

        }
          text += " ";
      }

    cout << text << endl;

  // while(text.size() > 0)
  // {
  //   position = count 72
  //   if(text.at(position) == " ")
  //   {
  //     text = text.substring;
  //   }
  //   else{
  //     temp = substring;
  //     position = temp.found_last_of(" ")
  //   }
  // }

  return 0;
}
