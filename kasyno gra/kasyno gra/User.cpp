#include "User.h"
User::User(int saldo /*5000*/)
{
	m_saldo = saldo;
}
void User::SetSaldo(int saldo)
{
	m_saldo = saldo;
}
int User::GetSaldo()
{
	return m_saldo;
}

void User::Game(int stawka)
{
	m_saldo -= stawka;
	m_automat.game();
	std::vector<Symbol> respone_vector = m_automat.is_win();
	for (auto symbol : respone_vector) {
		if(symbol == Symbol::non) {
			continue;
		}
		if (std::find(DOUBLE_VALUE_SYMBOLS.begin(), DOUBLE_VALUE_SYMBOLS.end(), symbol) != DOUBLE_VALUE_SYMBOLS.end()) {
			stawka *= 4;
		} else {
			stawka += stawka;
		}
	}
	m_saldo += stawka;
}
