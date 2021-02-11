namespace Animalopoly
{
    enum InstructionType
    {
        START,
        MISS_A_TURN
    }

    class Instruction : Tile
    {
        private InstructionType instruction_type;
        public Instruction(InstructionType given_Instruction)
        {
            type = TileType.INSTRUCTION;
            instruction_type = given_Instruction;
        }
        public bool IsStart()
        {
            if (instruction_type == InstructionType.START)
                return true;
            else
                return false;
        }
    }
}