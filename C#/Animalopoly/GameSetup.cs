using System.Collections.Generic;
using System;

namespace Animalopoly
{
    public class GameSetup 
    {
        private int numberOfPlayers;
 
        List<char> tokens = new List<char>();    

        public GameSetup()
        {
            ClearScreen();

            Console.WriteLine("\n\t\t*** Welcome to Animalopoly ***\n\n");
            
            do 
            {
                Console.WriteLine("How many people are playing today? Please enter between 2 and 4.");
                numberOfPlayers = Convert.ToInt32(Console.ReadLine());
            }
            while (numberOfPlayers > 4 || numberOfPlayers < 2); 
               
            tokens.Add('£');
            tokens.Add('$');
            tokens.Add('%');
            tokens.Add('&');
            tokens.Add('\\');
            tokens.Add('#');
            tokens.Add('|');
        }

        public List<Player> SetupAllPlayers()
        {
            List<Player> players = new List<Player>();
        
            int playerID = 1;

            while (numberOfPlayers-- != 0)
            {
                Console.WriteLine("\nPlayer " + playerID + ", please enter your name: ");

                String name = Console.ReadLine();

                Console.WriteLine("\nHi " + name + ", please chose a board token: ");  

                String input;
                int index = 0;
                do
                {
                    Console.WriteLine("\n\t" + tokens[index++ % tokens.Count] + "\n\n\tok\t- hit return\n\tmore\t- hit T");
                    input = Console.ReadLine();
                }
                while (input == "T"); 

                Console.WriteLine(name + " is: " + tokens[--index % tokens.Count]);
                char selectedToken = tokens[index % tokens.Count];

                tokens.RemoveAt(index % tokens.Count);
                
                players.Add(new Player(name, selectedToken));
                playerID++;
            }
            return players;
        }

        private void ClearScreen()
        {
            for (int i = 0; i <= 60; i++)
            {
                Console.WriteLine("");
            }
        }
    }
}