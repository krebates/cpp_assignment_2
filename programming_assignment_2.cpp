#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  ifstream readText;
  readText.open("test2.txt");

  string item;
  int count = 0;

  //Read a file until the end is reached
  while(!readText.eof()){
    readText >> item;
    count++;
    cout<<item<<endl;
  }

  cout << count << " items found."<<endl;

  readText.close();//After you finish reading, you have to close it.

  return 0;
}