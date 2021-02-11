using System;

namespace Shapes
{
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] shapes = new Shape[4];

            shapes[0] = new Square(10);           
            shapes[1] = new Circle(10);           
            shapes[2] = new Triangle(10,10,10);           
            shapes[3] = new Hexagon(10);

            for (int i = 0; i < shapes.Length; i++)
            {
                Console.WriteLine(shapes[i].get_area());        
            }            
        }
    }
}