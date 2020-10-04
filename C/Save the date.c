#include <stdio.h>

char marks_calendar[5][6] = {
                                {'M','1','2','3','4','5'},
                                {'1','C',' ','X','X',' '},
                                {'2',' ',' ',' ','C','C'},
                                {'3','C',' ','X',' ',' '},
                                {'4','X','X','C','C',' '}
                            };

char jacobs_calendar[5][6] = {
                                {'J','1','2','3','4','5'},
                                {'1','C',' ',' ','X','X'},
                                {'2',' ',' ','C','C','C'},
                                {'3',' ',' ','C','X','C'},
                                {'4','X',' ',' ','C',' '}
                            };

void main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (marks_calendar[i][j] == 'C' & jacobs_calendar[i][j] == 'C')
            {
                printf("Week %c Day %c\n", marks_calendar[i][0], marks_calendar[0][j]);
            }
        }
    }
}

