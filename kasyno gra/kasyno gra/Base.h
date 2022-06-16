#pragma once
#include <vector>
#include "SymbolEnum.cpp"
class Base
{
protected:
	const int MAX_LOST_GAME = 35;
	const int SIZE_ROLLER = 35;
	const int SIZE_WINDOW = 3;
	const int COUNT_ROLLER = 5;
	const std::vector<Symbol> DOUBLE_VALUE_SYMBOLS = { Symbol::seven };
	const std::vector<std::vector<int>> WIN_LAYOUTS = {
			{ 0,0,0,0,0 },
			{ 1,1,1,1,1 },
			{ 2,2,2,2,2 },
			{ 1,1,0,1,1 },
			{ 0,1,2,1,0 },
			{ 2,1,0,1,2 },
			{ 1,0,1,0,1 },
			{ 1,2,1,2,1 },
			{ 0,0,1,2,2 },
			{ 2,2,1,0,0 },
			{ 2,1,0,1,1 },
			{ 2,1,0,0,0 },
			{ 0,1,2,2,2 },
			{ 0,1,2,1,1 },
			{ 0,1,0,1,0 },
			{ 2,1,2,1,2 },
			{ 0,0,1,1,1 },
			{ 2,2,1,1,1 },
			{ 2,2,2,1,0 },
			{ 0,0,0,1,2 }
	};
};
