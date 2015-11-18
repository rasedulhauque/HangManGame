#include<iostream>
#include<string>
#include<ctime>

using namespace std;
int revelCountryName(char, string, string &);

int main()
{
	cout << "\t\t\t\tHANG MAN" << endl;
	cout << "you could save yourself from hanging by guessing the country name!!! You will get 5 chances to guess it" << endl;
start:
	cout << "\n\n> Start" << endl;
	cout << "> Quit" << endl;
	string choice;
	cout << "\nI want to ";
	getline(cin, choice);
	if (choice == "start")
	{
		const int __MAX_TIRE = 5;
		int __WRONG_GUESS = 0;
		char userChoice;
		string __COUNTRYS[] = { "india","pakistan","nepal","malaysia","philippines","australia","iran","ethiopia","oman","indonesia","bangladesh","canada",
			"brazil","argentina","russia","turkey","venezuela","germany","france","italy","spain","england","bhutan","switzerland","sewden","denmark","costa rica",
			"united state","netherland","singapore","china","afghanistan","austria","belgium","bolivia","cambodia","colombia","japan","korea","croatia","norway",
			"switzerland","thailand","united kingdon","zimbabwe","sri lanka","papua new guinea","new zealand","saudi arabia","hungary"

		};
		srand(time(NULL));
		int randomNum = rand() % 50;
		string __COUNTRY = __COUNTRYS[randomNum];
		string __UNKNOWN(__COUNTRY.length(), '*');
		while (__WRONG_GUESS < __MAX_TIRE)
		{
			cout << "\n\n" << __UNKNOWN;
			cout << "\n\nGuess a letter:  ";
			cin >> userChoice;
			if (revelCountryName(userChoice, __COUNTRY, __UNKNOWN) == 0)
			{
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				__WRONG_GUESS++;
			}
			else
			{
				cout << endl << "You found a letter! Isn't that exciting!" << endl;
			}
			cout << "You have " << __MAX_TIRE - __WRONG_GUESS;
			cout << " guesses left." << endl;
			if (__COUNTRY == __UNKNOWN)
			{
				cout << __COUNTRY << endl;
				cout << "Yeah! You got it!";
				//break;
				cin.ignore();
				cin.get();
				goto start;
			}
		}
		if (__MAX_TIRE == __WRONG_GUESS)
		{
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The country was : " << __COUNTRY << endl;
			cin.ignore();
			cin.get();
			goto start;
		}
		//cin.ignore();
		//cin.get();

	}
	else
		exit;
	return 0;
}
int revelCountryName(char __GUESS, string __SECRET_COUNTRY, string &__GUESS_COUNTRY)
{
	int match = 0;
	for (int i = 0;i < __SECRET_COUNTRY.length();i++)
	{
		if (__GUESS == __GUESS_COUNTRY[i])
		{
			return 0;
		}
		if (__GUESS == __SECRET_COUNTRY[i])
		{
			__GUESS_COUNTRY[i] = __GUESS;
			match++;
		}
	}
	return match;
}