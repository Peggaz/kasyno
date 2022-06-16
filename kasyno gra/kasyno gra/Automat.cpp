#include "Automat.h"

Automat::Automat()
{
	for (int index = 0; index < COUNT_ROLLER; index++)
		m_rollers.push_back(*new Roller(index));
}



Symbol Automat::is_win_layout(std::vector<int> win_layout)
{
	if (m_rollers.size() != win_layout.size())
		throw;
	Symbol symbol = m_rollers.at(0).get_window().at(0);
	for(int index = 0; index < win_layout.size(); index++)
	{
		if (m_rollers.at(index).get_window().at(win_layout.at(index)) != symbol)
		{
			return Symbol::non;
		}
	}
	return symbol;
}

void Automat::set_lost_layout()
{
	std::vector<Symbol> symbols = m_rollers.at(0).get_window();
	int wrong_roller = (rand() % COUNT_ROLLER) + 1;
	if (wrong_roller == 0)
		wrong_roller = 1;

	for (auto symbol : symbols)
	{
		while (true)
		{
			std::vector<Symbol> window = m_rollers.at(wrong_roller).get_window();
			if(std::find(window.begin(), window.end(), symbol) != window.end()){
				m_rollers.at(wrong_roller).shift((rand() % 10) + 1);
			} else {
				break;
			}
		}
	}
}

void Automat::game()
{
	for(int index = 0; index < m_rollers.size(); index++)
	{
		int shift = (rand() % SIZE_ROLLER) + 1;
		m_rollers.at(index).shift(shift);
	}

}

void Automat::set_report(Report* report)
{
	m_report = report;
}

std::vector<Symbol>  Automat::is_win()
{
	std::vector<Symbol> ret;
	for (auto layout : WIN_LAYOUTS)
	{
		ret.push_back(is_win_layout(layout));
	}
	return ret;
}

void Automat::set_win_layout(Symbol arg_symbol/*non*/)
{
	Symbol symbol = arg_symbol;
	if(symbol == Symbol::non)
		symbol = m_rollers.at(0).get_window().at((rand() % SIZE_WINDOW));

	for (int index = 0; index < COUNT_ROLLER; index++) {
		while (true) {
			std::vector<Symbol> window = m_rollers.at(index).get_window();
			if (std::find(window.begin(), window.end(), symbol) != window.end()) {
				break; 
			} else {
				m_rollers.at(index).shift(1);
			}
		}
	}

}



