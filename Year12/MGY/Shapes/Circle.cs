using System;

namespace Shapes
{
    class Circle
    {
        // data
        private int radius;

        // Constructor
        public Circle(int given_radius)
        {
            radius = given_radius;
        }

        public double GetArea()
        {
            return Math.PI * (radius * radius);
        }
    }

}
