#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

// node class constructor
class node
{
public:
    node(string word);
    ~node();

    string  m_sWord;
    short   m_nInstances;
    node*   m_pLeft;
    node*   m_pRight;
};

// node constructor
node::node(string word)
{
    m_sWord = word;
    m_nInstances = 1;
    m_pLeft = NULL;
    m_pRight = NULL;
}

// node destructor
node::~node()
{
    delete (m_pLeft);
    delete (m_pRight);
    m_pLeft = m_pRight = NULL;
}

// utility function to add a word to the tree
node* insert(node* root, string newWord)
{
    if (!root)
      root = new node(newWord);
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

// utility function to read the tree from left to right
void traverseInOrder(node* root, ofstream* pSortedFile)
{
    if (!root)
        return;

    traverseInOrder(root->m_pLeft, pSortedFile);
    *pSortedFile << root->m_nInstances << '\t' << root->m_sWord <<'\n';
    traverseInOrder(root->m_pRight, pSortedFile);
}

int main()
{
    clock_t startTime = clock();

    ifstream readFile;
    readFile.open("../TestData/Shakespeare.txt");

    string singleWord;
    node* pNode = NULL;
    int totalwords = 0;

    while (readFile >> singleWord)
    {
        totalwords++;
        pNode = insert(pNode, singleWord);
    }

    ofstream sortedFile;
    sortedFile.open("Sorted.txt");

    traverseInOrder(pNode, &sortedFile);

    readFile.close();
    sortedFile.close();

    delete (pNode);

    clock_t endTime = clock();
    printf("\nC++: Total words = %d, Total time = %g\n\n", totalwords, ((double) (endTime - startTime)) /  CLOCKS_PER_SEC);

    return 0;
}
