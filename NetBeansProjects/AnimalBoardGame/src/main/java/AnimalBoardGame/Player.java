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
public class Player
{
    private String      name;
    private Character   token;
    private int         wealth;
    private int         boardPos;    
    private int         prevBoardPos;   
    private boolean     miss_a_turn;
    private boolean     out_the_game;
    
    Player(String given_Name, Character given_Token)
    {
        name = given_Name;
        token = given_Token;
        wealth = 500;
        boardPos = 0;     
        prevBoardPos = 0;
        miss_a_turn = false;
        out_the_game = false;
    }
    
    public void SaveMoney(int amount)
    {
        wealth += amount;    
    } 

    public boolean SpendMoney(int amount)
    {
        wealth -= amount;    
        return wealth >= 0;
    }  
    
    public int GetWealth()
    {
        return wealth;
    }
    
    public int GetBoardPos()
    {
        return boardPos;
    }

    public int GetPrevBoardPos()
    {
        return prevBoardPos;
    }
    
    public Character GetToken()
    {
        return token;
    }

    public String GetName()
    {
        return name;
    }

    public void SetMissATurn(boolean newState)
    {
        miss_a_turn = newState;
    }

    public boolean GetMissATurn()
    {
        return miss_a_turn;
    }

    public void SetOutTheGame(boolean newState)
    {
        out_the_game = newState;
    }

    public boolean GetOutTheGame()
    {
        return out_the_game;
    }
    
        public void IncrementBoardPos(int moveBy)
    {
        prevBoardPos = boardPos;
        boardPos += moveBy;
        boardPos %= 26;
        
        // handle passing go
        if (boardPos == 0)
            SaveMoney(500);
    }   
}