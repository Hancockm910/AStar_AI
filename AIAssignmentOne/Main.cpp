
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;

#include "AStar.h"
#include "Board.h"
#include "SlidingTilePuzzle.h"

int main(void)
{
	SlidingTilePuzzle SL;
	SL.Play(SL.CreateBoard());

	system("pause");
	return 910;
}