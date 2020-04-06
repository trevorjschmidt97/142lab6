/* PLINKO LAB
Nathan Tietjen and Trevor Schmidt
nathan.c.tietjen@gmail.com and trevorjschmidt97@gmail.com
CS 142 Section 06
9-27-2018*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

double ComputeWinnings(int slot) {
	int chipPosition = slot;
	double totalWinnings = 0;
	cout << fixed << setprecision(1) << chipPosition << "]" << endl;
	switch (static_cast<int>(chipPosition)) {
	case 0:
		totalWinnings = totalWinnings + 100.00;
		break;
	case 1:
		totalWinnings = totalWinnings + 500.00;
		break;
	case 2:
		totalWinnings = totalWinnings + 1000.00;
		break;
	case 3:
		totalWinnings = totalWinnings + 0.00;
		break;
	case 4:
		totalWinnings = totalWinnings + 10000.00;
		break;
	case 5:
		totalWinnings = totalWinnings + 0.00;
		break;
	case 6:
		totalWinnings = totalWinnings + 1000.00;
		break;
	case 7:
		totalWinnings = totalWinnings + 500.00;
		break;
	case 8:
		totalWinnings = totalWinnings + 100.00;
		break;
	}
	return totalWinnings;
}

double DropChip(int slot) {
	int random = 0;
	cout << "*** Dropping chip into slot " << slot << " ***" << endl;
	int chipPosition = slot;
	cout << "Path: [";
	for (int i = 0; i < 12; ++i) {
		cout << fixed << setprecision(1) << chipPosition;
		cout << ", ";
		if (chipPosition == 0.0) {
			chipPosition = chipPosition + 0.5;
		}
		else if (chipPosition == 8.0) {
			chipPosition = chipPosition - 0.5;
		}
		else {
			random = rand() % 2;
			if (random == 0) {
				chipPosition = chipPosition - 0.5;
			}
			else {
				chipPosition = chipPosition + 0.5;
			}
		}
	}
	return ComputeWinnings(chipPosition);
}

void SingleChip() {
	int slot = 0;
	cout << "*** Drop a single chip ***" << endl << endl;
	cout << "Which slot do you want to drop the chip in (0-8)? ";
	cin >> slot;
	cout << endl;
	while (slot < 0 || slot > 8) {
		cout << "Invalid slot." << endl;
		cout << "Which slot do you want to drop the chip in (0-8)? ";
		cin >> slot;
	}
	double totalWinnings = DropChip(slot);
	cout << "Winnings: $" << fixed << setprecision(2) << totalWinnings << endl;
}

void MulitpleChip() {
	int numChips = 0;
	int slot = 0;
	cout << "*** Drop multiple chips ***" << endl << endl;
	cout << "How many chips do you want to drop (>0)? ";
	cin >> numChips;
	while (numChips < 0) {
		cout << "Invalid number of chips." << endl;
		cout << "How many chips do you want to drop (>0)? ";
		cin >> numChips;
	}
	cout << endl << endl;
	cout << "Which slot do you want to drop the chip in (0-8)? " << endl;
	cin >> slot;
	cout << endl;
	while (slot < 0 || slot > 8) {
		cout << "Invalid slot." << endl;
		cout << "Which slot do you want to drop the chip in (0-8)? ";
		cin >> slot;
	}
	double totalWinnings = DropChip(slot);
	double averageWinnings = static_cast<int>(((totalWinnings / numChips) + .005) * 100) / 100.00;
	cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
	cout << "Average winnings per chip: $" << averageWinnings << endl;

}

int main() {

	// Variables
	int userSelection = 0;
	int slot = 0;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);
	double chipPosition = 0.0;
	int random = 0;
	int numChips = 0;
	double totalWinnings = 0.0;
	double averageWinnings = 0.0;

	// Intro
	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now: " << endl;
	cin >> userSelection;

	// Sets up entire program loop
	while (userSelection != 4) {
		totalWinnings = 0.0;

		//Single Chip
		if (userSelection == 1) {
			SingleChip();
		}

		// Multiple Chips	
		else if (userSelection == 2) {
			MulitpleChip();
		}

		// Option Menu	
		else if (userSelection == 3) {
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl;
		}
		else if (userSelection <= 0 || userSelection >= 5) {
			cout << "Invalid selection. Enter 3 to see options." << endl;
		}
		cout << "Enter your selection now: " << endl;
		cin >> userSelection;
	}

	// End Game
	cout << "Goodbye!" << endl;

	return 0;
}