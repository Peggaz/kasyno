#pragma once
#include <string>

#include "Base.h"
#include "Automat.h"
#include "Report.h"

class User :private Base
{
private:
	Automat m_automat = Automat();
	int m_saldo;
	int m_id;
	Report* report;
public:
	User(int saldo = 5000);
	void SetSaldo(int saldo);
	int GetSaldo();
	void Game(int stawka = 100);
	void prepare_report(std::string url);
	Report* get_report();
};



