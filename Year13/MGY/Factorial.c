#include<stdio.h>

int factorial(int num)
{
    // Base case
    if (num == 1)
        return num;
    else
        return num * factorial(num-1);    
}

void main()
{
    int userNumber = 0;
    printf("\nPlease enter number for which you'd like the factotial for: ");
    scanf("%i", &userNumber);

    int retNum = factorial(userNumber);

    printf("\nMy recursive function returned: %i", retNum);
}