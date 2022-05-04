/*
File Name: CSC161_jjordan_FinalProject.cpp
Author: Josh Jordan
Date: 5-2-2022
Description: Battleship boardgame

NOTES: few minor errors going to try to circle around to them after presentation / time complexity analysis of time is avail
*/

#include "BattleBoard.h"

void menu()
{
    std::cout << "\n   Welcome To Battle Ship   " << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "1) Rules & Instructions" << std::endl;
    std::cout << "2) Play" << std::endl;
    std::cout << "3) Exit" << std::endl;
}

void rules()
{
    std::cout << "                                    Rules / Instructions                                    " << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "You will first be prompted to place your three ships. The orientation of the ships can be " << std::endl;
    std::cout << "placed in either vertical or horizontal orientation, however diagonal will not be accepted." << std::endl;
    std::cout << "Once all your ships have been placed & accepted the game will begin. You will then be " << std::endl;
    std::cout << "prompted to choose enter a number (either 1 or 2). This will replicate flipping a coin to " << std::endl;
    std::cout << "determine how will start off the game. IF you guess correctly you will go first. Once it " << std::endl;
    std::cout << "is your turn you will enter the 'index' on the board map you wish to send your hits. Direct " << std::endl;
    std::cout << "hits will replace the index with a 'X' and misses will replace the index wit ha 'o'. Once a " << std::endl;
    std::cout << "ship has been hit in all locations a message will be displayed alerting you that either your " << std::endl;
    std::cout << "or your enemies ship has been sunk. Once all ships have been sunk a message will be " << std::endl;
    std::cout << "displayed stating the victor of the match." << std::endl;
}

