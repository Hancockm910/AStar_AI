#include "Board.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
using namespace std;

bool Board::WinCondition(vector<vector<int>>Input)
{
	return (Input == Goal);
}

void Board::PrintBoard(vector<vector<int>>Input)
{
	//cout << endl;
	//cout << " ";
	//for (int j = 0; j < Input.size(); j++)
	//{
	//	cout << j + 1 << " ";
	//}
	//cout << endl;
	//for (int j = 0; j < Input.size(); j++)
	//{
	//	cout << "---";
	//}
	//cout << endl;
	//for (int j = 0; j < Input.size(); j++)
	//{
	//	cout << "|" << Input[j];
	//}
	//cout << "|" << endl;
	//for (int j = 0; j < Input.size(); j++)
	//{
	//	cout << "---";
	//}
	cout << "   1    2    3" << endl << endl;

	for (int row = 0; row < 3; row++)
	{
		cout << row + 1;

		for (int col = 0; col < 3; col++)
		{
			cout << setw(3);
			if (Input[row][col] == 0)
				cout << ' ';
			else
				cout << Input[row][col];
			

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}

	cout << endl;

	cout << endl << endl;
}

void Board::GetEmpty(vector<vector<int>>Input)
{
	for (int y = 0; y < Input.size(); y++)
		for (int x = 0; x < Input[y].size(); x++)
			if (Input[y][x] == 0)
			{
				EmptyY = y;
				EmptyX = x;
				return;
			}
}

vector<vector<int>> Board::MoveTile(vector<vector<int>>Input, int y, int x)
{
	vector<vector<int>>RetVec = Input;
	GetEmpty(RetVec);
	swap(RetVec[EmptyY][EmptyX], RetVec[y][x]);
	return RetVec;
}

vector<pair<int, int>> Board::ValidMoves(vector<vector<int>>Input)
{
	GetEmpty(Input);
	vector<pair<int, int>>RetVec;
	if ( (EmptyX + 1) <= Input.size() - 1)
	{
		RetVec.push_back(make_pair(EmptyY, EmptyX + 1));
	}
	if ((EmptyX - 1) >= 0)
	{
		RetVec.push_back(make_pair(EmptyY, EmptyX - 1));
	}
	if ((EmptyY + 1) <= Input.size() - 1)
	{
		RetVec.push_back(make_pair(EmptyY + 1, EmptyX));
	}
	if ((EmptyY - 1) >= 0)
	{
		RetVec.push_back(make_pair(EmptyY - 1, EmptyX));
	}
	return RetVec;
}
