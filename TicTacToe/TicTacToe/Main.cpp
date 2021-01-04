#include <iostream>



int main()
{
	int intBoard[9] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	char showBoard[9] = {
		' ', ' ', ' ',
		' ', ' ', ' ',
		' ', ' ', ' '
	};
	bool won = false;
	bool p1Turn = true;

	while (!won) {
		std::cout << "Input Board" << std::endl;
		std::cout << " " << intBoard[0] << " " << intBoard[1] << " " << intBoard[2] << std::endl;
		std::cout << " " << intBoard[3] << " " << intBoard[4] << " " << intBoard[5] << std::endl;
		std::cout << " " << intBoard[6] << " " << intBoard[7] << " " << intBoard[8] << std::endl;

		std::cout << std::endl;

		std::cout << "Play Board" << std::endl;
		std::cout << " " << showBoard[0] << " " << showBoard[1] << " " << showBoard[2] << std::endl;
		std::cout << " " << showBoard[3] << " " << showBoard[4] << " " << showBoard[5] << std::endl;
		std::cout << " " << showBoard[6] << " " << showBoard[7] << " " << showBoard[8] << std::endl;

		std::cout << std::endl;

		if (p1Turn) {
			std::cout << "P1's turn" << std::endl;
		}
		else {
			std::cout << "P2's turn" << std::endl;
		}

		int input = -1;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail()); //metadelim
		//std::fflush(stdin);
		std::cin >> input;

		if (input < 1 || input > 9) {
			std::cout << "Please enter a valid number." << std::endl;
			system("pause");
			system("cls");
			input = -1;
		}
		else {
			if (showBoard[input - 1] == 'X' || showBoard[input - 1] == 'O') {
				std::cout << "That position is already taken, please choose another." << std::endl;
				system("pause");
				system("cls");
			}
			else {
				if (p1Turn) {
					showBoard[input - 1] = 'X';
				}
				else {
					showBoard[input - 1] = 'O';
				}

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

					if (p1Turn) {
						std::cout << "P1 WINS!" << std::endl;
						system("pause");
					}
					else {
						std::cout << "P2 WINS!" << std::endl;
						system("pause");
					}

					won = true;

				}
				else {
					if (p1Turn) {
						p1Turn = false;
					}
					else {
						p1Turn = true;
					}

				}


				system("cls");
			}
		}
	}
}