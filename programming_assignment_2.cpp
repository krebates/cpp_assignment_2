#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(){

  ifstream inFile;
  inFile.open("test2.txt");

  int values[0];  // declare the array and then...
    for (int i = 0; i < 100; i++) // ...initialize it
    {
        values[i] = 0;
    }
  // string item;
  // int count = 0;

  // //Read a file until the end is reached
  // while(!inFile.eof()){
  //   inFile >> item;
  //   count++;
  //   cout<<item<<endl;
  // }

  // cout << count << " items found."<<endl;

  inFile.close();//After you finish reading, you have to close it.

  return 0;
}