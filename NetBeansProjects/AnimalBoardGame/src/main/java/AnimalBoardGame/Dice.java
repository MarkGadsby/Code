/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;

import java.util.Random;

/**
 *
 * @author M.Gadsby
 */
public class Dice 
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

    public int doubleRoll()
    {
        firstThrow = SingleRoll();
        secondThrow = SingleRoll();

        return firstThrow + secondThrow;
    }
    
    public boolean ThrewDouble()
    {
        if (firstThrow != -1 &&
            secondThrow != -1)
        {
            return firstThrow == secondThrow;
        }
        else
            return false;        
    }
    
    private int SingleRoll()
    {
        return rand.nextInt(6) + 1;
    }
}
