#pragma once
#include "Roller.h"
#include <vector>
#include "Base.h"
#include "Report.h"

class Automat:private Base
{
private:
	std::vector<Roller> m_rollers;
	Symbol is_win_layout(std::vector<int> win_layout);
	Report* m_report = 0;
public:
	Automat();
	std::vector<Symbol> is_win();
	void set_win_layout(Symbol arg_symbol = Symbol::non);
	void set_lost_layout();
	void game();
	void set_report(Report* report);
};

