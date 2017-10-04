#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <fstream.h>

using namespace std;

int main(){

  ifstream inFile;
  inFile.open("test2.txt");

  string item;
  int count = 0;

  //Read a file until the end is reached
  while(!inFile.eof()){
    inFile >> item;
    count++;
    cout<<item<<endl;
  }

  https://www.thecrazyprogrammer.com/2011/07/c-program-to-read-from-text-file-and.html
  cout.open("sample.txt"); //create file to write
    char ch;
    while(cin) //loop wiill run till end of file
      {
        cin>>ch;       //reading data from file
        cout<<ch;       //writing data to file
      }
    cin.close();
    cout.close();

  cout << count << " items found."<<endl;

  inFile.close();//After you finish reading, you have to close it.

  return 0;
}