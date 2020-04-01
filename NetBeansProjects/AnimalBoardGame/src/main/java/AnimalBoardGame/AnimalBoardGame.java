/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AnimalBoardGame;

import java.util.ArrayList;
/**
 *
 * @author M.Gadsby
 */
public class AnimalBoardGame 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        PlayerInitialiser initPlay = new PlayerInitialiser();
        ArrayList<Player> players = initPlay.SetupEachPlayer();

        Board board = new Board(players);
        board.PlayGame();
    }
}
