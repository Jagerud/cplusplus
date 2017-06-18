#include "stdafx.h";
#include "iostream";
#include "ctime";
using namespace std;

int main()
{
	int money = 1000, roundMoneyValue, colorNumber, rouletteValue, gameEnder = 1;
	
	cout << "Welcome to the Roulette game \n";
	while (gameEnder != 0 && money >= 100) {		//Game continues as long as there is money and the user wants to spend it
		cout << "Use 100, 300 or 500 to continue playing \n";
		cin >> roundMoneyValue;	//input of amount chosen
		//Loops as long as money value is wrong or more than funds
		while ((money - roundMoneyValue < 0) || !(roundMoneyValue == 100 || roundMoneyValue == 300 || roundMoneyValue == 500)) { 
			cout << "Insuffient funds or wrong sum, please try again \n";
			cin >> roundMoneyValue;
		}
		money = money - roundMoneyValue;	//updates wallet
		cout << "You now have " << money << " left \n";
		cout << "Choose a color, type 50 for black or 51 for red, or a number between 1 and 36 \n";
		cin >> colorNumber;
		
			rouletteValue = rand() % 36 + 1;	//spins wheel 1-36
			if (colorNumber > 40) {
				if (rouletteValue % 2) {		//odd, red
					cout << "Red " << rouletteValue << "\n";
					if (colorNumber == 51) { //win
						roundMoneyValue = roundMoneyValue * 2;
						cout << "You won " << roundMoneyValue;
					}
					else {		//lose
						roundMoneyValue = 0;	//turn money is lost
						cout << "You lost \n";
					}
				}
				else {		//even, black
					cout << "Black " << rouletteValue << "\n";
					if (colorNumber == 50) { //win
						roundMoneyValue = roundMoneyValue * 2;
						cout << "You won " << roundMoneyValue;
					}
					else {		//lose
						roundMoneyValue = 0;	//turn money is lost
						cout << "You lost \n";
					}
				}
			}
			else {
				if (rouletteValue % 2) {		//odd, red
					cout << "Red " << rouletteValue << "\n";
				}
				else {
					cout << "Black " << rouletteValue << "\n";
				}
				if (rouletteValue == colorNumber) {	//player wins
					roundMoneyValue = roundMoneyValue * 10;
					cout << "You won " << roundMoneyValue;
				}
				else {		//lose
					roundMoneyValue = 0;
					cout << "You lost \n";
				}
			}
		
		money = money + roundMoneyValue;	//turn money is added to total money, might be 0
		if (money == 0) {
			cout << "Out of money! \n";
		}
		else
		{
			cout << "You now have " << money << "\n";
			cout << "To continue type any number or 0 to end \n";
			cin >> gameEnder;		//input if the user wants to end the game
		}
	}
    return 0;
}

