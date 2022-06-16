#include "Automat.h"
bool Automat::is_win_layout(std::vector<Walec> uklad, std::vector<int> win_layout)
{
	if (uklad.size() != win_layout.size())
		throw;
	Symbol symbol = uklad.at(0).get_window().at(0);
	for(int index = 0; index < win_layout.size(); index++)
	{
		if (uklad.at(index).get_window().at(win_layout.at(index)) != symbol)
		{
			return false;
		}
	}
	return true;
}

bool Automat::is_win(std::vector<Walec> uklad)
{
	std::vector<bool> ret;
	ret.push_back(is_win_layout(uklad, { 0,0,0,0,0 }));
}