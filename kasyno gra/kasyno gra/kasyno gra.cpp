﻿// kasyno gra.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// ReSharper disable All
#include <iostream>
#include "User.h"
#include "Walec.h"

void Game()
{
	
}



int main()
{
	User user = User();
    user.SetSaldo(5000);
	Walec walec = Walec();



    std::cout << user.GetSaldo() << "\n";
	for (auto element : walec.getAllSymbols())
	{
		std::cout << element << "\n";
	}

	std::cout << "\n======\n";
	walec.przesun(4);
	for (auto element : walec.getAllSymbols()) {
		std::cout << element << "\n";
	}
	
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
