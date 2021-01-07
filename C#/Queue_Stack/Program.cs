using System;

namespace Queue_Stack
{
    class Program
    {
        static void Main(string[] args)
        {

            Queue q = new Queue();

            q.enQueue(9);
            q.enQueue(8);
            q.enQueue(7);

            q.ShowYourself();

        }
    }
}
