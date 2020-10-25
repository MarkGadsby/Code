#include<stdio.h>

void mult(int* pNumOne, int numTwo)
{
    *pNumOne = *pNumOne * numTwo; 
}

void main()
{
    // Declaration and Assignment of interger named UserNum
    int UserNum = 9;

    int Mult = 3;

    mult(&UserNum,Mult);

    printf("The number now is = %i\n", UserNum);     
}