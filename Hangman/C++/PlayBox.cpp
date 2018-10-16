#include "CPlayBox.h"

#include <iostream>
#include <cstdlib>     // rand, srand
#include <ctime>

using namespace std;

void CPlayBox::PaparRockScissors()
{
    PRSSelection    computerSelection;
    PRSSelection    userSelection;

    cout << "\n\t";
    cout << "Would you like to play Paper, Rock, Scissors, with me?" << "\n\n\n";
    cout << "Just Press:" << "\n\n\n\t";
    cout << "'P' if you want to select paper" << "\n\n\t";
    cout << "'R' if you want to select rock" << "\n\n\t";
    cout << "'S' if you want to select scissors" << '\n';
    cout << '\n';
    cout << '\n';
    cout << "Good Luck!" << '\t';

    char userKeyPress = 0;
    cin >> userKeyPress;

    if (userKeyPress == 'R')
        userSelection = eRock;
    else if (userKeyPress == 'P')
        userSelection = ePaper;
    else if (userKeyPress == 'S')
        userSelection = eScissors;
    else
        userSelection = eUnknown;

    srand(time(0));
    computerSelection = (PRSSelection)(rand() % 3);

    cout << computerSelection << '\t' << userSelection;
    cin >> userKeyPress;
 }

void CPlayBox::Hangman()
{
    // set up list of countries and randomly select one
    string  countryArray[] = { "india", "japan", "nepal", "ethiopia", "china", "france", "vietnam" };
    srand(time(0));
 	string  selectedCountry = countryArray[rand() % 7];

    // introduce the game
 	cout << "\n\nCan you identify which country I'm thinking of by\n";
 	cout << "pressing letters that may be in the countries name?\n\n";
 	cout << "You have " << MAX_TRIES << " tries and the countries name is " << selectedCountry.length() << " letters long\n\n";
 	cout << "Good luck!\n\n";

	// initialise and display the revealed word.
    string  revealedWord(selectedCountry.length(), '-');
    cout << revealedWord;
    cout << "\n\n";

    // set up outer loop and required variables
    char    candidateLetter;
	int     nGuesses = MAX_TRIES;

    while (nGuesses &&
           revealedWord != selectedCountry)
    {
        // retrieve user guessed letter.
        cout << "Your turn to guess a letter: ";
        cin >> candidateLetter;
        cout << "\n\n";

        // set up inner loop and required variables
        bool    bFoundOne = false;

        int iSelectedCountryIndex = selectedCountry.length();
        while (iSelectedCountryIndex--)
        {
            if (candidateLetter == selectedCountry[iSelectedCountryIndex])
            {
                revealedWord[iSelectedCountryIndex] = candidateLetter;
                bFoundOne = true;
            }
        }

        // handle inner loop results
        if (bFoundOne)
            cout << "That's great you've found one!\n";
        else
        {
            cout << "No, that letter isn't in there!\n";
            // lose one guess
            nGuesses--;
        }

        cout << revealedWord;
        cout << "\n\n";
        cout << "Guesses left = " << nGuesses << "\n\n";
    }
    // handle outer loop results
    if (revealedWord == selectedCountry)
        cout << "You did it! The word was " << revealedWord << " very well done!\n\n";
    else if (nGuesses == 0)
    {
        cout << "Sorry, you've out of guesses and have been hanged.\n\n";
        cout << "The country was : " << selectedCountry << '\n';
    }
}
