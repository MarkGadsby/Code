#ifndef CPLAYBOX_H
#define CPLAYBOX_H

#include <iostream>
#include <cstdlib>     // rand, srand
#include <ctime>

using namespace std;

enum PRSSelection
{
    ePaper,
    eRock,
    eScissors,
    eUnknown
};

class CPlayBox
{
public:
    CPlayBox(){};
    virtual ~CPlayBox(){};

    void PaparRockScissors();
    void Hangman();
};

const   int MAX_TRIES = 5;

#endif // CPLAYBOX_H
