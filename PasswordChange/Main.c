#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("Passwords.txt", "r");

    if (fp != NULL)
    {
        char userName[64];
        char password[64];
        
        fgets(userName, 64, fp);
        printf("%s", userName);
        fgets(userName, 64, fp);
        printf("%s", userName);
        fgets(userName, 64, fp);
        printf("%s", userName);
   
        printf("%s", userName);
        fclose(fp);
    }
   
    return(0);
}