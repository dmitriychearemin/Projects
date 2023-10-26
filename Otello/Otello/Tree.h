#pragma once
#include "Game.h"

class Tree_MINIMAX {
private:
	int Eval = 0;
	int Invented_Game_Field[8][8];
	int Count_Pos = 0;
	Tree_MINIMAX** Mass_Pos;

	friend class Game;
};