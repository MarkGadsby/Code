namespace Shapes
{
    public class Square : Shape
    {
        // private member variables
        private double lenSides;

        // This is the constructor for the Square class
        public Square(double given_lenSides)
        {
            lenSides = given_lenSides;
        }

        // Function called getArea that will return the 
        // area of the shape is a floating point number
        public override double getArea()
        {
            return lenSides * lenSides;  
        }
    }
}