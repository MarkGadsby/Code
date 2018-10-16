#include <iostream>
using namespace std;

bool CompareFunction(int nPlayer, int nComputer)
{
	if (nPlayer == nComputer)
	{
		cout << "You did it! Well Done.";
		return true;
	}
		
	if (nPlayer < nComputer)
		cout << "No it's higher than that\n";
	
	if (nPlayer > nComputer)
		cout << "No it's lower than that\n";
	
	return false;	
}


int main(int argc, char **argv)
{
	int nComputer = 23;
	int nPlayer = 0;

	cout << "Please guess my number\n : ";
	cin >> nPlayer;

	for (int i = 0; i < 10; i++)
	{
		if (CompareFunction(nPlayer,nComputer))
			return 0;
		else
		{
			cout << "Have another go : ";
			cin >> nPlayer;
		}		
	}
	return 0;
}

