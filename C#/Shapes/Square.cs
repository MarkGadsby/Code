namespace Shapes
{
    public class Square
    {
        private int lenSides;

        public Square(int given_lenSides)
        {
            lenSides = given_lenSides;
        }

        public int getArea()
        {
            return lenSides * lenSides;  
        }
    }
}