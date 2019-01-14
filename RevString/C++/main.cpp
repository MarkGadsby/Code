#include <iostream>

using namespace std;

void RevString(char * const pString)
{
    char* pStart = pString;
    char* pEnd = pString;

    while (*pEnd)
        pEnd++;

    pEnd--;

    char scratchArea;

    while (pStart < pEnd)
    {
        scratchArea = *pEnd;
        *pEnd = *pStart;
        *pStart = scratchArea;
        pStart++;
        pEnd--;
    }
    cout << pString;
}

int main()
{
    char chararray[256];
    cin >> chararray;
//   cin.getline(chararray, 256);
    RevString(chararray);
    return 1;
}
