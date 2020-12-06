using System;

namespace Shapes
{
    class Program
    {
        static void Main(string[] args)
        {
            Square square = new Square(10);
            Console.WriteLine("The area of square:\t" + square.getArea());

            Circle circle = new Circle(10);
            Console.WriteLine("The area of circle:\t" + circle.getArea());

            Triangle triangle = new Triangle(10,10,10);
            Console.WriteLine("The area of triangle:\t" + triangle.getArea());

            Hexagon hexagon = new Hexagon(10);
            Console.WriteLine("The area of hexagon:\t" + hexagon.getArea());
        }
    }
}