#include <stdio.h>

int main()
{
    int TimesTable[12][12] = {{1,2,3,4,5,6,7,8,9,10}, {1,2,3,4,5,6,7,8,9,10}};
    int a, b;
    
    for (a = 1; a <= 10; ++a) 
    {
        for (b = 1; b <= 10; ++b) 
        {
            printf("%5d", a*b);
        }
        printf("\n\n");
    }
    return 0;
}