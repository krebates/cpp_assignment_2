#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
  {
    //variables
    int pipe_file_desc[2];
    int process_id;
    int readValue;
    int counter = 0;
    string word;


  //Creates process (a) and value (b) provided in command line,
  //uses 0 for unvalid input
  int a, b;
  a = strtol(argv[2], NULL, 0);
  b = strtol(argv[3], NULL, 0);

    ifstream readText;
    readText.open(argv[1]);

  while(!readText.eof()){
    while(getline(readText, word))
      {
        readText >> word;
        for(int i=0; i < word.length(); ++i){
          if(!isdigit(word[i]))cout << word[i];
        }
        // cout << word[i];
      }
    cout<<"\n";
  }

  pid_t pid = fork();

  if (pid == 0)
    {
    // child process
    int i = 0;
    for (; i < a; ++i)
      {
        printf("child process: counter=%d\n", ++counter);
      }
    }
  else if (pid > 0)
    {
      // parent process
      // int j = 0;
      // for (; j < 5; ++j)
      // {
      //     printf("parent process: counter=%d\n", ++counter);
      // }
    }
  else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }


    return 0;
}

