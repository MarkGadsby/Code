/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;

import java.util.ArrayList; // import the ArrayList class
import java.awt.Point;      
import java.util.Scanner;

/**
 *
 * @author M.Gadsby
 */
public class Board 
{
    String[] board = {
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

    private GameSpace[] gameSpaces = new GameSpace[26];
    private ArrayList<Player> players = new ArrayList<>(); 
    private int turn;
    private Dice dice;  
    private Scanner scanner;
        
    public Board(ArrayList<Player> given_players)
    {
        players = given_players;
        turn = 0;
        dice = new Dice();
        scanner = new Scanner(System.in);   
                
        gameSpaces[0] = new Instruction(true);
        gameSpaces[10] = new Animal("Ant", 60, 10, 30, 90, 250);
        gameSpaces[1] = new Animal("Badger", 100, 30, 90, 270, 550);
        gameSpaces[2] = new Animal("Monkey", 100, 30, 90, 270, 550);
        gameSpaces[3] = new Animal("Cow", 120, 10, 100, 300, 600);
        gameSpaces[4] = new Animal("Deer", 140, 30, 90, 270, 550);
        gameSpaces[5] = new Animal("Wolf", 140, 30, 90, 270, 550);
        gameSpaces[6] = new Animal("Lion", 160, 40, 100, 300, 600);
        gameSpaces[7] = new Animal("Bear", 180, 70, 200, 550, 950);
        gameSpaces[8] = new Animal("Duck", 180, 70, 200, 550, 950);
        gameSpaces[9] = new Animal("Pig", 200, 80, 220, 600, 1000);
        gameSpaces[11] = new Animal("Shark", 220, 90, 250, 700, 1050);
        gameSpaces[12] = new Animal("Eagle", 220, 90, 250, 700, 1050);
        gameSpaces[13] = new Instruction(false);
        gameSpaces[14] = new Animal("Snake", 240, 100, 300, 750, 1200);
        gameSpaces[15] = new Animal("Chicken", 260, 110, 330, 800, 1150);
        gameSpaces[16] = new Animal("Horse", 260, 110, 330, 800, 1150);
        gameSpaces[17] = new Animal("Bird", 280, 120, 360, 850, 1200);
        gameSpaces[18] = new Animal("Rabbit", 300, 115, 370, 1025, 1200);
        gameSpaces[19] = new Animal("Cat", 300, 115, 370, 1100, 1275);
        gameSpaces[20] = new Animal("Dog", 320, 125, 380, 1100, 1275);
        gameSpaces[21] = new Animal("Ape", 350, 130, 390, 900, 1275);
        gameSpaces[22] = new Animal("Pony", 350, 130, 390, 900, 1275);
        gameSpaces[23] = new Animal("Camel", 380, 150, 450, 1000, 1400);
        gameSpaces[24] = new Animal("Dolphin", 400, 175, 1100, 1300, 1500);
        gameSpaces[25] = new Animal("Bison", 400, 200, 1400, 1700, 2000);
    }
    
    private void DisplayBoard()
    {
        BoardPosition boardPos = new BoardPosition();
        
        for (int playerIndex = 0; playerIndex < players.size(); playerIndex++)
        {
            Point currentPoint = boardPos.GetCharPosFromBoardPos(players.get(playerIndex).GetBoardPos());
            Point prevPoint = boardPos.GetCharPosFromBoardPos(players.get(playerIndex).GetPrevBoardPos());
            
            // Establish player positions
            for (int row = 0; row <= 35; row++)
            {
                // clear previous postion
                if (prevPoint.x + playerIndex == row)
                {
                    String st = board[row];

                    st = st.substring(0, prevPoint.y) 
                    + " "
                    + st.substring(prevPoint.y + 1); 

                    board[row] = st;
                }

                // add new postion
                if (currentPoint.x + playerIndex == row)
                {
                    String st = board[row];

                    st = st.substring(0, currentPoint.y) 
                    + players.get(playerIndex).GetToken() 
                    + st.substring(currentPoint.y + 1); 

                    board[row] = st;
                }
                
                if (playerIndex == players.size() - 1)
                    System.out.println(board[row]); 
            }
        }
    }
    
    public void PlayGame()
    {
        while (TakeTurn() == true)
        {
        }

        for (Player p : players)
        {
            if (p.GetOutTheGame() != true)
            {
                System.out.println("\t\t\t**********************************");
                System.out.println("\t\t\tAnd the winner is ...." + p.GetName());
                System.out.println("\t\t\tWell done " + p.GetName() + " you're ace!");
                System.out.println("\t\t\t**********************************");
            }
        }
    }
    
    private boolean TakeTurn()
    {
        System.out.println("It's " + players.get(turn).GetName() + "'s turn");
        
        scanner.nextLine();

        PlayoutMove(dice.doubleRoll());
        
        GameSpace space = gameSpaces[(players.get(turn).GetBoardPos())];
        
        Animal      animalLandedOn;
        Instruction instructionLandedOn;

        System.out.println(players.get(turn).GetName() + " you have: £"  + players.get(turn).GetWealth());
        
        switch (space.type)
        {
            case ANIMAL:
            {
                animalLandedOn = (Animal)space;

                System.out.println(players.get(turn).GetName() + " you have landed on:");
                animalLandedOn.DisplayDetails();
                
                if (animalLandedOn.IsOwned())
                {
                    Player owner = players.get(animalLandedOn.GetIndexOfOwner());

                    if (owner != players.get(turn))
                    {
                        System.out.println(players.get(turn).GetName() + ", pay £" + animalLandedOn.GetRent() + " to " + owner.GetName());
                        
                        if (players.get(turn).SpendMoney(animalLandedOn.GetRent()))
                            owner.SaveMoney(animalLandedOn.GetRent());
                        else
                        {
                            System.out.println(players.get(turn).GetName() + " you're bust, and out the game!");
                            players.get(turn).SetOutTheGame(true);
                        }
                    }
                    else
                    {
                        System.out.println(players.get(turn).GetName() + " would you like to upgrade it?\t\tPress 'Y' or 'N'");
                        
                        if (scanner.nextLine().compareToIgnoreCase("Y") == 0)
                        {
                            if (!players.get(turn).SpendMoney(animalLandedOn.GetCost()))
                            {
                                System.out.println(players.get(turn).GetName() + " you're bust, and out the game!");
                                players.get(turn).SetOutTheGame(true);
                            }
                            else
                            {
                                animalLandedOn.Upgrade();
                                System.out.println("Upgraded successfully");
                                animalLandedOn.DisplayDetails();
                            }
                        }
                    }                        
                }
                else
                {
                    System.out.println(players.get(turn).GetName() + " would you like to buy it?\t\tPress 'Y' or 'N'");
                    
                    if (scanner.nextLine().compareToIgnoreCase("Y") == 0)
                    {
                        if (!players.get(turn).SpendMoney(animalLandedOn.GetCost()))
                        {
                            System.out.println(players.get(turn).GetName() + " you're bust, and out the game!");
                            players.get(turn).SetOutTheGame(true);
                        }
                        else
                        {
                            animalLandedOn.Buy(turn);
                            System.out.println("OK it's yours");
                            animalLandedOn.DisplayDetails();
                        }
                    }                    
                }
                    
                break;
            }
            case INSTRUCTION:
            {
                instructionLandedOn = (Instruction)space;
                if (instructionLandedOn.IsStart())
                {
                    System.out.println(players.get(turn).GetName() + " you have landed on Start, collect £1000");
                    players.get(turn).SaveMoney(500);
                }
                else // miss a turn
                {
                    System.out.println(players.get(turn).GetName() + " you miss the next turn");
                    players.get(turn).SetMissATurn(true);
                }
                break;
            }
        }

        System.out.println(players.get(turn).GetName() + " you have: £"  + players.get(turn).GetWealth());

        turn++;
        turn %= players.size();
        
        while (players.get(turn).GetOutTheGame() == true)
        {
            turn++;
            turn %= players.size();
        }
        
        if (players.get(turn).GetMissATurn() == true)
        {
            players.get(turn).SetMissATurn(false);
            turn++;
            turn %= players.size();
        }
        
        int activePlayers = players.size();
        
        for (Player p : players)
        {
            if (p.GetOutTheGame() == true)
                activePlayers--;
        }
        
        if (activePlayers == 1)
            return false;
        else
            return true;
    }
    
    private void ClearScreen()
    {
        for (int i = 0; i <= 60; i++)
        {
            System.out.println("");
        }
    }

    private void Pause(int millsecs)
    {
        try
        {
            Thread.sleep(millsecs);
        }
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }

    
    private void PauseScreen(int Rolled)
    {
        try
        {
            ClearScreen();
            DisplayBoard();
            System.out.println(players.get(turn).GetName() + " you rolled: " + Rolled);
            Thread.sleep(250);
        }
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }
    
    private void PlayoutMove(int numOfSpaces)
    {
        int Rolled = numOfSpaces;
        
        while (numOfSpaces-- > 0)
        {
            PauseScreen(Rolled);    
            players.get(turn).IncrementBoardPos(1);
            PauseScreen(Rolled);    
        }
    }
}
