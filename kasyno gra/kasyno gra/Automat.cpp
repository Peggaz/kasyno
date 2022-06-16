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
			return symbol;
		}
	}
	return Symbol::non;
}

void Automat::game()
{
	for(int index = 0; index < m_rollers.size(); index++)
	{
		int shift = (rand() % SIZE_ROLLER) + 1;
		m_rollers.at(index).shift(shift);
	}

}

std::vector<Symbol>  Automat::is_win()
{
	std::vector<Symbol> ret;
	ret.push_back(is_win_layout({ 0,0,0,0,0 }));
	ret.push_back(is_win_layout({ 1,1,1,1,1 }));
	ret.push_back(is_win_layout({ 2,2,2,2,2 }));
	ret.push_back(is_win_layout({ 1,1,0,1,1 }));
	ret.push_back(is_win_layout({ 0,1,2,1,0 }));
	ret.push_back(is_win_layout({ 2,1,0,1,2 }));
	ret.push_back(is_win_layout({ 1,0,1,0,1 }));
	ret.push_back(is_win_layout({ 1,2,1,2,1 }));
	ret.push_back(is_win_layout({ 0,0,1,2,2 }));
	ret.push_back(is_win_layout({ 2,2,1,0,0 }));
	ret.push_back(is_win_layout({ 2,1,0,1,1 }));
	ret.push_back(is_win_layout({ 2,1,0,0,0 }));
	ret.push_back(is_win_layout({ 0,1,2,2,2 }));
	ret.push_back(is_win_layout({ 0,1,2,1,1 }));
	ret.push_back(is_win_layout({ 0,1,0,1,0 }));
	ret.push_back(is_win_layout({ 2,1,2,1,2 }));
	ret.push_back(is_win_layout({ 0,0,1,1,1 }));
	ret.push_back(is_win_layout({ 2,2,1,1,1 }));
	ret.push_back(is_win_layout({ 2,2,2,1,0 }));
	ret.push_back(is_win_layout({ 0,0,0,1,2 }));
	return ret;
}

