#include <iostream>
#include "GameStateNode.h"

using namespace std;

GameStateNode::GameStateNode(char* playstrip, int array_size)
{
    pFrogBranch = NULL;
    pToadBranch = NULL;

    IsFrogBranchEndStop = false;
    IsToadBranchEndStop = false;
    IsDeadBranch = false;

    playStripSize = array_size;

    pGameState = new char[playStripSize];

    for (int i = 0; i < playStripSize; i++)
    {
        pGameState[i] = playstrip[i];
    }
}

int main()
{
    int nFrogs = 0;

    cout << "Welcome to frogs and toads game" << endl;
    cout << "Please enter the number of frogs" << endl;
    cout << "and toads that are playing today" << endl;
    cin >> nFrogs;

    int nToads = nFrogs;

    int playStripSize = nFrogs + nToads + 2 + 1 + 1; // frogs, toads, two end slots, one empty slot and one null terminator. 
    char* initialGameState = new char[playStripSize];

    int index = 0;

    initialGameState[index] = '-';
    index++;

    while (nFrogs != 0) 
    {
        initialGameState[index] = 'F';
        index++;
        nFrogs--;
    }

    initialGameState[index] = '_';
    index++;

    while (nToads)
    {
        initialGameState[index] = 'T';
        index++;
        nToads--;
    }

    initialGameState[index] = '-';
    index++;

    // Null terminate
    initialGameState[index] = '\0';
   
    GameStateNode* pMove = new GameStateNode(initialGameState, playStripSize);

    delete []initialGameState;

    DisplayGameState(pMove);

    cout << "To play press F for frog move or T for toad move" << endl;

    char userChoice = 0;
    int MovesAvailable = 2;

    while (MovesAvailable > 0)
    {
        cin >> userChoice;

        if (userChoice == 'F' || userChoice == 'f')
        {
            if (MakeFrogMove(pMove) == false)
            {
                cout << "No frog move is possilbe" << endl;
                MovesAvailable--;
            }
        }
        else if (userChoice == 'T' || userChoice == 't')
        {
            if (MakeToadMove(pMove) == false)
            {
                cout << "No toad move is possilbe" << endl;
                MovesAvailable--;
            }
        }
        else
        {
            cout << "I didn't recognise that command" << endl;
        }
        DisplayGameState(pMove);
    }
    return 0;
}

GameStateNode* FindOpenBranch(GameStateNode* node)
{
    if (node->pFrogBranch == NULL &&
        node->pToadBranch == NULL)
    {
        cout << "About to return mode" << endl; 
        return node;
    }

    if (node->pFrogBranch != NULL)
        FindOpenBranch(node->pFrogBranch);

    if (node->pToadBranch != NULL)
        FindOpenBranch(node->pToadBranch);
}

void TransverseTree(GameStateNode* node)
{
    DisplayGameState(node);
    if (node->pFrogBranch != NULL)
        TransverseTree(node->pFrogBranch);
    
    if (node->pToadBranch != NULL)
        TransverseTree(node->pToadBranch);
}

void DisplayGameState(GameStateNode* nodeToDisplay)
{
//    cout << "Node memory location: " << nodeToDisplay << endl; 
    cout << "Node game state: " << nodeToDisplay->pGameState << endl; 
//    cout << "Node pFrogBranch: " << nodeToDisplay->pFrogBranch << endl; 
//    cout << "Node pToadBranch: " << nodeToDisplay->pToadBranch << endl; 
}

void AddNewMoves(GameStateNode* pBase)
{
    // Make frog move
    GameStateNode* pPossFrogBranch = new GameStateNode(pBase->pGameState, pBase->playStripSize);
    
    if (MakeFrogMove(pPossFrogBranch) == true)
        pBase->pFrogBranch = pPossFrogBranch;
    else
    {
        pBase->pFrogBranch = NULL;
        pBase->IsFrogBranchEndStop = true;
    }

    // Make toad move
    GameStateNode* pPossToadBranch = new GameStateNode(pBase->pGameState, pBase->playStripSize);

    if (MakeToadMove(pPossToadBranch) == true)
        pBase->pToadBranch = pPossToadBranch;
    else
    {
        pBase->pToadBranch = NULL;
        pBase->IsToadBranchEndStop = true;
    }
}

bool MakeFrogMove(GameStateNode* pNewGameState)
{
    for (int i = 0; i < pNewGameState->playStripSize; i++)
    {
        if (pNewGameState->pGameState[i] == 'F')
        {
            if (pNewGameState->pGameState[i + 1] == '_')
            {
                pNewGameState->pGameState[i] = '_';
                pNewGameState->pGameState[i + 1] = 'F';
                return true;                   
            }
            
            if (pNewGameState->pGameState[i + 1] == 'T' &&
                pNewGameState->pGameState[i + 2] == '_')
            {
                pNewGameState->pGameState[i] = '_';
                pNewGameState->pGameState[i + 2] = 'F';
                return true;
            }
        }
    }
    return false;
}

bool MakeToadMove(GameStateNode* pNewGameState)
{
    for (int i = 0; i < pNewGameState->playStripSize; i++)
    {
        if (pNewGameState->pGameState[i] == 'T')
        {
            if (pNewGameState->pGameState[i - 1] == '_')
            {
                pNewGameState->pGameState[i] = '_';
                pNewGameState->pGameState[i - 1] = 'T';

                return true;                   
            }
            
            if (pNewGameState->pGameState[i - 1] == 'F' &&
                pNewGameState->pGameState[i - 2] == '_')
            {
                pNewGameState->pGameState[i] = '_';
                pNewGameState->pGameState[i - 2] = 'T';

                return true;
            }
        }
    }
    return false;
}



