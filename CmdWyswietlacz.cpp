#pragma once
#include "CmdWyswietlacz.h"


void CmdWyswietlacz::pokazZwyciezce(Zolnierz* zolnierz)
{
	cout << "Zwyciezca bitwy: " << endl;
	cout << "nazwa: " << zolnierz->nazwa() << endl;
	cout << "nrZolnierza: " << zolnierz->nrZolnierza() << endl;
	cout << "Zdrowie: " << zolnierz->zdrowie() << endl;
	cout << "Max zdrowie: " << zolnierz->maxZdrowie() << endl;
	cout << "Obrazenia: " << zolnierz->obrazenia() << endl;
	cout << "Szybkosc: " << zolnierz->szybkosc() << endl;
	cout << "Glod: " << zolnierz->glod() << endl;
	cout << "Wspolrzedne: [" << zolnierz->wspolrzednaX() << ", " << zolnierz->wspolrzednaY() << "]" << endl;
	cout << "============================================" << endl;
}

void CmdWyswietlacz::wyswietlTeren(Plansza* plansza)
{
	int wymiary = plansza->wymiary();
	for (auto x = 0; x < wymiary; x++)
	{
		cout << "|";
		for (auto y = 0; y < wymiary; y++)
		{
			Pole* pole = plansza->pole(x, y);
			if (pole->trudnosc() == TrudnoscTerenu::latwy) cout << "L ";
			else if (pole->trudnosc() == TrudnoscTerenu::neutralny) cout << "N ";
			else if (pole->trudnosc() == TrudnoscTerenu::trudny) cout << "T ";
		}
		cout << "|" << endl;
	}
}

void CmdWyswietlacz::pokazPlansze(Plansza* plansza, Zolnierz* zolnierz1, Zolnierz* zolnierz2)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	int wymiary = plansza->wymiary();
	for (auto x = 0; x < wymiary; x++)
	{
		cout << "|";
		for (auto y = 0; y < wymiary; y++)
		{

			Pole* pole = plansza->pole(x, y);
			if (zolnierz1->wspolrzednaX() == x && zolnierz1->wspolrzednaY() == y)
				cout << "* ";
			else if (zolnierz2->wspolrzednaX() == x && zolnierz2->wspolrzednaY() == y)
				cout << "* ";
			/*else if (dynamic_cast<Buty*>(pole->przedmiot()) != nullptr)
				cout << "B ";
			else if (dynamic_cast<Kamizelka*>(pole->przedmiot()) != nullptr)
				cout << "K ";
			else if (dynamic_cast<Karabin*>(pole->przedmiot()) != nullptr)
				cout << "G ";
			else if (dynamic_cast<Apteczka*>(pole->przedmiot()) != nullptr)
				cout << "A ";
			else if (dynamic_cast<Pozywienie*>(pole->przedmiot()) != nullptr)
				cout << "P ";*/
			else
				cout << "  ";


		}
		cout << "|" << endl;
	}
}