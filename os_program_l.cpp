#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  ifstream readText;
  readText.open("test2.txt");

  string item, word, newNumber;

  do {
   int count = 0;

   for (int i = 0; i < 3; ++i){
    getline(readText, word);
      {
        readText >> word;
        for(int i=0; i < word.length(); ++i){
          if(isdigit(word[i]))
              newNumber += word[i];
          else if(!isdigit(word[i]))
              cout << word[i];
          else if(isspace(word[i]))
              cout << " ";
        }
      }
    cout<<"\n";
      }


   // for (int i = 0; i < 3; ++i){
   //  while(!readText.eof()){
   //    while(getline(readText, word))
   //      {
   //      readText >> word;
   //      for(int i=0; i < word.length(); ++i){
   //        if(isdigit(word[i]))
   //            newNumber += word[i];
   //        else if(!isdigit(word[i]))
   //            cout << word[i];
   //        else if(isspace(word[i]))
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