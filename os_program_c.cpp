#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

double num, nIndex;
string strName;
char number (string strName);
stringstream strStream;
int pipe_file_desc[2];

int main(int argc, char **argv)
  {
    ifstream readText;
    readText.open(argv[1]);

    int a, b;
    a = strtol(argv[2], NULL, 0);
    b = strtol(argv[3], NULL, 0);

    if (pipe(pipe_file_desc) == -1){
      perror ("error creating");
      exit(0);
    }

    char number (string strName)
    ifstream readText;
    readText.open(argv[1]);

  {

    while(!readText.eof()){
      while(getline(readText, word))
      {

        for ( nIndex=0; nIndex < strName.length(); nIndex++)
          if (!isdigit(strName[nIndex]))
            continue;
          else
            strStream << strName[nIndex];
            strStream >>  num ;
            cout <<   num ;
        break;
        }
      }
    }

  return 0;

}







// #include <iostream>
// #include <fstream>
// #include <string>
// #include <stdlib.h>

// using namespace std;

// int main(int argc, char **argv)
//   {
//     int a, b;
//     string word, newWord;
//     // stringstream concat;


//     a = strtol(argv[2], NULL, 0);
//     b = strtol(argv[3], NULL, 0);

//     ifstream readText;
//     readText.open(argv[1]);

//     while(!readText.eof()){
//       while(getline(readText, word))
//         {
//           readText >> word;
//           for(int letter = 0; letter < word.length(); ++letter){
//             if(isdigit(word[letter]))
//               {

//                 // concat << newWord << word[i];
//                 newWord += word[letter];
//                 //a=concat.str(); //defines the string concat.
//                 // cout << concat.str() << endl;
//               }
//             else{
//               cout << word[letter];
//             }
//           }
//           // cout << word[i];
//         }
//       cout<<"p0\n";
//     }
//   return 0;
// }