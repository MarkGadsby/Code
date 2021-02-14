using System;

namespace C_
{
    class square
    {
        private int length;

        public square(int new_length)
        {
            length = new_length;
        }

        public int get_area()
        {
            int area = length * length;
            return area;
        }

        public void set_length(int new_len)
        {
            length = new_len;
        }
        
        public int get_length()
        {
            Console.WriteLine(length);
            return length;
        }
    }

    class circle
    {
        private int radius;

        public circle(int input)
        {
            radius=input;
        }

        public get_area()
        {
            int area = radius * 3.14;
            return area;
        }
    }

class Program
    {
        static void Main(string[] args)
        {
            square sq1 = new square(4);
            Console.WriteLine(sq1.get_area());     
            sq1.set_length(8);
            Console.WriteLine(sq1.get_area());
            sq1.get_length();

            circle c1 = new circle(10);
            Console.WriteLine(c1.get_area);

        }
    }
}
