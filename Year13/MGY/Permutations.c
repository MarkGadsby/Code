#include<stdio.h>
#include <time.h>

int combination_lock()
{
    int retval = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    retval++;
                    printf("\t %d %d %d %d\n", i,j,k,l);
                }
            }
        }        
    }

    return retval;
}

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
    printf("\nThe number of combinations allowing reputation = %d", combination_lock());
    printf("\nThe factorial of 4 is %d", factorial(4));
    printf("\nThe factorial of 5 is %d", factorial(5));
    printf("\nThe factorial of 6 is %d", factorial(6));
    printf("\nThe factorial of 7 is %d", factorial(7));
    printf("\nThe factorial of 8 is %d", factorial(8));
    printf("\nThe factorial of 9 is %d", factorial(9));
    printf("\nThe factorial of 10 is %d", factorial(10));
    clock_t startTime = clock();
    printf("\nThe factorial of 12 is %d", factorial(12));
    clock_t endTime = clock();
    printf("\nfactorial - Total time = %ld\n\n", endTime - startTime);
}