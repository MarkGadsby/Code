using System;

namespace Queue_Stack
{
    class Stack
    {
        // Define the maximum queue size
        const int MAX_STACK_SIZE = 5;

        // Declare an empty stack of int
        private int[] stack  = new int[MAX_STACK_SIZE];

        // Declare stack top pointer
        private int top_of_stack;

        public Stack()
        {
            for (int i = 0; i < MAX_STACK_SIZE; i++)
            {
                stack[i] = 0;
            }

            top_of_stack = -1;
        }
        //==========================================
        // Print the stack on the screen 
        //==========================================
        public void ShowYourself()
        {
            Console.WriteLine();
            Console.WriteLine("Stack: top");
            
            int i = MAX_STACK_SIZE - 1;
            
            while (i != -1)
            {
                Console.WriteLine("\t\t" + stack[i]);
                i--;
            }
            Console.WriteLine("Stack: bottom");
            Console.WriteLine();
        }

        //==========================================
        // Checks if the stack is full by comparing
        // the top_of_stack with the max stack size.
        //==========================================
        private bool isFull()
        {
            if (top_of_stack == MAX_STACK_SIZE - 1)
            {
                return true;
            }
            else
            {
                return false;
            }       
        }

        //==========================================
        // Adds a new item to the top of the stack. 
        //==========================================
        public void push(int new_value)
        {
            if (isFull() == true)
            {
                Console.WriteLine("Sorry stack overflow\n");
            }
            else
            {
                top_of_stack++;
                stack[top_of_stack] = new_value;
            }
        }

        //==========================================
        // Checks if the stack is empty by comparing  
        // the top_of_stack with -1.
        //==========================================
        private bool isEmpty()
        {
            if (top_of_stack == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        //==========================================
        // Removes and returns the item from the top 
        // of the stack. 
        //==========================================
        public int pop()
        {
            int return_value = 0;

            if (isEmpty() == true)
            {
                Console.WriteLine("Sorry stack underflow");
            }
            else
            {
                return_value = stack[top_of_stack];
                stack[top_of_stack] = 0;
                top_of_stack--;
            }

            return return_value;
        }
    }
}