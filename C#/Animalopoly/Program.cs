using System;

namespace Animalopoly
{
    class Game
    {
        static void Main(string[] args)
        {
            Player[] players = new Player[4];

            players[0] = new Player("Mark",'%');
            players[1] = new Player("Josh",'$');
            players[2] = new Player("Abdul",'"');
            players[3] = new Player("Jade",'*');

            Board board = new Board(players);
            board.PlayoutMove(10);
        }
    }
}
