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
	void setup()
	{

	}
	void MakeMove()
	{

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