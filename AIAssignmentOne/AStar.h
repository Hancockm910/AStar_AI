#pragma once
#include "Board.h"
class AStar
{
public:
	AStar();
	~AStar();

private:
	struct State
	{
		int Index = -1;
		int ParentIndex = -1;
		vector<vector<int>>SavedBoard;
		int MoveX = -1; // Move coordinate
		int MoveY = -1;

		int gn = 0; //Number of moves taken
		int hn = 0; //Sum of distance of the tiles from end location
		int f = 0; // f = gn + hn;
		bool operator < (const State& state) const
		{
			return f < state.f;
		}
	};

	vector<vector<int>>Goal{ {1, 2, 3}, {8, 0, 4}, {7, 6, 5} };

	bool CropToVisit(vector<vector<vector<int>>>Cropped, vector<vector<int>>Input);
	int HN(vector<vector<int>>Input); //Sum of distance of the tiles from end location

public:

	vector<pair<int, int>> AStarCalc(Board board);

};

