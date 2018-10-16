#include <stdlib.h>     // rand, srand
#include <time.h>
#include <fstream>

#include "CCodeExperiments.h"

using namespace std;

void CCodeExperiments::TestRand()
{
    ofstream logfile;
    logfile.open("Random_Number_Results.txt", ios::app);

    logfile << '\t';
    logfile << rand();
    logfile << '\t';
    srand(time(0));
    logfile << rand();
    logfile << '\n';
    logfile.close();
}
