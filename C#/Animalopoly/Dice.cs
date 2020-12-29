using System;

namespace Animalopoly
{
    class Dice 
    {
        private int firstThrow;
        private int secondThrow;

        private Random rand;
    
        public Dice()
        {
            rand = new Random();
            firstThrow = -1;
            secondThrow = -1;
        }

        public int GetRollTotal()
        {
            firstThrow = SingleRoll();
            secondThrow = SingleRoll();

            return firstThrow + secondThrow;
        }
    
        public bool ThrewDouble()
        {
            if (firstThrow != -1 && secondThrow != -1)
            {
                return firstThrow == secondThrow;
            }
            else
                return false;        
        }
    
        private int SingleRoll()
        {
            return rand.Next(1,7);
        }
    }
}
