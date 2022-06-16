#pragma once
#include "ZnakiEnum.cpp"
#include <vector>
#include "Base.h"
class Walec :private Base
{
private:
	std::vector<Symbol> m_symbols;
	void GenerateSymbols();
	bool SymbolInVector(int id_symbol);
public:
	Walec();
	std::vector<Symbol>get_window();
	void przesun(int przesuniecie);
	std::vector<Symbol>getAllSymbols();
	
};

