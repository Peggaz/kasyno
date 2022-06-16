#include "User.h"
User::User(int saldo /*5000*/)
{
	report = new Report();
	report->start_budget = saldo;
	m_automat.set_report(report);
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

void User::Game(int stawka/*100*/)
{
	m_saldo -= stawka + 1;
	int ret_stawka = 1;
	if(report->lost_in_row > MAX_LOST_GAME) {
		m_automat.set_win_layout();
	} else if(report->start_budget <= m_saldo + (stawka*2)){
		m_automat.set_lost_layout();
	} else {
		m_automat.game();
	}
	std::vector<Symbol> respone_vector = m_automat.is_win();
	for (auto symbol : respone_vector) {
		if(symbol == Symbol::non) {
			continue;
		}
		if (std::find(DOUBLE_VALUE_SYMBOLS.begin(), DOUBLE_VALUE_SYMBOLS.end(), symbol) != DOUBLE_VALUE_SYMBOLS.end()) {
			ret_stawka = stawka *  4;
			report->count_double_win++;
		} else {
			ret_stawka += stawka;
		}
	}
	if (ret_stawka == 1) {
		report->count_lost++;
		report->lost_in_row++;
		report->win_in_row = 0;
	} else if (ret_stawka > report->best_win) {
		report->best_win = ret_stawka;
		report->count_win++;
		report->win_in_row++;
		report->lost_in_row = 0;
	} else {
		report->lost_in_row = 0;
		report->count_win++;
		report->win_in_row++;
	}

	report->count_games++;
	
	m_saldo += ret_stawka;
}


Report* User::get_report()
{
	return report;
}
