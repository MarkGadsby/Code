/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;

/**
 *
 * @author mark
 */
public class Main 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Dice diceThrow = new Dice();

        System.out.println(diceThrow.GetPairOfDiceRoll());
        System.out.println(diceThrow.ThrewDouble());

        // Set up the players
        System.out.println("Please select your token: ");

        char tokens[] = {'!', '{', '£', '$', '%', '&', '?'};
        
        for (int i = 0; i < tokens.length; i++)
        {
            System.out.println("press " + (i + 1) + " to choose " + tokens[i]);
        } 
    }     
}
