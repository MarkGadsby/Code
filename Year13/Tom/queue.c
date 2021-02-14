#include "stdio.h"
#include "stdbool.h"

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];

int front;
int back;
int queue_len;

void initialise()
{

    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    { 
        queue[i] = 0;
    }

    front=0;
    back=0;
    queue_len=0;
}

void ShowYourself()
{
    printf("\n");

    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        printf("\t%i",queue[i]);
    }
}

bool isFull()
{
    if (queue_len == MAX_QUEUE_SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

void enQueue(int new_value)
{
    if (isFull() ==true) #dont know format
    {
        printf("line is full")
    }
    else
    {
    queue[back] = new_value;
    queue_len++;  
    back++;
    }                      
}

bool isEmpty()
{
 //   if queue_len=0
 //   return true;
}

int deQueue()
{
//    for (int i=0; i<MAX_QUEUE_SIZE; i++)
  //  {
 //   queue[i]=queue[i+1]
 //   }
}

void main()
{
    initialise();
    ShowYourself();

    int count = 9;

    while (count != 0)
    {
        enQueue(count);
        ShowYourself();

        count--;
    }
       
}
