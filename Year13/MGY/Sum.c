#include<stdio.h>

int sum_iterartion(int num)
{
    int retval = 0;

    for (int i = 0; i <= num; i++)
    {
        retval += i; 
    }

    return retval;
}

int sum_single(int num)
{
    return num * (num + 1) / 2;
}

void main()
{
    int sum_num = 0;
    printf("\nPlease enter number we would like the sum of: ");
    scanf("%i", &sum_num);
    printf("\nsum_iterartion() returned: %i", sum_iterartion(sum_num));
    printf("\nsum_single() returned: %i", sum_single(sum_num));

}