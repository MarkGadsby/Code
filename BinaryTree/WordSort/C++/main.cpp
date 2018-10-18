#include <iostream>
#include <fstream>

using namespace std;

class CLeaf
{
public:
    CLeaf(string word);
    ~CLeaf();

    string  m_sWord;

    short   m_nInstances;

    CLeaf*  m_pLeft;
    CLeaf*  m_pRight;
};

CLeaf::CLeaf(string word)
{
    m_sWord = word;
    m_nInstances = 1;
    m_pLeft = NULL;
    m_pRight = NULL;
}

CLeaf::~CLeaf()
{
    delete (m_pLeft);
    delete (m_pRight);

    m_pLeft = m_pRight = 0;
}

CLeaf* insert(CLeaf* root, string newWord)
{
    if (!root)
        root = new CLeaf(newWord);
    else
    {
        if (newWord == root->m_sWord)
            root->m_nInstances++;
        else if (newWord < root->m_sWord)
            root->m_pLeft = insert(root->m_pLeft, newWord);
        else if (newWord > root->m_sWord)
            root->m_pRight = insert(root->m_pRight, newWord);
    }
    return root;
}

void traverseInOrder(CLeaf* root, ofstream* pSortedFile)
{
    if (!root)
        return;

    traverseInOrder(root->m_pLeft, pSortedFile);

    *pSortedFile << root->m_nInstances << '\t' << root->m_sWord <<'\n';

    traverseInOrder(root->m_pRight, pSortedFile);
}

int main()
{
    // open file
    ifstream    harryPotterFile;
    harryPotterFile.open("HarryPotter.txt");

    string      harryPotterWord;
    CLeaf*      pCLeaf = NULL;

    while (harryPotterFile >> harryPotterWord)
    {
        pCLeaf = insert(pCLeaf, harryPotterWord);
    }

    ofstream    sortedFile;
    sortedFile.open("Sorted.txt");

    traverseInOrder(pCLeaf, &sortedFile);

    harryPotterFile.close();
    sortedFile.close();
    delete (pCLeaf);
    return 0;
}
