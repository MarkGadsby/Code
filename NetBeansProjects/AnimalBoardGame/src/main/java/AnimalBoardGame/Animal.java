/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;

/**
 *
 * @author M.Gadsby
 */
public class Animal extends GameSpace
{
    private String name;
    private int currentLevel;
    private int cost;
    private boolean owned;
    private int indexOfOwner;
    private int[] feeLevels = new int[4];  
    
    public Animal(String given_name, int given_cost, int fee_0, int fee_1, int fee_2, int fee_3)
    {
        super.type = SpaceType.ANIMAL;
        
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
    
    public boolean IsOwned()
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
        System.out.println("\n\t\tName:\t\t" + name);
        System.out.println("\t\tCost:\t\t£" + cost);

        if (owned)
            System.out.println("\t\tOwned:\t\tYes");
        else
            System.out.println("\t\tOwned:\t\tNo");
            
        System.out.println("\t\tCurrent level:\t" + currentLevel);
        
        for (int i = 0; i < feeLevels.length; i++)
        {
            System.out.println("\t\tLevel " + i + " stop:\t£" + feeLevels[i]);
        }
        System.out.println();
    }
}
