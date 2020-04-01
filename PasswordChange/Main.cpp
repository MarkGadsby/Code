#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // open the file in read mode.
    ifstream passwordFileRead;
    passwordFileRead.open("Passwords.txt");

    if (!passwordFileRead.good())
    {
        cout << "Couldn't find the Passwords file on your disk\n";
        return 0;
    }
    
    cout << "Passwords file opened successfully\n";

    vector<string> listOfUsers;
    vector<string> listOfPasswords;
    string user;
    string password;

    while (passwordFileRead.good())
    {
        getline(passwordFileRead, user);
        listOfUsers.push_back(user);

        getline(passwordFileRead, password);
        listOfPasswords.push_back(password);
    }

    string input_username;
    string input_password;
    
    cout << "Please enter your username:\n";
    getline (cin, input_username);

    int index = -1;

    for (int i = 0; i <= listOfUsers.size(); i++)
    {
        if (listOfUsers[i].compare(input_username) == 0)
            index = i;
    }

    if (index == -1)
    {
        cout << "We don't have a registered user of that name\n";
        return 0;
    }

    cout << "Hi " << listOfUsers[index] << " please enter your password:\n";
    cin >> input_password;

    if (input_password.compare(listOfPasswords[index]) != 0)
    {
        cout << "That is not the password for your account\n";
        return 0;
    }

    string firstGo;
    string secondGo;

    cout << "\n** You are successfully logged in **\n\n";
    cout << "Please reset your password:\n";
    cin >> firstGo;
    cout << "Please retype new password:\n";
    cin >> secondGo;

    if (firstGo.compare(secondGo) == 0)
        cout << "Passwords match\n";
    else
    {
        cout << "Passwords do not match, please login again using your current password\n";
        return 0;
    }

    if (firstGo.length() < 8)
    {
        cout << "Passwords needs to be at least 8 characters long, please login again using your current password\n";
        return 0;
    }

    if (firstGo.length() < 8)
    {
        cout << "Passwords needs to be at least 8 characters long, please login again using your current password\n";
        return 0;
    }

    bool bUpper = false;
    bool blower = false;
    bool bdigit = false;

    for (char c : firstGo)
    {
        if (isupper(c))
            bUpper = true;
        if (islower(c))
            blower = true;
        if (isdigit(c))
            bdigit = true;     
    }

    if (bUpper == false || blower == false | bdigit == false)
    {        
        cout << "Passwords need to contain at least one upper case letter,\nat least one lower case letter and\nat least one digit.\n\nPlease login again using your current password\n";
        return 0;
    }

    for (int i = 0; i < listOfUsers.size(); i++)
    {
        if (index == i)
            listOfPasswords[index] = firstGo;
    }

    cout << "\n **Your password has been successfully changed**\n\n";

    passwordFileRead.close();

    ofstream passwordFileWrite;
    passwordFileWrite.open("Passwords.txt");

    for (int i = 0; i < listOfUsers.size(); i++)
    {
        passwordFileWrite << listOfUsers[i] << endl;
        passwordFileWrite << listOfPasswords[i];
        
        if (i < listOfUsers.size() -1)
            passwordFileWrite << endl;
    }

    passwordFileWrite.close();
}