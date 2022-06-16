// kasyno gra.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// ReSharper disable All
#include <iostream>
#include <string>

#include "User.h"
#include "Roller.h"
#include "Automat.h"


int main(int argc, char* argv[])
{
	int games_count = 500;
	int start_credit = 250000;
	std::string out_file = "wynik.txt";
	int stawka = 100;
	try {
		games_count = std::stoi(argv[2]);
		start_credit = std::stoi(argv[4]);
		out_file = argv[6];
	} catch (...) {
		std::cout << "Niestety wystąpił błąd argumentów, symulacja zostanie wykonana dla domyślnych wartości";
	}
	User user = User(start_credit);
	for (int iter = 0; iter < games_count; iter++) {
		if ((user.GetSaldo() - stawka) < 0) {
			break;
		}
		user.Game(stawka);
		//std::cout << user.GetSaldo() << '\n';
	}
	std::cout << "liczba wygranych: " << user.get_report()->count_win << "\n";
	std::cout << "liczba przegranych: " << user.get_report()->count_lost << "\n";
	std::cout << "liczba podwonych wygranych: " << user.get_report()->count_double_win << "\n";
	std::cout << "najwyzszy wynik: " << user.get_report()->best_win << "\n";
	std::cout << "liczba rozegranych gier: " << user.get_report()->count_games << "\n";
	std::cout << "saldo koncowe" << user.GetSaldo();
	
}

