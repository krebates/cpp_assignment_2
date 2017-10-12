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

    // while(!readText.eof())
    // {
    //   while(getline(readText, item))
    //   {
    //   readText >> item;
    //   for(int i=0; i < item.length(); ++i){
    //     if(isdigit(item[i]))
    //       //add value here to variable to be able to change it
    //       // readValue << item[i];
    //       // name += item[i];
    //       newitem += item[i];
    //       // else{
    //       //     if (newNumber.length() == 0)cout << item[i];
    //       // }
    //     else if(!isdigit(item[i]))
    //         cout << item[i];
    //     else if(isspace(item[i]))
    //         cout << " ";
    //       // if(!isdigit(item[i]))cout << item[i];
    //       // cout << readValue;
    //     }
    //   }
    //   cout<< newitem <<"\n";
    //   return 0;
    // }

    string digits = "";
    string text = "";


    while(!readText.eof())
    {
      // while(getline(readText, item))
      // {
      readText >> item;



      for(int i=0; i < item.length(); ++i){
        if (isdigit(item[i]) && !isdigit(item[i+1])){
          digits += item[i];
          int digit = atoi(digits.c_str());
          int changeddigits = pipe_function(item[i], atoi(argv[3]), atoi(argv[2]) );
          string stringdigit = to_string(changeddigits);
          text += stringdigit;
          // cout << stringdigit <<endl;
          // cout << digit << endl;
        }
        else if (isdigit(item[i])){
          digits += item[i];
        }
        else if (isspace(item[i])){
          text += " ";
        }
        else
          text += item[i];
        }
      }
cout << text << endl;

  //    int x = pipe_function(50, atoi(argv[3]), atoi(argv[2]) );
  // cout << x;

    // }

    // while(!readText.eof()){
    //   while(getline(readText, item))
    //     {
    //       readText >> item;
    //       char arr[100] = ""; // An array of strings holding all the digits in the text.
    //       int arrIndex = 0; // To keep track of what index we are in for the arr.
    //         for(int i=0; i < item.length(); i++)
    //         {
    //           if(isdigit(item[i]) == true)
    //           { //Only want the digits from the text file.
    //             arr[arrIndex] = item[i]; // Storing the digits from the text into the arr.
    //             cout << "This is the digit that got extracted: " << arr[arrIndex] << endl;
    //             arrIndex++; // Incrementing to the next open position of arr.
    //           }
    //         }
    //     for(int i = 0; i < arrIndex; i++){ // Printing all of the digits in the array of strings. Once                 the chunks of numbers are seperated the "atoi" function c                an be used to turn the strings into digits.
    //       cout << "These are the numbers from the text : " << arr[i] << endl;
    //     }
    //       // cout << item[i];
    //     }
    //   cout<<"\n";
    // }
  return 0;
}
