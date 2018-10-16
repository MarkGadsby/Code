#include <iostream>

using namespace std;

char GetEncryptedText(char plainLetter, int shiftValue)
{
    if (plainLetter >= 65 &&
        plainLetter <= 90)
    {
        return (((plainLetter - 65 + shiftValue) % 26) + 26) % 26 + 65;
    }

    if (plainLetter >= 97 &&
        plainLetter <= 122)
    {
        return (((plainLetter - 97 + shiftValue) % 26) + 26) % 26 + 97;
    }

    if (plainLetter >= 48 &&
        plainLetter <= 57)
    {
        return (((plainLetter - 48 + shiftValue) % 10) + 10) % 10 + 48;
    }
    return plainLetter;
}

int main()
{
    string plainText;
    string codedText;

    int shiftValue = 0;
    cout << "Enter your message" << endl;
    getline(cin, plainText);

    cout << "Enter your shift number" << endl;
    cin >> shiftValue;

    int i = plainText.size();

    while(i--)
        codedText.insert(0, 1, GetEncryptedText(plainText[i], shiftValue));

    cout << codedText << endl;

    cout << ".. and back the other way" << endl;
    cin >> shiftValue;

    i = codedText.size();

    while(i--)
        plainText[i] = GetEncryptedText(codedText[i], shiftValue);

    cout << plainText << endl;
    return 0;
}
