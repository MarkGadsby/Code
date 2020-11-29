using System;

namespace Shapes
{
    class Program
    {
        static void Main(string[] args)
        {
            Square square = new Square(5);
            Console.WriteLine(square.getArea());

            Circle circle = new Circle(32.56);
            Console.WriteLine(circle.getArea());

            Triangle triangle = new Triangle(10,10,10);
            Console.WriteLine(triangle.getArea());
        }
    }
}