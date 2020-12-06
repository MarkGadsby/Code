using System;

namespace Shapes
{
    public class Triangle : Shape 
    {
        private double sideOne;
        private double sideTwo;
        private double sideThree;
        
        public Triangle(double given_One, double given_two, double given_three)
        {
            sideOne = given_One;
            sideTwo = given_two;
            sideThree = given_three;
        }
        
        // Heron's Formula for the area of a triangle(Hero's Formula)
        // A method for calculating the area of a triangle when you know the lengths of all three sides.
        public override double getArea()
        {
            double perimeter = sideOne + sideTwo + sideThree;
            double halfP = perimeter / 2;
            return Math.Sqrt(halfP * (halfP - sideOne) * (halfP - sideTwo) * (halfP - sideThree));
        }
    }
}
