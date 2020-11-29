#include "stdio.h"
#include "stdbool.h"

bool mystery(int number)
{
    bool answer = true;

    for (int count = 2; count <= number - 1; count++)
    {
        int reminder = number % count;

        if (reminder == 0)
            answer = false;
    }
    return answer;
}

int main()
{
    int count = 50;
    while (count)
    {
        printf("\n\tmystery(%d) \treturned %d\n", count, mystery(count));
        count--;
    }
    return 0;
}