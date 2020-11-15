#include "stdio.h"
#include "stdbool.h"

// define the maximum queue size
#define MAX_QUEUE_SIZE 5

// Declare a global array to hold the queue items
int queue[10];

// Declare queue markers
int front;
int back;

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
}

//==========================================
// Print the queue on the screen 
//==========================================
void ShowYourself()
{
    printf("\n");

    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if (i >= front)
            printf("\t%i", queue[i]);
        else             
            printf("\t%i", 0);
    }

    printf("\n");
}

//==========================================
// Checks if the queue is full by comparing
// the back marker and the max queue size.
//==========================================
bool isFull()
{
    if (back == MAX_QUEUE_SIZE)
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
// Increments the back marker
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
        back++;    }
}

//==========================================
// Checks if the queue is empty by comparing 
// the front and back markers.
//==========================================
bool isEmpty()
{
    if (front == back)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//==========================================
// Removes the item from the front of the queue. 
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

