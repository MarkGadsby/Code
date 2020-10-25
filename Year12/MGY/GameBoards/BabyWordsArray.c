#include<stdio.h>

void main()
{
    char words[5][256] =    {
                                {"ball"},
                                {"book"},
                                {"teddy"},
                                {"lion"}, 
                                {"flower"}
                            };
    int index = 2;
    
    while (index < 4)
    {
        printf("%s\n", words[index]);
        index = index + 1;
    }
}