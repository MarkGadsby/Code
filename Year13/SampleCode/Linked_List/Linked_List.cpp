#include <linux/limits.h>
#include <iostream>
#include <cstring>

class Node
{
public:
    int priority;
    char name[NAME_MAX];
    Node* pNext;
};

Node* pHead = NULL;

void ShowYourself()
{
    Node* pListRunner = pHead;

    printf("\n\nThe current list state is:\n");
    printf("\nName:\t\tPriority:\n");

    while (pListRunner != NULL)
    {
        printf("\n%s\t\t%i", pListRunner->name, pListRunner->priority);
        pListRunner = pListRunner->pNext;
    }
}

void FreeMemory()
{
    Node* pListRunner = pHead;

    while (pListRunner != NULL)
    {
        delete(pListRunner);
        pListRunner = pListRunner->pNext;
    }
}

void add_to_front(char name_to_add[NAME_MAX], int priority_of_name)
{
    // allocate dynamic memory (from the heap) for the new node
    Node* pNewNode = new Node();

    // initialise the node
    pNewNode->priority = priority_of_name;
    strcpy(pNewNode->name, name_to_add);

    // New node points to the current head of the list
    pNewNode->pNext = pHead;
    // Head of the list points to the new node
    pHead = pNewNode;
}

void add_to_back(char name_to_add[NAME_MAX], int priority_of_name) 
{
    // allocate dynamic memory (from the heap) for the new node
    Node* pNewNode = new Node();

    // initialise the node
    pNewNode->priority = priority_of_name;
    strcpy(pNewNode->name, name_to_add);

    // Check if the list is empty
    if (pHead == NULL)
    {
        pHead = pNewNode;
    }
    else
    {
        Node* pListRunner = pHead;
        while (pListRunner->pNext != NULL)
        {
            pListRunner = pListRunner->pNext;
        }
        pListRunner->pNext = pNewNode;
    }
}

bool remove_name(char name_to_remove[NAME_MAX])
{
    // Check if the list is empty
    if (pHead == NULL)
    {
        return false;
    }

    // Start from the head of the list
    Node* pListRunner = pHead;
    Node* pPrevious = NULL;

    bool found = false;   

    // If the element to delete is at the head
    if (strcmp(pListRunner->name, name_to_remove) == 0)
    {
        // Free the heap memory, like good citizens
        delete(pHead);
        // Move the head to point to the next node  
        pHead = pListRunner->pNext;
        return true;
    }
    else
    {
        // Go through the elements of the list until you find the node
        // or reach the end of the list
        while (found == false && pListRunner->pNext != NULL)
        {
            // Stop when you find the node to delete
            if (strcmp(pListRunner->name, name_to_remove) == 0)
                found = true;
            else
            {
                pPrevious = pListRunner;            // Keep track of the previous node
                pListRunner = pListRunner->pNext;   // Move to the next node        
            }
        }
    }
    // If you reached the end of the list and did not find the element
    if (pListRunner->pNext == NULL && found == false)
    {
        return false;
    }

    // make the previous node point to the node
    // that comes after the node to delete
    pPrevious->pNext = pListRunner->pNext;

    // Free the heap memory, like good citizens
    delete(pListRunner);
    return true;
}

bool remove_priority(int priority)
{
    // Check if the list is empty
    if (pHead == NULL)
    {
        return false;
    }

    // Start from the head of the list
    Node* pListRunner = pHead;
    Node* pPrevious = NULL;

    bool found = false;   

    // If the element to delete is at the head
    if (pListRunner->priority == priority)
    {
        // Free the heap memory, like good citizens
        delete(pHead);
        // Move the head to point to the next node  
        pHead = pListRunner->pNext;
        return true;
    }
    else
    {
        // Go through the elements of the list until you find the node
        // or reach the end of the list
        while (found == false && pListRunner != NULL)
        {
            // Stop when you find the node to delete
            if (pListRunner->priority == priority)
                found = true;
            else
            {
                pPrevious = pListRunner;            // Keep track of the previous node
                pListRunner = pListRunner->pNext;   // Move to the next node        
            }
        }
    }
    // If you reached the end of the list and did not find the element
    if (pListRunner == NULL && found == false)
    {
        return false;
    }

    // make the previous node point to the node
    // that comes after the node to delete
    pPrevious->pNext = pListRunner->pNext;

    // Free the heap memory, like good citizens
    delete(pListRunner);
    return true;
}

int main()
{
    add_to_back((char*)"Hattie", 5);
    ShowYourself();

    add_to_back((char*)"Barbara", 12);
    ShowYourself();

    add_to_back((char*)"Sidney", 1);
    ShowYourself();

    add_to_front((char*)"Kenneth", 8);
    ShowYourself();

    add_to_front((char*)"Charles", 6);
    ShowYourself();

    add_to_back((char*)"Leslie", 7);
    ShowYourself();

    int i = 12;

    while (i)
    {
        remove_priority(i);
        ShowYourself();
        i--;
    }

    FreeMemory();
}