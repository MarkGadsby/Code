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
public class Instruction extends GameSpace
{
    boolean bIsStart;
    
    public Instruction(boolean given_isStart)
    {
        super.type = SpaceType.INSTRUCTION;
        bIsStart = given_isStart;
    }
    
    public boolean IsStart()
    {
        return bIsStart;
    }
}
