#pragma once
#include "Roller.h"
#include <vector>
#include "Base.h"
class Automat:private Base
{
private:
	std::vector<Roller> m_rollers;
	Symbol is_win_layout(std::vector<int> win_layout);
public:
	Automat();
	std::vector<Symbol> is_win();
	std::vector<Roller> get_win_layout();
	std::vector<Roller> get_lost_layout();
	void game();
};