int main()
{
    // declarations
	BattleBoard b1, b2, p1_EnemyBoard, p2_EnemyBoard;
    int rows, cols, row, col, MenuDecision, coin = 0;
    std::string CoinToss;
    char delay;
    bool p1_ships = false, p2_ships = false;

    // choosing size of board 1 - 9
	std::cout << "How many rows and columns would you like the board to be? 1-9 (separated by spaces): ";
	std::cin >> rows >> cols;
    rows += 1;
    cols += 1;

	// constructing the two board objects
	b1 = BattleBoard(rows, cols);
	b2 = BattleBoard(rows, cols);
    p1_EnemyBoard = BattleBoard(rows, cols);
    p2_EnemyBoard = BattleBoard(rows, cols);

	// creating the two boards (p1/p2)
	b1.CreateBoard(rows, cols);
	b2.CreateBoard(rows, cols);
    p1_EnemyBoard.CreateBoard(rows, cols);
    p2_EnemyBoard.CreateBoard(rows, cols);

    menu();
    std::cin >> MenuDecision;

    while (MenuDecision == 1 || MenuDecision == 2)
    {
        if (MenuDecision == 1)
        {
            rules();
        }
        else if (MenuDecision == 2)
        {
            // player one places ships
            std::cout << "\nPlayer 1: Begin Setup." << std::endl;
            b1.setup();

            // player two places ships
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2: Begin Setup." << std::endl;
            b2.setup();

            // coin toss
            srand(time(0));
            coin = rand() % 2 + 1;

            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Player 1 flips a coin, Player 2: choose heads or tails.\n> ";
            std::cin >> CoinToss;
            if (CoinToss[0] == 'h' || CoinToss[0] == 'H')
            {
                if (coin == 1)
                {
                    while (!p1_ships && !p2_ships) // loops until either player 1 or player 2 has won
                    {
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 2 is up!" << std::endl;
                        
                        std::cout << std::endl;
                        p2_EnemyBoard.PrintBoard();

                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b2.SendHit(row, col);
                        b1.CheckHit(row, col, p2_EnemyBoard);

                        std::cout << "Player 1: Press any key to continue: ";
                        std::cin >> delay;

                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 1 is up!" << std::endl;

                        std::cout << std::endl;
                        p1_EnemyBoard.PrintBoard();
                        
                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b1.SendHit(row, col);
                        b2.CheckHit(row, col, p1_EnemyBoard);

                        std::cout << "Player 2: Press any key to continue: ";
                        std::cin >> delay;

                        p1_ships = b1.IsShips_Empty(); // checking if ship set is empty
                        p2_ships = b2.IsShips_Empty();
                    }
                }
                else
                {
                    while (!p1_ships && !p2_ships) // loops until either player 1 or player 2 has won
                    {
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 1 is up!" << std::endl;

                        std::cout << std::endl;
                        p1_EnemyBoard.PrintBoard();

                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b1.SendHit(row, col);
                        b2.CheckHit(row, col, p1_EnemyBoard);

                        std::cout << "Player 2: Press any key to continue: ";
                        std::cin >> delay;

                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 2 is up!" << std::endl;

                        std::cout << std::endl;
                        p2_EnemyBoard.PrintBoard();

                        std::cout << "Enter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b2.SendHit(row, col);
                        b1.CheckHit(row, col, p2_EnemyBoard);

                        std::cout << "Player 1: Press any key to continue: ";
                        std::cin >> delay;

                        p1_ships = b1.IsShips_Empty(); // checking if ship set is empty
                        p2_ships = b2.IsShips_Empty();
                    }
                }
            }
            else if (CoinToss[0] == 't' || CoinToss[0] == 'T')
            {
                if (coin == 2)
                {
                    while (!p1_ships && !p2_ships) // loops until either player 1 or player 2 has won
                    {
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 2 is up!" << std::endl;

                        std::cout << std::endl;
                        p2_EnemyBoard.PrintBoard();

                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b2.SendHit(row, col);
                        b1.CheckHit(row, col, p2_EnemyBoard);

                        std::cout << "Player 1: Press any key to continue: ";
                        std::cin >> delay;

                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 1 is up!" << std::endl;

                        std::cout << std::endl;
                        p1_EnemyBoard.PrintBoard();

                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b1.SendHit(row, col);
                        b2.CheckHit(row, col, p1_EnemyBoard);

                        std::cout << "Player 2: Press any key to continue: ";
                        std::cin >> delay;

                        p1_ships = b1.IsShips_Empty(); // checking if ship set is empty
                        p2_ships = b2.IsShips_Empty();
                    }
                }
                else
                {
                    while (!p1_ships && !p2_ships) // loops until either player 1 or player 2 has won
                    {
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 1 is up!" << std::endl;

                        std::cout << std::endl;
                        p1_EnemyBoard.PrintBoard();

                        std::cout << "\nEnter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b1.SendHit(row, col);
                        b2.CheckHit(row, col, p1_EnemyBoard);

                        std::cout << "Player 2: Press any key to continue: ";
                        std::cin >> delay;

                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        std::cout << "Player 2 is up!" << std::endl;

                        std::cout << std::endl;
                        p2_EnemyBoard.PrintBoard();

                        std::cout << "Enter the row and column you wish to fire your missile (separated by spaces).\n> ";
                        std::cin >> row >> col;
                        while (row < 1 || col < 1)
                        {
                            std::cout << "Incorrect location! Please enter a new location within the bounds of the board\n> ";
                            std::cin >> row >> col;
                        }
                        b2.SendHit(row, col);
                        b1.CheckHit(row, col, p2_EnemyBoard);

                        std::cout << "Player 1: Press any key to continue: ";
                        std::cin >> delay;

                        p1_ships = b1.IsShips_Empty(); // checking if ship set is empty
                        p2_ships = b2.IsShips_Empty();
                    }
                    std::cout << "YOU HAVE BESTED YOUR OPONENT AND ARE THE NEW NAVAL VICTOR!!!" << std::endl;
                }
            }
        }
        menu();
        std::cin >> MenuDecision;
    }
}