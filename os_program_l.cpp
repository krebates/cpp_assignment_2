#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  ifstream readText;
  readText.open("test2.txt");

  string item, line, newNumber;

  do {
   int count = 0;


    getline(readText, line);
      for (int i = 0; i < 3; ++i){
        readText >> line;
        for(int i=0; i < line.length(); ++i){
          if(isdigit(line[i]))
              newNumber += line[i];
          else if(!isdigit(line[i]))
              cout << line[i];
          else if(isspace(line[i]))
              cout << " ";
        }

    cout<<"\n";
      }


   // for (int i = 0; i < 3; ++i){
   //  while(!readText.eof()){
   //    while(getline(readText, line))
   //      {
   //      readText >> line;
   //      for(int i=0; i < line.length(); ++i){
   //        if(isdigit(line[i]))
   //            newNumber += line[i];
   //        else if(!isdigit(line[i]))
   //            cout << line[i];
   //        else if(isspace(line[i]))
   //            cout << " ";
   //        }
   //      }
   //    cout<<"\n";
   //    }
   //  }
    cout << "\nPress a key to continue...";
  } while (getchar());

  readText.close();//After you finish reading, you have to close it.

  return 0;
}