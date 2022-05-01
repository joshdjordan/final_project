#pragma once

#include <iostream>
#include <string>
#include <set>

class BattleBoard
{
public:
	// constructors //
	BattleBoard()
	{
		m_Rows = 10;
		m_Cols = 10;
		board = new char*[m_Rows];

		for (int i = 0; i < m_Rows; i++)
		{
			board[i] = new char[m_Cols];
		}
	}
	BattleBoard(int rows, int cols)
	{
		m_Rows = rows;
		m_Cols = cols;
		board = new char* [rows];

		for (int i = 0; i < rows; i++)
		{
			board[i] = new char[cols];
		}
	}

	// member functions //
	void CreateBoard(int rows, int cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				board[i][j] = '-';
			}
		}
	}

	void player_setup()
	{
		const int frigate_size = 2, destroyer_size = 3, BattleShip_size = 4;
		int row, col;
		std::string s, orientation;

		//placing frigate
		for (int i = 0; i < frigate_size; i++)
		{
			PrintBoard();
			std::cout << "Which direction do you want your frigate ship to travel from the starting point? (left, right, up, down)\n> ";
			std::cin >> orientation;
			std::cout << "Choose a row and column to place your starting point for your frigate (separated by spaces).\n> ";
			std::cin >> row >> col;

			if (orientation == "left")
			{
				board[row][col - i] = 'F';
			}
			else if (orientation == "right")
			{
				board[row][col + i];
			}
		}
	}

	//void player_setup()
	//{
	//	const int frigate_size = 2, destroyer_size = 3, BattleShip_size = 4;
	//	int col, row;
	//	std::string s;
	//	
	//	// placing frigate
	//	for (int i = 0; i < frigate_size; i++)
	//	{
	//		bool found = true;
	//		PrintBoard();
	//		std::cout << "Choose a column to place position " << i + 1 << " for your frigate ship.\n> ";
	//		std::cin >> col;
	//		std::cout << "Now chose a row to place position " << i + 1 << " for your firgate ship.\n> ";
	//		std::cin >> row;

	//		while (i > 0)
	//		{
	//			if (row != row + 1 || row != row - 1)
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a column to place positiong " << i + 1 << " for your firgate ship.\n> ";
	//				std::cin >> col;
	//			}
	//			if (col != col + 1 || col != col - 1)
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a row to place positiong " << i + 1 << " for your frigate ship.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//		
	//		while (found)
	//		{
	//			std::cout << "Enter your final posotion (if you chose row 3 and column 9. Your example should be entered as 39)." << std::endl;
	//			std::cin >> s;

	//			if (ships.find(s) == ships.end())
	//			{
	//				board[row][col] = 'F';
	//				ships.insert(s);
	//				frigate.insert(s);
	//				found = false;
	//			}
	//			else
	//			{
	//				std::cout << "You have already placed something there!" << std::endl;
	//				std::cout << "Choose a column to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> col;
	//				std::cout << "Now chose a row to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//	}

	//	// placing destroyer
	//	for (int i = 0; i < destroyer_size; i++)
	//	{
	//		bool found = true;
	//		PrintBoard();
	//		std::cout << "Choose a column to place position " << i + 1 << " for your destroyer.\n> ";
	//		std::cin >> col;
	//		std::cout << "Now chose a row to place position " << i + 1 << " for your destroyer.\n> ";
	//		std::cin >> row;

	//		while (i > 0)
	//		{
	//			if (row != row + 1 || row != row - 1)
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a column to place positiong " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> col;
	//			}
	//			if (col != col + 1 || col != col - 1)
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a row to place positiong " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//		
	//		while (found)
	//		{
	//			std::cout << "Enter your final posotion (if you chose row 3 and column 9. Your example should be entered as 39)." << std::endl;
	//			std::cin >> s;

	//			if (ships.find(s) == ships.end())
	//			{
	//				board[row][col] = 'F';
	//				ships.insert(s);
	//				destroyer.insert(s);
	//				found = false;
	//			}
	//			else
	//			{
	//				std::cout << "You have already placed something there!" << std::endl;
	//				std::cout << "Choose a column to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> col;
	//				std::cout << "Now chose a row to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//	}

	//	// placing battleship
	//	for (int i = 0; i < BattleShip_size; i++)
	//	{
	//		bool found = true;
	//		PrintBoard();
	//		std::cout << "Choose a column to place position " << i + 1 << " for your battleship.\n> ";
	//		std::cin >> col;
	//		std::cout << "Now chose a row to place position " << i + 1 << " for your battleship.\n> ";
	//		std::cin >> row;

	//		while (i > 0)
	//		{
	//			if (row != row + 1 || row != row - 1) // requires 
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a column to place positiong " << i + 1 << " for your battleship.\n> ";
	//				std::cin >> col;
	//			}
	//			if (col != col + 1 || col != col - 1)
	//			{
	//				std::cout << "Incorrect placement!" << std::endl;
	//				std::cout << "Choose a row to place positiong " << i + 1 << " for your battleship.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//		
	//		while (found)
	//		{
	//			std::cout << "Enter your final posotion (if you chose row 3 and column 9. Your example should be entered as 39)." << std::endl;
	//			std::cin >> s;

	//			if (ships.find(s) == ships.end())
	//			{
	//				board[row][col] = 'F';
	//				ships.insert(s);
	//				battleship.insert(s);
	//				found = false;
	//			}
	//			else
	//			{
	//				std::cout << "You have already placed something there!" << std::endl;
	//				std::cout << "Choose a column to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> col;
	//				std::cout << "Now chose a row to place position " << i + 1 << " for your destroyer.\n> ";
	//				std::cin >> row;
	//			}
	//		}
	//	}
	//}

	void npc_setup()
	{

	}

	void player_MakeMove()
	{
		int row, col;
		std::string s;

		PrintBoard();

		std::cout << "Enter the row and column you wish to fire your first missile (separated by spaces).\> ";
		std::cin >> row >> col;

		std::cout << "Are you sure you want to fire at Row: " << row << " and Column: " << col << "?" << std::endl;
		std::cout << "To confirm enter the coordinate (i.e. 37).\n> ";
		std::cin >> s;

		if (ships.find(s) != ships.end())
		{
			std::cout << "YOUR MISSILE HAS STRUCK A SHIP!" << std::endl;
			ships.erase(s);
			if (frigate.find(s) != frigate.end())
			{
				frigate.erase(s);
				if (frigate.empty())
				{
					std::cout << "YOU HAVE SUNK THE ENEMIES FRIGATE!" << std::endl;
				}
			}
			else if (destroyer.find(s) != destroyer.end())
			{
				destroyer.erase(s);
				if (destroyer.empty())
				{
					std::cout << "YOU HAVE SUNK THE ENEMIES DESTROYER!" << std::endl;
				}
			}
			else if (battleship.find(s) != battleship.end())
			{
				battleship.erase(s);
				if (battleship.empty())
				{
					std::cout << "YOU HAVE SUNK TEH ENEMIES BATTLESHIP!" << std::endl;
				}
			}
			board[row][col] = 'X';
			PrintBoard();
		}
		else
		{
			std::cout << "Your missile has missed the enemies ship and has splashed into the water inflicting no damage." << std::endl;
			board[row][col] = 'O';
			PrintBoard();
		}
	}

	void npc_MakeMove()
	{

	}

	void PrintBoard()
	{
		for (int i = 0; i < m_Rows; i++)
		{
			for (int j = 0; j < m_Cols; j++)
			{
				std::cout << board[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	int m_Rows;
	int m_Cols;
	char **board;	
	std::set<std::string> frigate;
	std::set<std::string> destroyer;
	std::set<std::string> battleship;
	std::set<std::string> ships;
};