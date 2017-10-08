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
  string word;
  int readValue;

  //Creates process (a) and value (b) provided in command line,
  //uses 0 for unvalid input
  int a, b;
  // a = atoi(argv[1]);
  // b = atoi(argv[2]);
  a = strtol(argv[2], NULL, 0);
  b = strtol(argv[3], NULL, 0);

  //error message if problem creating the pipe
  if (pipe(pipe_file_desc) == -1){
    perror ("error creating");
    exit(0);
  }

  // //Creates x-1 forks
  // for ( int x = 0; x < a; x++ ) {
  //   process_id = fork();
  // }

  //Opens up the file to read
  ifstream readText;
  readText.open(argv[1]);

cout << "Hello World";
  // while(!readText.eof()){
  //   while(getline(readText, word))
  //     {
  //     readText >> word;
  //     for(int i=0; i < word.length(); ++i){
  //       if(isdigit(word[i]))cout << word[i];
  //         //add value here to variable to be able to change it
  //         // readValue << word[i];
  //         if(!isdigit(word[i]))cout << word[i];
  //         // cout << readValue;


  //       }
  //     }
  // cout<<"\n";
  // }

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

  // process_id = fork();

  if (process_id == 0)
  {
    close(pipe_file_desc[1]);
    read(pipe_file_desc[0], buffer, 20);
    printf("%s\n", buffer);
    close(pipe_file_desc[0]);
  }
  else
  {
    close(pipe_file_desc[0]);
    write(pipe_file_desc[1], "hi", 20);
    close(pipe_file_desc[1]);
  }

  readText.close();
return 0;
}