namespace Animalopoly
{
    public class Player
    {
        private string  name;
        private char    token;
        private int     boardPos;    
        private int     prevBoardPos;   
        private int     wealth;
        private bool    miss_a_turn;
        private bool    out_the_game;
    
        public Player(string given_Name, char given_Token)
        {
            name = given_Name;
            token = given_Token;
            boardPos = 0;     
            prevBoardPos = 0;
            wealth = 500;
            miss_a_turn = false;
            out_the_game = false;
        }

        public int GetBoardPos()
        {
            return boardPos;
        }

        public int GetPrevBoardPos()
        {
            return prevBoardPos;
        }

        public char GetToken()
        {
            return token;
        }

        public string GetName()
        {
            return name;
        }    

        public void SaveMoney(int amount)
        {
            wealth += amount;    
        } 

        public bool SpendMoney(int amount)
        {
            wealth -= amount;    
            return wealth >= 0;
        }  
    
        public int GetWealth()
        {
            return wealth;
        }

        public void SetMissATurn(bool newState)
        {
            miss_a_turn = newState;
        }

        public bool GetMissATurn()
        {
            return miss_a_turn;
        }

        public void SetOutTheGame(bool newState)
        {
            out_the_game = newState;
        }

        public bool GetOutTheGame()
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
}