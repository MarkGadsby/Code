#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are :\n");

//    printf("Calling towers with S (a), T (c), A (b):\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}

void towers(int num, char source, char target, char auxiliary)
{
    if (num > 0)
    {
        towers(num - 1, source, auxiliary, target);
        printf("\n Move disk %d from peg %c to peg %c\n", num, source, target);
        towers(num - 1, auxiliary, target, source);
    }
}