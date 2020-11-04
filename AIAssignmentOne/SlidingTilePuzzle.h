#pragma once
#include <vector>
#include <iostream>
#include "Board.h"
#include "AStar.h"
using namespace std;

class SlidingTilePuzzle
{
public:
	SlidingTilePuzzle();
	vector<vector<int>>CreateBoard();
	~SlidingTilePuzzle();
	void Play(vector<vector<int>>Input);
};

