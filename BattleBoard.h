#pragma once

#include <iostream>
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
	void setup() // STILL NEED TO ENTER INTO SETS
	{
		const int frigate_size = 2, destroyer_size = 3, BattleShip_size = 4;
		int col, row;
		
		// placing frigate
		for (int i = 0; i < frigate_size; i++)
		{
			PrintBoard();
			std::cout << "Choose a column to place position " << i + 1 << " for your frigate ship.\n> ";
			std::cin >> col;
			std::cout << "Now chose a row to place position " << i + 1 << " for your firgate ship.\n> ";
			std::cin >> row;

			while (i > 0)
			{
				if (row != row + 1 || row != row - 1)
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a column to place positiong " << i + 1 << " for your firgate ship.\n> ";
					std::cin >> col;
				}
				if (col != col + 1 || col != col - 1)
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a row to place positiong " << i + 1 << " for your frigate ship.\n> ";
					std::cin >> row;
				}
			}
			board[row][col] = 'F';
		}

		// placing destroyer
		for (int i = 0; i < destroyer_size; i++)
		{
			PrintBoard();
			std::cout << "Choose a column to place position " << i + 1 << " for your destroyer.\n> ";
			std::cin >> col;
			std::cout << "Now chose a row to place position " << i + 1 << " for your destroyer.\n> ";
			std::cin >> row;

			while (i > 0)
			{
				if (row != row + 1 || row != row - 1)
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a column to place positiong " << i + 1 << " for your destroyer.\n> ";
					std::cin >> col;
				}
				if (col != col + 1 || col != col - 1)
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a row to place positiong " << i + 1 << " for your destroyer.\n> ";
					std::cin >> row;
				}
			}
			board[row][col] = 'D';
		}

		// placing battleship
		for (int i = 0; i < BattleShip_size; i++)
		{
			PrintBoard();
			std::cout << "Choose a column to place position " << i + 1 << " for your battleship.\n> ";
			std::cin >> col;
			std::cout << "Now chose a row to place position " << i + 1 << " for your battleship.\n> ";
			std::cin >> row;

			while (i > 0)
			{
				if (row != row + 1 || row != row - 1) // requires 
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a column to place positiong " << i + 1 << " for your battleship.\n> ";
					std::cin >> col;
				}
				if (col != col + 1 || col != col - 1)
				{
					throw ("Incorrect placement!");
					std::cout << "Choose a row to place positiong " << i + 1 << " for your battleship.\n> ";
					std::cin >> row;
				}
			}
			board[row][col] = 'B';
		}
	}
	void MakeMove()
	{
		int row, col;


	}
	void PrintBoard()
	{
		for (int i = 0; i < m_Rows; i++)
		{
			for (int j = 0; j < m_Cols; j++)
			{
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
	}

private:
	int m_Rows;
	int m_Cols;
	char **board;
	std::set<std::string> battleship;
	std::set<std::string> destroyer;
	std::set<std::string> frigate;
};