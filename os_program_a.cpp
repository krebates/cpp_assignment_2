#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

  //variables
  int pipe_file_desc[2];
  int process_id;
  char buffer[20];
  // int inputValue = atoi(argv[2]);
  string word;

  //creates 'x' from value provided in command line
  int a;
  a = strtol(argv[3], NULL, 0);
  cout << a ;


  //checks input value



  //error message creating the pipe
  if (pipe(pipe_file_desc) == -1){
    perror ("error creating");
    exit(0);
  }

  //creating x-1 forks
  printf("hello\n");
  for ( int x = 0; x < a; x++ ) {
    printf("hello");
  }

  //opening up the file to read
  ifstream readText;
  readText.open(argv[1]);





  while(!readText.eof()){
    while(getline(readText, word))
      {
      readText >> word;

        for(int i=0; i < word.length(); ++i){

          if(isdigit(word[i]))cout << word[i];
            //add value here to variable to be able to change it
            if(!isdigit(word[i]))cout <<word[i];

        }
      }
  cout<<"\n";
  // return 0;

  }

  // cout << count << " items found."<<endl;
  readText.close();

  process_id = fork();


  if (process_id == 0)
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
return 0;
}