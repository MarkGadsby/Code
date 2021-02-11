using System;
using System.Collections.Generic;

namespace Animalopoly
{
    class Game
    {
        static void Main(string[] args)
        {

            GameSetup gameSetup = new GameSetup();
            List<Player> players = gameSetup.SetupAllPlayers();

            Board board = new Board(players);
            board.PlayGame();
        }
    }
}
