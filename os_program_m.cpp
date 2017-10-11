#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#define READ  0
#define WRITE 1

using namespace std;


int main ( int argc, char *argv[] )
{
    //variables
    int i, pid;
    int testValue = 3;
    int pipe_file_desc[2];
    int pipe_file_desc_2[2];
    int valueToAdd = atoi(argv[3]);
    int a = atoi(argv[2]);
    int numProcesses = atoi(argv[2]);
    char buffer[20];
   static int writeValue = 50;
   static string newNumber;
    int readValue;
    string line, word, name;
    int count = 0;

    // //Opens up the file to read
    //   ifstream readText;
    //   readText.open(argv[1]);

    //Read a file until the end is reached
    // while(!readText.eof()){
    //     // if (getline(std::cin,line)) {
    //         readText >> line;
    //         for(int i=0; i < line.length(); ++i){
    //             if(isdigit(line[i]))
    //                 // name +=aname[i];
    //                 newWord += line[i];
    //             if(!isdigit(line[i]))cout << line[i] ;


    //         }
    //     // }
    // }


// do{}while();

// //do while loop for press to continue
// do{

  // while(!readText.eof()){
  //   while(getline(readText, word))
  //     {
  //     readText >> word;
  //     for(int i=0; i < word.length(); ++i){
  //       if(isdigit(word[i]))
  //           newNumber += word[i];
  //       else if(!isdigit(word[i]))
  //           cout << word[i];
  //       else if(isspace(word[i]))
  //           cout << " ";
  //       }
  //     }
  // cout<<"\n";
  // }


//Opens up the file to read
    char b[73] = "";
    ifstream f(argv[1]);

    f.read(b, sizeof(b) - 1); // Read one less that sizeof(b) to ensure null
    cout << b;


  // while(!readText.eof()){
  //   while ( getline (readText,line) )
  //     {
  //       istream& get (char* s, streamsize n );
  //       cout << line << endl;
  //       c += line.length();
  //       int number = atoi(line.c_str());
  //   }
  // }


// int newNumber = atoi(newNumber.c_str());
   /* change into integer*/

 //   cout << "\nPress a key to continue...";
 // } while (getchar());


    // for(i = 0; i < numProcesses; i++) {
    //     ++count;
    //     pid = fork();
    //     if(pid < 0) {
    //         printf("Error");
    //         exit(1);
    //     }
    //     if (pid > 0) { /* parent process */
    //         close(pipe_file_desc_2[WRITE]);
    //         read(pipe_file_desc_2[READ],&readValue,sizeof(readValue));
    //         close(pipe_file_desc_2[READ]);
    //         // wait(0);
    //     }
    //     else {
    //         close(pipe_file_desc_2[READ]);
    //         writeValue+=valueToAdd;
    //         write(pipe_file_desc_2[WRITE],&writeValue,sizeof(writeValue));
    //         if(count == numProcesses) {
    //         }
    //         close(pipe_file_desc_2[WRITE]);
    //     }

    // }

}