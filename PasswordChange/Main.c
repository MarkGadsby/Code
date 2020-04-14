#include <stdio.h>

int main()
{
    FILE* fp = fopen("Passwords.txt", "r");

    if (fp == NULL)
    {
        printf("Couldn't find the Passwords file on your disk\n");
        return 0;
    }

    char userName[64][64];
    char password[64][64];

    int iNumberofPasswords = 0;

    while (!feof(fp))
    {
        fgets(&userName[iNumberofPasswords][0], 64, fp);
        fgets(&password[iNumberofPasswords][0], 64, fp);
        iNumberofPasswords++;
    } 

    for (int i; i <= iNumberofPasswords; i++)
    {
        printf("%s", &userName[i][0]);
        printf("%s", &password[i][0]);
    }

    fclose(fp);
    return(0);
}