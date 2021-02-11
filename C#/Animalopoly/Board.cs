using System;
using System.Threading;
using System.Collections.Generic;

namespace Animalopoly
{
    public class Board 
    {
        string[] board = {
        "-------------------------------------------------------------------------",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "-------------------------------------------------------------------------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "----------                                                     ----------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "----------                                                     ----------",
        "|        |            -----------                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "----------            |         |                              ----------",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            -----------                              |        |",
        "----------                                                     ----------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "-------------------------------------------------------------------------",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "-------------------------------------------------------------------------"};

        private List<Player> players; 
        private Tile[] tiles = new Tile[26]; 
        private int turn;
        private Dice dice;


        public Board(List<Player> given_players)
        {
            players = given_players;
            turn = 0;

            dice = new Dice();

            tiles[0] = new Instruction(InstructionType.START);
            tiles[1] = new Animal("Ant", 60, 10, 30, 90, 250);
            tiles[2] = new Animal("Monkey", 100, 30, 90, 270, 550);
            tiles[3] = new Animal("Badger", 100, 30, 90, 270, 550);
            tiles[4] = new Animal("Cow", 120, 10, 100, 300, 600);
            tiles[5] = new Animal("Deer", 140, 30, 90, 270, 550);
            tiles[6] = new Animal("Wolf", 140, 30, 90, 270, 550);
            tiles[7] = new Animal("Lion", 160, 40, 100, 300, 600);
            tiles[8] = new Animal("Bear", 180, 70, 200, 550, 950);
            tiles[9] = new Animal("Duck", 180, 70, 200, 550, 950);
            tiles[10] = new Animal("Pig", 200, 80, 220, 600, 1000);
            tiles[11] = new Animal("Shark", 220, 90, 250, 700, 1050);
            tiles[12] = new Animal("Eagle", 220, 90, 250, 700, 1050);
            tiles[13] = new Instruction(InstructionType.MISS_A_TURN);
            tiles[14] = new Animal("Snake", 240, 100, 300, 750, 1200);
            tiles[15] = new Animal("Chicken", 260, 110, 330, 800, 1150);
            tiles[16] = new Animal("Horse", 260, 110, 330, 800, 1150);
            tiles[17] = new Animal("Bird", 280, 120, 360, 850, 1200);
            tiles[18] = new Animal("Rabbit", 300, 115, 370, 1025, 1200);
            tiles[19] = new Animal("Cat", 300, 115, 370, 1100, 1275);
            tiles[20] = new Animal("Dog", 320, 125, 380, 1100, 1275);
            tiles[21] = new Animal("Ape", 350, 130, 390, 900, 1275);
            tiles[22] = new Animal("Pony", 350, 130, 390, 900, 1275);
            tiles[23] = new Animal("Camel", 380, 150, 450, 1000, 1400);
            tiles[24] = new Animal("Dolphin", 400, 175, 1100, 1300, 1500);
            tiles[25] = new Animal("Bison", 400, 200, 1400, 1700, 2000);
        }
        
        private void DisplayBoard()
        {
            BoardPosition boardPos = new BoardPosition();
            
            for (int playerIndex = 0; playerIndex < players.Count; playerIndex++)
            {
                Point currentPoint = boardPos.GetCharPosFromBoardPos(players[playerIndex].GetBoardPos());
                Point prevPoint = boardPos.GetCharPosFromBoardPos(players[playerIndex].GetPrevBoardPos());
                
                // Establish player positions
                for (int row = 0; row <= 35; row++)
                {
                    // clear previous postion
                    if (prevPoint.X + playerIndex == row)
                    {
                        string st = board[row];

                        st = st.Substring(0, prevPoint.Y) 
                        + " "
                        + st.Substring(prevPoint.Y + 1); 

                        board[row] = st;
                    }

                    // add new postion
                    if (currentPoint.X + playerIndex == row)
                    {
                        string st = board[row];

                        st = st.Substring(0, currentPoint.Y) 
                        + players[playerIndex].GetToken() 
                        + st.Substring(currentPoint.Y + 1); 

                        board[row] = st;
                    }

                    // Only display the board once 
                    if (playerIndex == players.Count - 1)
                        Console.WriteLine(board[row]); 
                }
            }
        }
        private void ClearScreen()
        {
            for (int i = 0; i <= 60; i++)
            {
                Console.WriteLine("");
            }
        }

        public void PlayGame()
        {
            while (TakeTurn() == true)
            {
            }

            foreach (Player p in players)
            {
                if (p.GetOutTheGame() != true)
                {
                    Console.WriteLine("\t\t\t**********************************");
                    Console.WriteLine("\t\t\tAnd the winner is ...." + p.GetName());
                    Console.WriteLine("\t\t\tWell done " + p.GetName() + " you're ace!");
                    Console.WriteLine("\t\t\t**********************************");
                }
            }
        }
    
        private bool TakeTurn()
        {
            Console.WriteLine("It's " + players[turn].GetName() + "'s turn");
            Console.ReadLine();

            int diceRoll = dice.GetRollTotal();

            if (dice.ThrewDouble())
            {
                Console.WriteLine(players[turn].GetName() + " you have: £"  + players[turn].GetWealth());
                Console.WriteLine(players[turn].GetName() + " you threw a double! Pick a card");
                Console.ReadLine();
       
                Card cd = new Card();

                if (cd.PickRandom())
                {
                    players[turn].SaveMoney(cd.GetAmount());
                }
                else
                {
                    if (!players[turn].SpendMoney(cd.GetAmount()))
                    {
                        Console.WriteLine(players[turn].GetName() + " you're bust, and out the game!");
                        players[turn].SetOutTheGame(true);
                    }
                }
            }
            else
            {
                PlayoutMove(diceRoll);
                
                Tile space = tiles[(players[turn].GetBoardPos())];

                Console.WriteLine(players[turn].GetName() + " you have: £"  + players[turn].GetWealth());
                
                switch (space.get_type())
                {
                    case TileType.ANIMAL:
                    {
                        Animal animalLandedOn = (Animal)space;

                        Console.WriteLine(players[turn].GetName() + " you have landed on:");
                        animalLandedOn.DisplayDetails();
                        
                        if (animalLandedOn.IsOwned())
                        {
                            Player owner = players[animalLandedOn.GetIndexOfOwner()];

                            if (owner != players[turn])
                            {
                                Console.WriteLine(players[turn].GetName() + ", pay £" + animalLandedOn.GetRent() + " to " + owner.GetName());
                                
                                if (players[turn].SpendMoney(animalLandedOn.GetRent()))
                                {
                                    owner.SaveMoney(animalLandedOn.GetRent());
                                }
                                else
                                {
                                    Console.WriteLine(players[turn].GetName() + " you're bust, and out the game!");
                                    players[turn].SetOutTheGame(true);
                                }
                            }
                            else
                            {
                                Console.WriteLine(players[turn].GetName() + " would you like to upgrade it?\t\tPress 'Y' or 'N'");
                                
                                if (Console.ReadLine().CompareTo("Y") == 0)
                                {
                                    if (!players[turn].SpendMoney(animalLandedOn.GetCost()))
                                    {
                                        Console.WriteLine(players[turn].GetName() + " you're bust, and out the game!");
                                        players[turn].SetOutTheGame(true);
                                    }
                                    else
                                    {
                                        animalLandedOn.Upgrade();
                                        Console.WriteLine("Upgraded successfully");
                                        animalLandedOn.DisplayDetails();
                                    }
                                }
                            }                        
                        }
                        else
                        {
                            Console.WriteLine(players[turn].GetName() + " would you like to buy it?\t\tPress 'Y' or 'N'");
                            
                            if (Console.ReadLine().CompareTo("Y") == 0)
                            {
                                if (!players[turn].SpendMoney(animalLandedOn.GetCost()))
                                {
                                    Console.WriteLine(players[turn].GetName() + " you're bust, and out the game!");
                                    players[turn].SetOutTheGame(true);
                                }
                                else
                                {
                                    animalLandedOn.Buy(turn);
                                    Console.WriteLine("OK it's yours");
                                    animalLandedOn.DisplayDetails();
                                }
                            }                    
                        }                        
                        break;
                    }
                    case TileType.INSTRUCTION:
                    {
                        Instruction instructionLandedOn = (Instruction)space;

                        if (instructionLandedOn.IsStart())
                        {
                            Console.WriteLine(players[turn].GetName() + " you have landed on Start, collect £1000");
                            players[turn].SaveMoney(1000); 
                        }
                        else // miss a turn
                        {
                            Console.WriteLine(players[turn].GetName() + " you miss the next turn");
                            players[turn].SetMissATurn(true);
                        }
                        break;
                    }
                }

            }

            Console.WriteLine(players[turn].GetName() + " you have: £"  + players[turn].GetWealth());

            turn++;
            turn %= players.Count;
            
            while (players[turn].GetOutTheGame() == true)
            {
                turn++;
                turn %= players.Count;
            }
            
            if (players[turn].GetMissATurn() == true)
            {
                players[turn].SetMissATurn(false);
                turn++;
                turn %= players.Count;
            }
            
            int activePlayers = players.Count;
            
            foreach (Player p in players)
            {
                if (p.GetOutTheGame() == true)
                    activePlayers--;
            }
            
            if (activePlayers == 1)
                return false;
            else
                return true;
        }

        private void PlayoutMove(int numOfSpaces)
        {
            int Rolled = numOfSpaces;
        
            while (numOfSpaces-- > 0)
            {
                PauseScreen(Rolled);    
                players[turn].IncrementBoardPos(1);
                PauseScreen(Rolled);    
            }
        }
        private void PauseScreen(int Rolled)
        {
            ClearScreen();
            DisplayBoard();
            Console.WriteLine(players[turn].GetName() + " you rolled: " + Rolled);
            Thread.Sleep(250);
        }
    }
}