#include <stdio.h>
#include <stdbool.h>

void main()
{
    int digit = 0;
    int number = 78;

    char ResultArray[256]; 
    int indexCounter = 0;

    while (number)
    {
        digit = number % 2;
        number = number / 2;
    
        printf("%d", digit);
    }            
}

