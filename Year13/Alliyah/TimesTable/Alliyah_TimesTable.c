/*Import library for standard input/output functionality*/
#include <stdio.h>

/* 2D array for storing the products*/
int numbers[10][10];

/*Main function that runs when the program is run*/
void main()
{
    /*Loops through the rows*/
    for (int i = 0; i < 10; i++)
    {
        /*Loops through the columns*/
        for (int j = 0; j < 10; j++)
        {
          /*Changes the value of the ith row and jth column of the array to the product of (i+1) and (j+1)*/
          numbers[i][j] = (i+1) * (j+1);
        }
    }

    /*Loops through the rows*/
    for (int i = 0; i < 10; i++)
    {
      /*Loops through the columns*/
      for (int j = 0; j < 10; j++)
      {
        /*Prints the output of the ith row and jth columns of the array*/
        printf("%i", numbers[i][j]);
        /*Tabs used to make the multiplication table look better*/
        printf("\t");
      }
      /*Adds new lines after the row is complete*/
      printf("\n\n");
    }
}