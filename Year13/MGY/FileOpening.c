#include <stdio.h>

int main()
{
    FILE* fp = fopen("example.txt", "r");

    if (fp == NULL)
    {
        printf("Couldn't find the examples file on your disk\n");
        return 0;
    }

    char LineArray[FILENAME_MAX];

    while (!feof(fp))
    {
        if (fgets(LineArray, FILENAME_MAX, fp) != NULL)    
            printf("%s", LineArray);
    }
    
    fclose(fp);
    return 1; 
}