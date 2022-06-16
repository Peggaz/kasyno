#include "Roller.h"
#include <ctime> 
#include <xlocmon>

Roller::Roller(int id)
{
	m_id = id;
	generate_symbols();
}

bool Roller::symbol_in_vector(int id_symbol)
{
	if(m_symbols.size() >= SIZE_ROLLER)
	{
		return false;
	}
	for(auto element : m_symbols)
	{
		if(element == id_symbol) {
			return true;
		}
	}
	return false;
}

void Roller::generate_symbols()
{
	srand((unsigned)time(0));
	
	for(int i=0; i< SIZE_ROLLER; i++)
	{
		while (true)
		{
			int symbol_id = (rand() % SIZE_ROLLER) + 1;
			if (!symbol_in_vector(symbol_id) && symbol_id != Symbol::non) {
				m_symbols.push_back(Symbol(symbol_id));
				break;
			}
		}
		
	}
}

void Roller::shift(int shift)
{
	
	if(shift > SIZE_ROLLER)
	{
		shift = shift % SIZE_ROLLER;
	}

	std::vector<Symbol> change_vector;
	int index2 = 0;
	for(int i = 0; i< SIZE_ROLLER; i++)
	{
		if ((i + shift) < SIZE_ROLLER) {
			change_vector.push_back(m_symbols.at(i + shift));
		} else {
			change_vector.push_back(m_symbols.at(index2));
			index2++;
		}
	}
	m_symbols = change_vector;
}

std::vector<Symbol> Roller::get_window()
{
	int id = 0;
	std::vector<Symbol> ret;
	for(int index = 0; index<SIZE_WINDOW; index++) {
		ret.push_back(m_symbols.at(index));
	}
	return ret;
}

std::vector<Symbol> Roller::get_all_symbols() {
	return m_symbols;
}