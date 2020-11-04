#include "AStar.h"
#include <queue>
#include <algorithm>

AStar::AStar()
{
}


AStar::~AStar()
{
}

bool AStar::CropToVisit(vector<vector<vector<int>>>Cropped, vector<vector<int>>Input)
{
	for (auto i : Cropped)
	{
		if (i == Input)
		{
			return false;
		}
	}
	return true;
}

int AStar::HN(vector<vector<int>>Input)
{
	int CurrentX; //Saves Current position to measure against Goal position
	int CurrentY;
	int GoalX; // Saves goal position to measure against Current position
	int GoalY;
	int Total = 0;
	int itr = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (Goal[y][x] == i)
				{
					GoalX = x;
					GoalY = y;
				}
				if (Input[y][x] == i)
				{
					CurrentX = x;
					CurrentY = y;
				}
			}
		}
		Total += (abs(CurrentX - GoalX) + abs(CurrentY - GoalY));
	}
	system("CLS");
	cout << "\nDistance from Goal: " << Total << endl;
	return Total;
}

vector<pair<int, int>> AStar::AStarCalc(Board board)
{
	State Current;
	vector<State>ToVisit;
	vector<State>Visited;
	vector<vector<vector<int>>>CropVisited;

	Current.SavedBoard = board.Squares;
	ToVisit.push_back(Current);

	while (!ToVisit.empty())
	{
		sort(ToVisit.begin(), ToVisit.end());


		Current = ToVisit[0];
		CropVisited.push_back(Current.SavedBoard);
		ToVisit.erase(ToVisit.begin());
		Current.Index = Visited.size();
		Visited.push_back(Current);

		if (board.WinCondition(Current.SavedBoard))
		{
			cout << "\n\nDONE\n\n";
			vector<pair<int, int>> Path;
			while (Current.ParentIndex != -1)
			{
				// Fill path with coords for moves that lead to completed board
				Path.push_back(make_pair(Current.MoveY, Current.MoveX));
				Current = Visited[Current.ParentIndex];
			}
			return Path;
		}
		vector<pair<int, int>>Moves = board.ValidMoves(Current.SavedBoard);
		for (auto i : Moves)
		{
			State Child;
			Child.ParentIndex = Current.Index;
			Child.gn = Current.gn + 1;

			Child.MoveY = i.first;
			Child.MoveX = i.second;
			Child.SavedBoard = Current.SavedBoard;
			Child.SavedBoard = board.MoveTile(Child.SavedBoard, Child.MoveY, Child.MoveX);
			Child.hn = HN(Child.SavedBoard);

			Child.f = Child.hn + Child.gn;
			if (CropToVisit(CropVisited, Child.SavedBoard))
			{
				ToVisit.push_back(Child);
			}
		}
	}

}


