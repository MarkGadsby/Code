using System;

namespace Shapes
{
    public class Circle
    {
        private double  radius;
        
        public Circle(double given_radius)
        {
            radius = given_radius;
        }
        
        public double getArea()
        {
            return Math.PI * radius * radius; 
        }
    }
}