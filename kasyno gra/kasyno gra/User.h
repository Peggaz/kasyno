#pragma once
#include "Base.h"
class User :private Base
{
private:
	int m_saldo;
	int m_id;
public:
	User();
	void SetSaldo(int saldo);
	int GetSaldo();
};



