#include <iostream>
#include <unistd.h> // for usleep function

using namespace std;

const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          | |\n\
          | |\n\
          | |\n\
          | |\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
\n\
";

const char rocket1[] =
"             _\n\
            /^\\\n\
            |-|\n\
            | |\n\
            | |\n\
            | |\n\
            | |\n\
            | |\n\
           /| |\\\n\
          / | | \\\n\
         |  | |  |\n\
          `-\"\"\"-`\n\
\n\
";


int main()
{
    for (int i = 0; i < 50; i ++)
        cout << endl; 

    cout << rocket;
 
    int j = 100000;
    usleep(j); // move faster and faster,
 
    for (int i = 0; i < 50; i ++)
        cout << endl; 

    cout << rocket1;
  
//    for (int i = 0; i < 50; i ++) 
 //   {
 //       usleep(j); // move faster and faster,
 //       j = (int)(j * 0.9); // so sleep less each time
 //       cout << endl;
 //   }
    return 0;
}