package AnimalBoardGame;

import java.util.Random;


public class Dice 
{
    private Random  rand;
    private int     firstRoll;
    private int     secondRoll;
    
    public Dice()
    {   
        rand = new Random();
        firstRoll = -1;
        secondRoll = -1;
    }

    public int GetPairOfDiceRoll()
    {
        firstRoll = GetSingleDiceRoll();
        secondRoll = GetSingleDiceRoll();
        
        return firstRoll + secondRoll;     
    }
    
    public boolean ThrewDouble()
    {
        if (firstRoll != -1 && secondRoll != -1)
        {
            return firstRoll == secondRoll;
        }
        else return false;                    
    }

    private int GetSingleDiceRoll()
    {
        return rand.nextInt(6) + 1;
    }
}
