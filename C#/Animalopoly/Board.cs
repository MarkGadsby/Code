using System;
using System.Threading;

namespace Animalopoly
{
    public class Board 
    {
        string[] board = {
        "-------------------------------------------------------------------------",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "-------------------------------------------------------------------------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "----------                                                     ----------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "----------                                                     ----------",
        "|        |            -----------                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "----------            |         |                              ----------",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            |         |                              |        |",
        "|        |            -----------                              |        |",
        "----------                                                     ----------",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "|        |                                                     |        |",
        "-------------------------------------------------------------------------",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "|        |        |        |        |        |        |        |        |",
        "-------------------------------------------------------------------------"};

        private Player[] players; 
        private int turn;


        public Board(Player[] given_players)
        {
            players = given_players;
            turn = 2;
        }
        
        private void DisplayBoard()
        {
            BoardPosition boardPos = new BoardPosition();
            
            for (int playerIndex = 0; playerIndex < players.Length; playerIndex++)
            {
                Point currentPoint = boardPos.GetCharPosFromBoardPos(players[playerIndex].GetBoardPos());
                Point prevPoint = boardPos.GetCharPosFromBoardPos(players[playerIndex].GetPrevBoardPos());
                
                // Establish player positions
                for (int row = 0; row <= 35; row++)
                {
                    // clear previous postion
                    if (prevPoint.X + playerIndex == row)
                    {
                        string st = board[row];

                        st = st.Substring(0, prevPoint.Y) 
                        + " "
                        + st.Substring(prevPoint.Y + 1); 

                        board[row] = st;
                    }

                    // add new postion
                    if (currentPoint.X + playerIndex == row)
                    {
                        string st = board[row];

                        st = st.Substring(0, currentPoint.Y) 
                        + players[playerIndex].GetToken() 
                        + st.Substring(currentPoint.Y + 1); 

                        board[row] = st;
                    }
                    Console.WriteLine(board[row]); 
                }
            }
        }
        private void ClearScreen()
        {
            for (int i = 0; i <= 60; i++)
            {
                Console.WriteLine("");
            }
        }
        public void PlayoutMove(int numOfSpaces)
        {
            int Rolled = numOfSpaces;
        
            while (numOfSpaces-- > 0)
            {
                PauseScreen(Rolled);    
                players[turn].IncrementBoardPos(1);
                PauseScreen(Rolled);    
            }
        }
        private void PauseScreen(int Rolled)
        {
            ClearScreen();
            DisplayBoard();
            Console.WriteLine(players[turn].GetName() + " you rolled: " + Rolled);
            Thread.Sleep(250);
        }
    }
}