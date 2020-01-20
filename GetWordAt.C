#include <stdio.h>

int GetWordAt(int iStart, char base[], char target[64])
{
    int baseIndex = iStart;

    int retVal = 0;

    while (base[baseIndex] != ' ' &&
           base[baseIndex] != '\0')
    {
        target[retVal] = base[baseIndex];
        retVal++;
        baseIndex++;
    }

    target[retVal] = '\0';

    if (base[baseIndex] == '\0')
        retVal = -1;

    return retVal;
}

int main()
{
    char words[] = "REMEMBER TO TAKE CHARLIE TO THE DENTIST";
    char word[64];

    int i = 0;
    int counter = 0;

    while (i != -1)
    {
        i = GetWordAt(counter, words, word);
        counter += i;
        counter++;

        printf("\t%s\n\n",word);
    }
    return 0;
}