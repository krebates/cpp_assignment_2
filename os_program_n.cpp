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

  //Opens up the file to read
  char b[73] = "";
  ifstream f(argv[1]);

  f.read(b, sizeof(b) - 1); // Read one less that sizeof(b) to ensure null
  cout << b;
}