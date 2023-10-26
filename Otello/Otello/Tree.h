#pragma once
#include "Game.h"

class Tree_MINIMAX {
private:
	int Invented_Game_Field[8][8];
	int Count_Pos = 0;
	int** Mass_Pos;

	friend class Game;
};