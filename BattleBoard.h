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
		m_Rows = 0;
		m_Cols = 0;
		board = new char*[m_Rows + 1];

		for (int i = 0; i < m_Rows + 1; i++)
		{
			board[i] = new char[m_Cols + 1];
		}
	}
	BattleBoard(int rows, int cols)
	{
		m_Rows = rows;
		m_Cols = cols;
		board = new char* [m_Rows + 1];

		for (int i = 0; i < m_Rows + 1; i++)
		{
			board[i] = new char[m_Cols + 1];
		}
	}

	// member functions //
	void CreateBoard(int rows, int cols)
	{
		int count = 49;

		for (int i = 0; i < rows + 1; i++)
		{
			for (int j = 0; j < cols + 1; j++)
			{
				board[i][j] = '-';
			}
		}
		board[0][0] = ' ';
		for (int i = 1; i < rows; i++)
		{
			board[i][0] = count++;
		}
		
		count = 49;
		for (int i = 1; i < cols; i++)
		{
			board[0][i] = count++;
		}
	}

	void setup()
	{
		const int frigate_size = 2, destroyer_size = 3, BattleShip_size = 4;
		int row, col;
		std::string s, orientation;

		PrintBoard();

		//placing frigate
		std::cout << "\nWhich direction do you want your frigate to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your frigate (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << std::endl;
		
		
		for (int i = 0; i < frigate_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'F';
				s = std::to_string(row) + std::to_string(col - i);
				ships.insert(s);
				frigate.insert(s);
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'F';
				s = std::to_string(row) + std::to_string(col + i);
				ships.insert(s);
				frigate.insert(s);
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'F';
				s = std::to_string(row - i) + std::to_string(col);
				ships.insert(s);
				frigate.insert(s);
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'F';
				s = std::to_string(row + i) + std::to_string(col);
				ships.insert(s);
				frigate.insert(s);
			}
		}
		PrintBoard();

		// placing destroyer
		std::cout << "\nWhich direction do you want your destroyer to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your destroyer (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << std::endl;

		for (int i = 0; i < destroyer_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'D';
				s = std::to_string(row) + std::to_string(col - i);
				ships.insert(s);
				destroyer.insert(s);
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'D';
				s = std::to_string(row) + std::to_string(col + i);
				ships.insert(s);
				destroyer.insert(s);
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'D';
				s = std::to_string(row - i) + std::to_string(col);
				ships.insert(s);
				destroyer.insert(s);
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'D';
				s = std::to_string(row + i) + std::to_string(col);
				ships.insert(s);
				destroyer.insert(s);
			}
		}
		PrintBoard();

		// placing battleship
		std::cout << "\nWhich direction do you want your battleship to be from the starting point? (left, right, up, down)\n> ";
		std::cin >> orientation;
		std::cout << "Choose a row and column to place your starting point for your battleship (separated by spaces).\n> ";
		std::cin >> row >> col;
		std::cout << std::endl;

		for (int i = 0; i < BattleShip_size; i++)
		{
			if (orientation == "left")
			{
				board[row][col - i] = 'B';
				s = std::to_string(row) + std::to_string(col - i);
				ships.insert(s);
				battleship.insert(s);
			}
			else if (orientation == "right")
			{
				board[row][col + i] = 'B';
				s = std::to_string(row) + std::to_string(col + i);
				ships.insert(s);
				battleship.insert(s);
			}
			else if (orientation == "up")
			{
				board[row - i][col] = 'B';
				s = std::to_string(row - i) + std::to_string(col);
				ships.insert(s);
				battleship.insert(s);
			}
			else if (orientation == "down")
			{
				board[row + i][col] = 'B';
				s = std::to_string(row + i) + std::to_string(col);
				ships.insert(s);
				battleship.insert(s);
			}
		}
		PrintBoard();
	}

	std::string SendHit(int row, int col)
	{
		std::string s;

		s = std::to_string(row) + std::to_string(col);

		return s;
	}

	void CheckHit(int row, int col, BattleBoard object)
	{
		std::string s;
		
		s = SendHit(row, col);

		if (ships.find(s) != ships.end())
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
					std::cout << "YOU HAVE SUNK THE ENEMIES BATTLESHIP!" << std::endl;
				}
			}
			object.board[row][col] = 'X';
			object.PrintBoard();
		}
		else
		{
			std::cout << "Your missile has missed the enemies ship and splashed into the water inflicting 0 damage." << std::endl;
			object.board[row][col] = 'O';
			object.PrintBoard();
		}
	}

	// function to test if sets are empty
	bool IsShips_Empty()
	{
		bool set = false;

		if (this->ships.empty())
		{
			set = true;
			return set;
		}
		return set;
	}
	bool IsFrigate_Empty(BattleBoard object)
	{
		bool set = true;

		if (object.frigate.empty())
		{
			return true;
		}
		return false;
	}
	bool IsDestroyer_Empty(BattleBoard object)
	{
		bool set = true;

		if (object.destroyer.empty())
		{
			return true;
		}
		return false;
	}
	bool IsBattleShip_Empty(BattleBoard object)
	{
		bool set = true;

		if (object.battleship.empty())
		{
			return true;
		}
		return false;
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