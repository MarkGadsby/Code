// To complie: gcc -o MG_TimesTable "MG_TimesTable.c"
// To Run: ./MG_TimesTable 
#include <stdio.h>

void main()
{
    // Allocate an uninitialised array
    int table[10][10];
    
    // Assign values to the array
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            // Need parenthesis here as * beats + in precedence order
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    // To display the array
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            // %d for decimal and /t for tab
            printf("%d\t", table[i][j]);
        }
        printf("\n"); // New line
    }
}