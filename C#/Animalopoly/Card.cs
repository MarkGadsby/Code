using System;

namespace Animalopoly
{
    class Card 
    {
        private int amount;
        private bool positive;
        private string[] pos_scenarios = new string[8];
        private string[] neg_scenarios = new string[8];

        private Random rand;
    
        public Card()
        {
            rand = new Random();
            
            pos_scenarios[0] = "You have won a beauty contest, collect £";
            pos_scenarios[1] = "You save a cat in a tree and the grateful owner gives you £";
            pos_scenarios[2] = "You win the lottery, collect £";
            pos_scenarios[3] = "You win a bursary to study computer science at university, collect £";
            pos_scenarios[4] = "You win a crossword competition, collect £";
            pos_scenarios[5] = "You find buried treasure in your garden worth £";
            pos_scenarios[6] = "You sell one of your parent's old 45 singles on Discogs, collect £";
            pos_scenarios[7] = "You are given a free bet on Bet365 and win £";

            neg_scenarios[0] = "You get caught holding a party in contravention of the covid-19 restriction, pay £";
            neg_scenarios[1] = "Maintenace repair bill, pay £";
            neg_scenarios[2] = "You risk your own money on Bet365 and lose £";
            neg_scenarios[3] = "You get caught speeding, pay £";
            neg_scenarios[4] = "Unpaid tax bill, pay £";
            neg_scenarios[5] = "Parking in residents' parking bay without permit, pay £";
            neg_scenarios[6] = "Pay university fees £";
            neg_scenarios[7] = "Pay bank fees £";
        }

        public bool PickRandom()
        {
            amount = rand.Next(5, 50);
            amount *= 10;

            positive = rand.Next() % 2 == 0;

            if (positive)
            {
                Console.WriteLine(pos_scenarios[rand.Next(0,7)] + amount);
            }
            else
            {
                Console.WriteLine(neg_scenarios[rand.Next(0,7)] + amount);
            }    

            return positive;
        } 

        public int GetAmount()
        {
            return amount;
        }
    }
}
