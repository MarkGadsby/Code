namespace Animalopoly
{
    enum TileType
    {
        ANIMAL,
        INSTRUCTION
    }
    class Tile 
    {
        protected TileType type;

        public TileType get_type()
        {
            return type;
        }
    }
}
