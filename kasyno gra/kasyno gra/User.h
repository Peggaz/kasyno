#pragma once
#include "Base.h"
#include "Automat.h"
class User :private Base
{
private:
	Automat m_automat = Automat();
	int m_saldo;
	int m_id;
public:
	User(int saldo = 5000);
	void SetSaldo(int saldo);
	int GetSaldo();
	void Game(int stawka = 100);
};



