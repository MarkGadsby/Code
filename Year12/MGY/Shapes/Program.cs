using System;

namespace Shapes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Circle c = new Circle(5);
        
            Console.WriteLine("Area of the circle is: " + c.GetArea());

        }
    }
}
