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

		PrintBoard();

		//placing frigate
		std::cout << "Which direction do you want your frigate to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your frigate (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << "To confirm this ship placement enter the coordinate (Ex. 01).\n> ";
		std::cin >> s;
		
		for (int i = 0; i < frigate_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'F';
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'F';
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'F';
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'F';
			}
		}
		PrintBoard();

		// placing destroyer
		std::cout << "Which direction do you want your destroyer to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your destroyer (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << "To confirm this ship placement enter the coordinate (Ex. 01).\n> ";
		std::cin >> s;

		for (int i = 0; i < destroyer_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'D';
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'D';
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'D';
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'D';
			}
		}
		PrintBoard();

		// placing battleship
		std::cout << "Which direction do you want your battleship to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your battleship (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << "To confirm this ship placement enter the coordinate (Ex. 01).\n> ";
		std::cin >> s;

		for (int i = 0; i < BattleShip_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'B';
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'B';
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'B';
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'B';
			}
		}
		PrintBoard();
	}

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