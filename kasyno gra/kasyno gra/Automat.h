#pragma once
#include "Walec.h"
#include <vector>
#include "Base.h"
class Automat:private Base
{
private:
#pragma region wyliczniea
	
#pragma endregion
public:
	Automat();
	bool is_win(std::vector<Walec> uklad);
	bool is_win_layout(std::vector<Walec> uklad, std::vector<int> win_layout );

	std::vector<Walec> getWygranaUklad();
	std::vector<Walec> getPrzegranaUklad();
};

