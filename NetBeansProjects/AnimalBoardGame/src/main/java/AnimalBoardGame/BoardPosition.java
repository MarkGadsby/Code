/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;
import java.awt.Point;      

/**
 *
 * @author M.Gadsby
 */
public class BoardPosition 
{
    Point[] playerPosLookup = 
    {
        new Point(1,4),
        new Point(1,13),
        new Point(1,22),
        new Point(1,31),
        new Point(1,40),
        new Point(1,49),
        new Point(1,58),
        new Point(1,67),
        new Point(6,67),
        new Point(11,67),
        new Point(16,67),
        new Point(21,67),
        new Point(26,67),
        new Point(31,67),
        new Point(31,58),
        new Point(31,49),
        new Point(31,40),
        new Point(31,31),
        new Point(31,22),
        new Point(31,13),
        new Point(31,4),
        new Point(26,4),
        new Point(21,4),
        new Point(16,4),
        new Point(11,4),
        new Point(6,4)
    };
   
    public Point GetCharPosFromBoardPos(int boardPos)
    {
        return playerPosLookup[boardPos];
    }
}
