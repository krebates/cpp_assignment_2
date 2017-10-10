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
    int writeValue = 50;
    int readValue;
    string item, newWord, word, line;
    int count = 0;

    //Opens up the file to read
      ifstream readText;
      readText.open(argv[1]);

    //Read a file until the end is reached
    // while(!readText.eof()){
    //     // if (getline(std::cin,line)) {
    //         readText >> item;
    //         for(int i=0; i < item.length(); ++i){
    //             if(isdigit(item[i]))
    //                 // name +=aname[i];
    //                 newWord += item[i];
    //             if(!isdigit(item[i]))cout << item[i] ;


    //         }
    //     // }
    // }



    for(i = 0; i < numProcesses; i++) {
        ++count;
        pid = fork();
        if(pid < 0) {
            printf("Error");
            exit(1);
        }
        if (pid > 0) { /* parent process */
            close(pipe_file_desc_2[WRITE]);        //close write end, read, and then close read end
            read(pipe_file_desc_2[READ],&readValue,sizeof(readValue));
            close(pipe_file_desc_2[READ]);
        }
        else { /* child process */
            close(pipe_file_desc_2[READ]);       //close read end, write and then close write end
            writeValue+=valueToAdd;
            write(pipe_file_desc_2[WRITE],&writeValue,sizeof(writeValue));
            if(count == numProcesses) {
                printf("child: writeValue value : %d\n", writeValue);
                printf("count : %d\n", count);
            }
            close(pipe_file_desc_2[WRITE]);
        }

    }

}