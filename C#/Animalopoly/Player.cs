namespace Animalopoly
{
    public class Player
    {
        private string  name;
        private char    token;
        private int     boardPos;    
        private int     prevBoardPos;   
    
        public Player(string given_Name, char given_Token)
        {
            name = given_Name;
            token = given_Token;
            boardPos = 0;     
            prevBoardPos = 0;
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
        public void IncrementBoardPos(int moveBy)
        {
            prevBoardPos = boardPos;
            boardPos += moveBy;
            boardPos %= 26;
        }
    }   
}