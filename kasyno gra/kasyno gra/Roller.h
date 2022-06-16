#pragma once
#include <vector>
#include "Base.h"
class Roller :private Base
{
private:
	std::vector<Symbol> m_symbols;
	int m_id;
	void generate_symbols();
	bool symbol_in_vector(int id_symbol);
public:
	Roller(int _id);
	std::vector<Symbol>get_window();
	void shift(int shift);
	std::vector<Symbol>get_all_symbols();
	
};

