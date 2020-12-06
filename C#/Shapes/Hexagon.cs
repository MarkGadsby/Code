using System;

namespace Shapes
{
    public class Hexagon : Shape 
    {
        private double lenSides;
        public Hexagon(double given_lenSides)
        {
            lenSides = given_lenSides;
        }    
        public override double getArea()
        {       
            return (3 * Math.Sqrt(3) * lenSides * lenSides) / 2; 
        }  
    }
}