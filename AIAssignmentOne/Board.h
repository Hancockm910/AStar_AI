#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

class Board
{
public:
	Board()
	{
	}
	~Board()
	{

	}

private:
	vector<vector<int>>Goal{ {1, 2, 3}, {8, 0, 4}, {7, 6, 5} };
	int EmptyX;
	int EmptyY;
public:
	vector<vector<int>>Squares;
	bool WinCondition(vector<vector<int>>Input);
	void PrintBoard(vector<vector<int>>Input);
	void GetEmpty(vector<vector<int>>Input);
	vector<vector<int>>MoveTile(vector<vector<int>>Input, int y, int x);
	vector<pair<int, int>>ValidMoves(vector<vector<int>>Input);

};

