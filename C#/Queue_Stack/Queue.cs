using System;

namespace Queue_Stack
{
    class Queue
    {
        // Define the maximum queue size
        const int MAX_QUEUE_SIZE = 5;

        // Declare an empty array of queue markers
        private int[] queue = new int[MAX_QUEUE_SIZE];

        // Declare queue markers
        private int front;
        private int back;

        // Declare a varible for queue length
        private int queue_len;

        //==========================================
        // Initialise the queue to all zeros
        // Initialise the queue markers to zero
        //==========================================
        public Queue()
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
        public void ShowYourself()
        {
            Console.WriteLine();

            Console.Write("Queue: front");

            for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            {
                Console.Write("\t" + queue[i]);
            }

            Console.Write("\tback");

            Console.WriteLine();
        }

        //==========================================
        // Checks if the queue is full by comparing
        // the queue length with the max queue size.
        //==========================================
        private bool isFull()
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
        public void enQueue(int new_value)
        {
            if (isFull() == true)
            {
                Console.WriteLine("Sorry the queue is full\n");
            }
            else
            {
                queue[back] = new_value;
                back = (back + 1) % MAX_QUEUE_SIZE; 
                queue_len++;
            }
        }

        //==========================================
        // Checks if the queue is empty by comparing  
        // the queue length with zero.
        //==========================================
        private bool isEmpty()
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
        public int deQueue()
        {
            int return_value = 0;

            if (isEmpty() == true)
            {
                Console.WriteLine("Sorry the queue is empty`");
            }
            else
            {
                return_value = queue[front];
                front = (front + 1) % MAX_QUEUE_SIZE; 
                queue_len--;   
            }
            return return_value;
        }
    }
}