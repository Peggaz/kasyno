#include "Walec.h"
#include <ctime> 
#include <xlocmon>

Walec::Walec()
{
	GenerateSymbols();
}

bool Walec::SymbolInVector(int id_symbol)
{
	if(m_symbols.size() >= SIZE_GAME)
	{
		return false;
	}
	for (auto element : m_symbols)
	{
		if(element == id_symbol)
		{
			return true;
		}
	}
	return false;
}

void Walec::GenerateSymbols()
{
	srand((unsigned)time(0));
	
	for(int i=0; i< SIZE_GAME; i++)
	{
		while (true)
		{
			int symbol_id = (rand() % SIZE_GAME) + 1;
			if (!SymbolInVector(symbol_id)) {
				m_symbols.push_back(Symbol(symbol_id));
				break;
			}
		}
		
	}
}

void Walec::przesun(int przesuniecie)
{
	
	if(przesuniecie > SIZE_GAME)
	{
		przesuniecie = przesuniecie % SIZE_GAME;
	}

	std::vector<Symbol> change_vector;
	int index2 = 0;
	for(int i = 0; i<SIZE_GAME; i++)
	{
		if ((i + przesuniecie) < SIZE_GAME) {
			change_vector.push_back(m_symbols.at(i + przesuniecie));
		} else {
			change_vector.push_back(m_symbols.at(index2));
			index2++;
		}
	}
	m_symbols = change_vector;
}

std::vector<Symbol> Walec::get_window()
{
	int id = 0;
	std::vector<Symbol> ret;
	for(int index = 0; index<SIZE_WINDOW; index++) {
		ret.push_back(m_symbols.at(index));
	}
	return ret;
}

std::vector<Symbol> Walec::getAllSymbols() {
	return m_symbols;
}