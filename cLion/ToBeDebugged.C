#include <stdio.h>

void Square(int n)
{
    n = n * n;
}

int main()
{
    printf("A. Fibonacci printout:\n");

    int fib[] = {0,1,1,2,3,5,8,13,21};
    int size = sizeof(fib) / sizeof(int);

    // use the debugger to test this loop and explain what is printed out.
    for (int i = 0; i <= size; i++)
    {
        printf("%d\n", fib[i]);
    }

    printf("\n\nB. Square printout:\n");

    // use the debugger to examine why this code isn't printing the square of 6.
    int num = 6;
    Square(num);
    printf("%d\n", num);
    return 0;
}
