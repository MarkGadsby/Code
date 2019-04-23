class GameStateNode
{
public:
    GameStateNode(char*, int);
    ~GameStateNode(){};

    char* pGameState;
    int playStripSize;

    GameStateNode* pFrogBranch;
    GameStateNode* pToadBranch;

    bool IsFrogBranchEndStop;
    bool IsToadBranchEndStop;
    bool IsDeadBranch;
};

void AddNewMoves(GameStateNode*);
bool MakeFrogMove(GameStateNode*);
bool MakeToadMove(GameStateNode*);
void DisplayGameState(GameStateNode*);
void TransverseTree(GameStateNode*);
GameStateNode* FindOpenBranch(GameStateNode* node);