#include <iostream>

int main()
{
	//Initialize the arrays to hold the player names
	char name1[17];
	char name2[17];

	//Have the players input their names
	std::cout << "P1, please enter your name in 16 characters or less" << std::endl;
	std::cin >> name1;
	system("cls");

	std::cout << "P2, please enter your name in 16 characters or less" << std::endl;
	std::cin >> name2;
	system("cls");


	//Have a list of number coordinates to record what goes where on the board
	int intBoard[9] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	//And have another one that shows the updates during play
	char showBoard[9] = {
		' ', ' ', ' ',
		' ', ' ', ' ',
		' ', ' ', ' '
	};
	bool won = false;
	bool p1Turn = true;

	//While someone hasn't won the game
	while (!won) {

		//Show the coordinates or numbers to input so the players can accurately place their marks
		std::cout << "Input Board" << std::endl;
		std::cout << " " << intBoard[0] << " " << intBoard[1] << " " << intBoard[2] << std::endl;
		std::cout << " " << intBoard[3] << " " << intBoard[4] << " " << intBoard[5] << std::endl;
		std::cout << " " << intBoard[6] << " " << intBoard[7] << " " << intBoard[8] << std::endl;

		std::cout << std::endl;

		//Show the marks that have been chosen so far
		std::cout << "Play Board" << std::endl;
		std::cout << " " << showBoard[0] << " " << showBoard[1] << " " << showBoard[2] << std::endl;
		std::cout << " " << showBoard[3] << " " << showBoard[4] << " " << showBoard[5] << std::endl;
		std::cout << " " << showBoard[6] << " " << showBoard[7] << " " << showBoard[8] << std::endl;

		std::cout << std::endl;

		//Declare whose turn it is
		if (p1Turn) {
			std::cout << name1 << "'s turn" << std::endl;
		}
		else {
			std::cout << name2 << "'s turn" << std::endl;
		}

		//Take input from the active player
		int input = -1;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail()); //metadelim
		//std::fflush(stdin);
		std::cin >> input;

		//If the input is invalid, have them resubmit
		if (input < 1 || input > 9) {
			std::cout << "Please enter a valid number." << std::endl;
			system("pause");
			system("cls");
			input = -1;
		}
		//if it's valid
		else {
			//check if the space they selected was already taken
			if (showBoard[input - 1] == 'X' || showBoard[input - 1] == 'O') {
				//If it was, have them choose another space
				std::cout << "That position is already taken, please choose another." << std::endl;
				system("pause");
				system("cls");
			}
			//If the space is unmarked
			else {
				//Mark the requested space with their insignia
				if (p1Turn) {
					showBoard[input - 1] = 'X';
				}
				else {
					showBoard[input - 1] = 'O';
				}

				//Check for a win condition
				if (
					(showBoard[0] == showBoard[1] && showBoard[1] == showBoard[2] && showBoard[0] != ' ') ||
					(showBoard[3] == showBoard[4] && showBoard[4] == showBoard[5] && showBoard[3] != ' ') ||
					(showBoard[6] == showBoard[7] && showBoard[7] == showBoard[8] && showBoard[6] != ' ') ||

					(showBoard[0] == showBoard[3] && showBoard[3] == showBoard[6] && showBoard[0] != ' ') ||
					(showBoard[1] == showBoard[4] && showBoard[4] == showBoard[7] && showBoard[1] != ' ') ||
					(showBoard[2] == showBoard[5] && showBoard[5] == showBoard[8] && showBoard[2] != ' ') ||

					(showBoard[0] == showBoard[4] && showBoard[4] == showBoard[8] && showBoard[0] != ' ') ||
					(showBoard[2] == showBoard[4] && showBoard[4] == showBoard[6] && showBoard[2] != ' ')
					) {

					//If one is detected, check whose turn it is
					if (p1Turn) {
						//And declare the victor
						std::cout << name1 << " WINS!" << std::endl;
						system("pause");
					}
					else {
						std::cout << name2 << " WINS!" << std::endl;
						system("pause");
					}

					won = true;

				}
				else {
					//Otherwise, change the turns
					if (p1Turn) {
						p1Turn = false;
					}
					else {
						p1Turn = true;
					}

				}

				//Check for the tie condition
				if (
					showBoard[0] != ' ' && showBoard[1] != ' ' && showBoard[2] != ' ' && showBoard[3] != ' ' &&
					showBoard[4] != ' ' && showBoard[5] != ' ' && showBoard[6] != ' ' && showBoard[7] != ' ' &&
					showBoard[8] != ' '
					) 
				{
					//If it matches, then declare the tie
					std::cout << "Cat's!" << std::endl;
					system("pause");
					won = true;
				}
				system("cls");
			}
		}
	}
}