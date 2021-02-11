using System;

namespace Animalopoly
{
    class Animal : Tile
    {
        private string name;
        private int currentLevel;
        private int cost;   
        private bool owned;
        private int indexOfOwner;
        private int[] feeLevels = new int[4];  
    
        public Animal(string given_name, int given_cost, int fee_0, int fee_1, int fee_2, int fee_3)
        {
            type = TileType.ANIMAL;
        
            name = given_name;
            currentLevel = 0;
            cost = given_cost;
            owned = false;
            indexOfOwner = -1;
        
            feeLevels[0] = fee_0;
            feeLevels[1] = fee_1;
            feeLevels[2] = fee_2;
            feeLevels[3] = fee_3;
        }

        public void Buy(int given_indexOfOwner)
        {
            indexOfOwner = given_indexOfOwner;
            owned = true;
        }
    
        public bool IsOwned()
        {
            return owned;
        }

        public int GetIndexOfOwner()
        {
            return indexOfOwner;
        }

        public int GetCost()
        {
            return cost;
        }

        public int GetRent()
        {
            return feeLevels[currentLevel];
        }
    
        public void Upgrade()
        {
            currentLevel++;
        }
   
        public void DisplayDetails()
        {
            Console.WriteLine("\n\t\tName:\t\t" + name);
            Console.WriteLine("\t\tCost:\t\t£" + cost);

            if (owned)
                Console.WriteLine("\t\tOwned:\t\tYes");
            else
                Console.WriteLine("\t\tOwned:\t\tNo");
                
            Console.WriteLine("\t\tCurrent level:\t" + currentLevel);
            
            for (int i = 0; i < feeLevels.Length; i++)
            {
                Console.WriteLine("\t\tLevel " + i + " stop:\t£" + feeLevels[i]);
            }
            Console.WriteLine();
        }
    }
}