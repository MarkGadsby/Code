using System;

namespace Shapes
{
    public class Circle : Shape

    {
        private double radius;
        
        public Circle(double given_radius)
        {
            radius = given_radius;
        }
        
        public override double get_area()
        {
            return Math.PI * radius * radius; 
        }
    }
}