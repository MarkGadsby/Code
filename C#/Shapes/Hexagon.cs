using System;

namespace Shapes
{
    public class Hexagon 
    {
        private double lenSides;
        public Hexagon(double given_lenSides)
        {
            lenSides = given_lenSides;
        }    
        public double getArea()
        {       
            return (3 * Math.Sqrt(3) * lenSides * lenSides) / 2; 
        }  
    }
}