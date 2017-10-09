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
  a = strtol(argv[2], NULL, 0);
  b = strtol(argv[3], NULL, 0);

  //error message if problem creating the pipe
  if (pipe(pipe_file_desc) == -1){
    perror ("error creating");
    exit(0);
  }

  //Opens up the file to read
  ifstream readText;
  readText.open(argv[1]);

  // while(!readText.eof()){
  //   while(getline(readText, word))
  //     {
  //       readText >> word;
  //       for(int i=0; i < word.length(); ++i){
  //         if(!isdigit(word[i]))cout << word[i];
  //       }
  //       // cout << word[i];
  //     }
  //   cout<<"\n";
  // }

  process_id = fork();

  if (process_id == 0) //child process
  {
    close(pipe_file_desc[1]);

    //Creates process (a) and value (b) provided in command line,
    //uses 0 for unvalid input
    int a, b;
    a = strtol(argv[2], NULL, 0);
    b = strtol(argv[3], NULL, 0);

      ifstream readText;
      readText.open(argv[1]);

    while(!readText.eof())
    {
      while(getline(readText, word))
        {
          readText >> word;
          char arr[100] = ""; // An array of strings holding all the digits in the text.
          int arrIndex = 0; // To keep track of what index we are in for the arr.
            for(int i=0; i < word.length(); i++)
            {
              if(isdigit(word[i]) == true)
              { //Only want the digits from the text file.
                arr[arrIndex] = word[i]; // Storing the digits from the text into the arr.
                arrIndex++; // Incrementing to the next open position of arr.
                // cout << arr[arrIndex];
                cout << word[i] << " ";
              }
              else cout << word[i];
            }
        }
    }

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