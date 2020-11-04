#include "SlidingTilePuzzle.h"
#include <fstream>
#include <sstream>
#include <vector>



SlidingTilePuzzle::SlidingTilePuzzle()
{
}

vector<vector<int>> SlidingTilePuzzle::CreateBoard()
{
	ifstream InputCities;
	InputCities.open("SlidingTileConfig.txt");

	vector<vector<vector<int>>>RetVec;
	vector<vector<int>>Board;
	int One, Two, Three;

	if (InputCities.is_open())
	{
		for (string Line; getline(InputCities, Line); )
		{
			stringstream SingleLine;
			SingleLine << Line;

			if (isdigit(Line[0]))
			{
				while (SingleLine >> One >> Two >> Three)
				{
					vector<int>Insertion{ One, Two, Three };
					Board.push_back(Insertion);
				}
			}
			if (Line[0] == '-')
			{
				RetVec.push_back(Board);
				Board.clear();
			}
		}
	}
	else
	{
		cout << "\nFile did not open!\n";
	}

	int Choice;
	cout << "Select board from 1-13\n";
	cin >> Choice;
	cout << endl;

	return RetVec[Choice];
}

SlidingTilePuzzle::~SlidingTilePuzzle()
{
}

void SlidingTilePuzzle::Play(vector<vector<int>>Input)
{
	Board b;
	b.Squares = Input;
	AStar a;
	vector<pair<int, int>>Moves = a.AStarCalc(b);

	reverse(begin(Moves), end(Moves));

	int TotalMoves = 0;
	for (auto i : Moves)
	{
		b.PrintBoard(Input);
		Input = b.MoveTile(Input, i.first, i.second);
		TotalMoves++;
	}
	b.PrintBoard(Input);

	cout << "\n=================================\n";
	cout << "TotalMoves: " << TotalMoves << endl;

}
