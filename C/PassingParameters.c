#include<stdio.h>

void square(int* pNum)
{
    *pNum *= *pNum; 
}

void main()
{
    int UserNum = 0;
    printf("What int would you like to square: "); 

    scanf("%d", &UserNum);

    square(&UserNum);

    printf("The number now is = %d\n", UserNum);     
}