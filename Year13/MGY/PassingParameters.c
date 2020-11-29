#include<stdio.h>

void mult(int* pNumOne)
{
    *pNumOne = *pNumOne * 8; 
}

void main()
{
    int UserNum = 0;

    
    // Declaration and Assignment of interger named UserNum
    printf("please enter the number you would like to times by 8: ");

    scanf("%i", &UserNum);
    
     
    mult(&UserNum);

    printf("The number now is = %i\n", UserNum);     
}