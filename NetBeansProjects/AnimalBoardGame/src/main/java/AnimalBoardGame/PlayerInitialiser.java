/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author M.Gadsby
 */
public class PlayerInitialiser 
{
    private ArrayList<Character> tokens = new ArrayList<>();
    private int numberOfPlayers;
    private Scanner scanner;


    public PlayerInitialiser()
    {
        ClearScreen();
        
        scanner = new Scanner(System.in);     
        
        System.out.println("\n\t\t*** Welcome to Animalopoly ***\n\n");
        System.out.println("How many people are playing today?");
        
        numberOfPlayers = Integer.parseInt(scanner.nextLine());
                
        tokens.add('£');
        tokens.add('$');
        tokens.add('%');
        tokens.add('&');
        tokens.add('\\');
        tokens.add('#');
        tokens.add('|');
    }

    public ArrayList<Player> SetupEachPlayer()
    {
        ArrayList<Player> players  = new ArrayList<>();
        
        int playerID = 1;

        while (numberOfPlayers-- != 0)
        {
            System.out.println("\nPlayer " + playerID + ", please enter your name: ");
            String name = scanner.nextLine();

            System.out.println("\nHi " + name + ", please chose a board token: ");  

            String input;
            int index = 0;
            do
            {
                System.out.println("\n\t" + tokens.get(index++ % tokens.size()) + "\n\n\tok\t- hit return\n\tmore\t- hit T");
                input = scanner.nextLine();
            }
            while (input.equalsIgnoreCase("T")); 

            System.out.println(name + " is: " + tokens.get(--index % tokens.size()));
            Character selectedToken = tokens.remove(index % tokens.size());

            players.add(new Player(name, selectedToken));
            playerID++;
        }
        return players;
    }
    
    private void ClearScreen()
    {
        for (int i = 0; i <= 60; i++)
        {
            System.out.println("");
        }
    }
}
