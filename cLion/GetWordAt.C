////////////////////////////////////////////////////////
// Program to demonstrate an implementation of the 'remove'
// function mentioned in Q3 of the Christmas Tracking Test.
// It returns the first word in an array.
////////////////////////////////////////////////////////
#include <stdio.h>

////////////////////////////////////////////////////////
// GetWordAt()
//
// Function to copy letters from the sentence parameter to
// the word parameter. The iStart parameter indicates where
// in the sentence to start reading. Reading will stop when
// a space or null terminator is encountered.
//
// Returns the length of the word read, or -1 if the last
// word has just been read.
////////////////////////////////////////////////////////
int GetWordAt(int iStart, char sentence[], char word[])
{
    int index = iStart;
    int retVal = 0;

    while (sentence[index] != ' ' &&
           sentence[index] != '\0')
    {
        word[retVal] = sentence[index];
        retVal++;
        index++;
    }

    word[retVal] = '\0';

    if (sentence[index] == '\0')
        retVal = -1;

    return retVal;
}

int main()
{
    // initialise words array
    char words[] = "REMEMBER TO TAKE CHARLIE TO THE DENTIST";
    // allocate space for the individual words.
    char word[64];

    int wordSize = 0;
    int counter = 0;

    while (wordSize != -1) // while we still have words to read
    {
        wordSize = GetWordAt(counter, words, word);
        counter += wordSize;    // move counter along the correct number of letters
        counter++;              // on to the start of the next word

        printf("\t%s\n\n",word);
    }
    return 0;
}