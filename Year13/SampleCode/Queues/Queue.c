#include "stdio.h"
#include "stdbool.h"

// define the maximum queue size
#define MAX_QUEUE_SIZE 5

// Declare a global array to hold the queue items
int queue[MAX_QUEUE_SIZE];

// Declare queue markers
int front;
int back;

// Declare a varible for queue length
int queue_len;

//==========================================
// Initialise the queue to all zeros
// Initialise the queue markers to zero
//==========================================
void Initialise()
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        queue[i] = 0;
    }

    front = 0;
    back = 0;
    queue_len = 0;
}

//==========================================
// Print the queue on the screen 
//==========================================
void ShowYourself()
{
    printf("\n");

    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        printf("\t%i", queue[i]);
    }

    printf("\n");
}

//==========================================
// Checks if the queue is full by comparing
// the queue length with the max queue size.
//==========================================
bool isFull()
{
    if (queue_len == MAX_QUEUE_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }       
}

//==========================================
// Adds a new item to the end of the queue. 
// Increments the back marker and queue length.
//==========================================
void enQueue(int new_value)
{
    if (isFull() == true)
    {
        printf("Sorry the queue is full\n");
    }
    else
    {
        queue[back] = new_value;
        back++; 
        queue_len++;
    }
}

//==========================================
// Checks if the queue is empty by comparing  
// the queue length with zero.
//==========================================
bool isEmpty()
{
    if (queue_len == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//==========================================
// Removes and returns the item from the front
// of the queue. 
// Increments the front marker.
//==========================================
int deQueue()
{
    int return_value = 0;

    if (isEmpty() == true)
    {
        printf("Sorry the queue is empty\n");
    }
    else
    {
        return_value = queue[front];
        queue[front] = 0;
        front++;
        return return_value;
    }
}

//==========================================
// main()
//==========================================
void main()
{
    Initialise();
    ShowYourself();
}

